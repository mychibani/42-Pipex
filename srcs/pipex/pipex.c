/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 08:42:29 by ychibani          #+#    #+#             */
/*   Updated: 2022/05/03 10:59:30y ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	_error_prompt(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}


int	open_file(char *infile_name, char *outfile_name, int mode, t_program_data *data)
{
	int infile;

	if (mode)
	{
		infile = open(infile_name, O_RDONLY);
		if (access(infile_name, R_OK))
		{
			ft_putstr_fd("pipex: ", STDERR_FILENO);
			ft_putstr_fd("no such file or directory: ", STDERR_FILENO);
			ft_putstr_fd(infile_name, STDERR_FILENO);
			ft_putstr_fd("\n", 2);
			free(data);
			exit(0);
		}
		else
			return (infile);
	}
	return (open(outfile_name, O_RDWR | O_TRUNC | O_CREAT, 0644));
}

void	_wait(int *pid, t_program_data *data)
{
	int	i;

	i = 0;
	while (i < (int)data->ninst)
		waitpid(pid[i++], 0, 0);	
	close(data->prev_read);
	free(pid);
}

int	pipex(t_program_data *data)
{	
	while (data->index < data->ninst)
	{
		if (pipe(data->pipe) < 0)
			_error_prompt("pipe :");
		data->pid[data->index] = fork();
		if (data->pid[data->index] < 0)
			return (perror("fork "), _FAILURE_);
		if (__is_child(data->pid[data->index]))
			exec_children_work(data);
		if (!__is_child(data->pid[data->index]))
		{
			_close_file_descriptors(data->prev_read, data->pipe[1]);
			data->elem = data->elem->next;
			data->prev_read = data->pipe[0];
		}
		data->index++;
	}
	return (_SUCCESS_);
}

int	main(int ac, char **av, char **env)
{
	t_program_data	*data;

	data = (t_program_data *)malloc(sizeof(t_program_data));
	if (!data)
		return (perror("error : "), 1);
	if (ac < 5)
		return (free(data), 0);
	if (!init_data(ac, av, env, data))
		return (STDERR_FILENO);
	if (!pipex(data))
	 	return (STDERR_FILENO);
	if (_close_file_descriptors(data->prev_read, data->outfile) == _ERROR_)
	 	return (_error_prompt("close "), STDERR_FILENO);
	_wait(data->pid, data);
	clean(data);
	exit (0);
	return (clean(data), _SUCCESS_);
}
