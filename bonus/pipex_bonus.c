/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:45:32 by ychibani          #+#    #+#             */
/*   Updated: 2022/05/10 14:46:04 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	_error_prompt(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	_usage_error(t_program_data *data)
{
	ft_putstr_fd("Usage : ./pipex <infile> 'unlimited command' <outfile>\n", 2);
	ft_putstr_fd("Or ./pipex here_doc LIMITER cmd1 cmd2 outfile\n", 2);
	clean(data);
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
		return (perror("error "), STDERR_FILENO);
	if (ac < 5)
		return (_usage_error(data), STDERR_FILENO);
	if (!init_data(ac, av, env, data))
		return (STDERR_FILENO);
	if (!pipex(data))
		return (STDERR_FILENO);
	if (_close_file_descriptors(data->prev_read, data->outfile) == _ERROR_)
		return (_error_prompt("close "), STDERR_FILENO);
	_wait(data->pid, data);
	return (_clean_exit(data), _SUCCESS_);
}
