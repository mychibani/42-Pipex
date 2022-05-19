/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children_work.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:18:40 by ychibani          #+#    #+#             */
/*   Updated: 2022/05/19 23:49:38 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	_execute_command(t_program_data *data)
{
	char	*new_command;

	new_command = find_command_path(data);
	if (!new_command)
	{
		ft_putstr_fd("command not found: ", STDERR_FILENO);
		ft_putstr_fd(data->elem->content[0], STDERR_FILENO);
		ft_putstr_fd("\n", 2);
		if (data->index == data->ninst - 1)
		{
			free(new_command);
			clean(data);
			exit(127);
		}
		free(new_command);
		clean(data);
		exit(EXIT_FAILURE);
	}
	execve(new_command, data->elem->content, data->env);
	free(new_command);
	perror(data->elem->content[0]);
	clean(data);
	exit(EXIT_FAILURE);
}

void	starter_child_worker(t_program_data *data)
{
	close(data->pipe[0]);
	if (data->mode == USUAL)
		data->prev_read = open_infile(data->infile_name, data);
	_file_descriptors_duplicators(data->prev_read, data->pipe[1]);
	_close_file_descriptors(data->prev_read, data->pipe[1]);
	_execute_command(data);
}

void	child_worker(t_program_data *data)
{
	close(data->pipe[0]);
	_file_descriptors_duplicators(data->prev_read, data->pipe[1]);
	_close_file_descriptors(data->pipe[1], data->prev_read);
	_execute_command(data);
}

void	finisher_child_worker(t_program_data *data)
{
	_close_file_descriptors(data->pipe[1], data->pipe[0]);
	data->outfile = open_outfile(data->outfile_name, data->mode, data);
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
