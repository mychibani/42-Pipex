/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:53:24 by ychibani          #+#    #+#             */
/*   Updated: 2022/05/10 14:53:26 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_infile(char *infile_name, t_program_data *data)
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
	int	outfile;

	if (mode)
		outfile = open(outfile_name, O_RDWR | O_CREAT | O_TRUNC, 0644);
	else
		outfile = open(outfile_name, O_RDWR | O_CREAT | O_APPEND, 0644);
	if (access(outfile_name, R_OK))
		_error_prompt(outfile_name);
	return (outfile);
}
