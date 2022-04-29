/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children_work.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:18:40 by ychibani          #+#    #+#             */
/*   Updated: 2022/04/29 19:11:04 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    starter_child_worker(t_program_data *data)
{
    _close_file_descriptors(data->pipe[0], data->outfile);
	_file_descriptors_duplicators(data->prev_read, data->pipe[1]);
    _close_file_descriptors(data->prev_read, data->path[1])
    _execute_command(data->elem->content, data->env);
    _error_prompt(data->elem->content);
}

void    child_worker(t_program_data *data)
{
	close(data->outfile);
    _file_descriptors_duplicators(data->prev_read, data->pipe[1]);
    _close_file_descriptors(data->pipe[1], data->prev_read);
	_execute_command(data->elem->content, data->env);
}

void    finisher_child_worker(t_program_data *data)
{
	close(data->pipe[1]);
	_file_descriptors_duplicators(data->prev_read, data->outfile);
    _close_file_descriptors(data->prev_read, data->outfile);
	_execute_command(data->elem->content, data->env);
}

void	exec_children_work(t_program_data *data)
{
	if (data->index == 0)
        starter_child_worker(data);
	else if (data->index < (data->ninst - 1))
        child_worker(data);
	else
        final_child_worker(data);
}