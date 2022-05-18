/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:53:24 by ychibani          #+#    #+#             */
/*   Updated: 2022/05/13 22:34:32 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_infile(char *infile_name, t_program_data *data)
{
	int	infile;

	infile = open(infile_name, O_RDONLY);
	if (access(infile_name, R_OK))
	{
		ft_putstr_fd("pipex: ", STDERR_FILENO);
		ft_putstr_fd("no such file or directory: ", STDERR_FILENO);
		ft_putstr_fd(infile_name, STDERR_FILENO);
		ft_putstr_fd("\n", 2);
		_close_file_descriptors(data->pipe[0], data->pipe[1]);
		clean(data);
		exit(EXIT_FAILURE);
	}
	else if (infile < 0)
	{
		_close_file_descriptors(data->pipe[0], data->pipe[1]);
		clean(data);
		_error_prompt(infile_name);
	}
	else
		return (infile);
	return (infile);
}

int	open_outfile(char *outfile_name, int mode, t_program_data *data)
{
	int	outfile;

	if (mode == USUAL)
		outfile = open(outfile_name, O_RDWR | O_CREAT | O_TRUNC, 0644);
	else
		outfile = open(outfile_name, O_RDWR | O_CREAT | O_APPEND, 0644);
	if (outfile < 0)
	{
		close(data->prev_read);
		_close_file_descriptors(data->pipe[0], data->pipe[1]);
		clean(data);
		_error_prompt(outfile_name);
	}
	return (outfile);
}
