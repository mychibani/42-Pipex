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

int	open_infile(char *infile_name)
{
	int infile;

	infile = open(infile_name, O_RDONLY);
	if (access(infile_name, R_OK))
	{
		ft_putstr_fd("pipex: ", STDERR_FILENO);
		ft_putstr_fd("no such file or directory: ", STDERR_FILENO);
		ft_putstr_fd(infile_name, STDERR_FILENO);
		ft_putstr_fd("\n", 2);
	}
	if (infile < 0)
		return (0);
	return (infile);
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
