/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children_work.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:18:40 by ychibani          #+#    #+#             */
/*   Updated: 2022/05/03 21:39:52 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	_execute_command(t_program_data *data)
{
	execve(find_command_path(data), data->elem->content, data->env);
	ft_putstr_fd("pipex :", STDERR_FILENO);
	ft_putstr_fd(data->elem->content[0], STDERR_FILENO);
	ft_putstr_fd(": command not found\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	starter_child_worker(t_program_data *data)
{
	if (data->prev_read < 0)
		_error_prompt("file");
	_close_file_descriptors(data->pipe[0], data->outfile);
	_file_descriptors_duplicators(data->prev_read, data->pipe[1]);
	_close_file_descriptors(data->prev_read, data->pipe[1]);
	_execute_command(data);
	_error_prompt(data->elem->content[0]);
}

void	child_worker(t_program_data *data)
{
	close(data->outfile);
	close(data->pipe[0]);
	_file_descriptors_duplicators(data->prev_read, data->pipe[1]);
	_close_file_descriptors(data->pipe[1], data->prev_read);
	_execute_command(data);
}

void	finisher_child_worker(t_program_data *data)
{
	close(data->pipe[1]);
	_file_descriptors_duplicators(data->prev_read, data->outfile);
	_close_file_descriptors(data->prev_read, data->outfile);
	_execute_command(data);
}

void	exec_children_work(t_program_data *data)
{
	if (data->index == 0)
		starter_child_worker(data);
	else if (data->index < (data->ninst - 1))
		child_worker(data);
	else
		finisher_child_worker(data);
}
