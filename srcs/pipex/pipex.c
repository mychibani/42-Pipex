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

void	_clean_exit(t_program_data *data)
{
	clean(data);
	exit(0);
}

int open_infile(char *infile_name, t_program_data *data)
{
	if (access(infile_name, R_OK))
	{
		ft_putstr_fd("pipex: ", STDERR_FILENO);
		ft_putstr_fd("no such file or directory: ", STDERR_FILENO);
		ft_putstr_fd(infile_name, STDERR_FILENO);
		ft_putstr_fd("\n", 2);
		_clean_exit(data);
	}
	return (open(infile_name, O_RDONLY));
}

int	open_outfile(char *outfile_name, int mode)
{
	int outfile;

	if (mode)
		outfile = open(outfile_name, O_RDWR | O_CREAT | O_TRUNC, 0644);
	else
		outfile = open(outfile_name, O_RDWR | O_CREAT | O_APPEND, 0644);
	if (access(outfile_name, R_OK))
		_error_prompt(outfile_name);
	return (outfile);
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
	// print_data(data);
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
			data->prev_read = data->pipe[0];
		}
		data->index++;
		data->elem = data->elem->next;
	}
	return (_SUCCESS_);
}

int	main(int ac, char **av, char **env)
{
	t_program_data	*data;

	data = (t_program_data *)malloc(sizeof(t_program_data));
	if (!data)
		return (perror("error "), 1);
	if (ac < 5)
		return (free(data), 0);
	if (!init_data(ac, av, env, data))
		return (STDERR_FILENO);
	if (!pipex(data))
	 	return (STDERR_FILENO);
	if (_close_file_descriptors(data->prev_read, data->outfile) == _ERROR_)
	 	return (_error_prompt("close "), STDERR_FILENO);
	_wait(data->pid, data);
	return (_clean_exit(data), _SUCCESS_);
}
