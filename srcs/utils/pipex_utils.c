/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:30:58 by ychibani          #+#    #+#             */
/*   Updated: 2022/05/10 15:31:00 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	__is_child(pid_t process)
{
	if (process == 0)
		return (_TRUE_);
	else
		return (_FALSE_);
}

int	__is_same(char *str, char *is_same)
{
	if (!ft_strcmp(str, is_same))
		return (1);
	return (0);
}

int	_close_file_descriptors(int _first, int _second)
{
	if (_first > 0)
		close(_first);
	if (_second > 0)
		close(_second);
	return (_SUCCESS_);
}

int	_file_descriptors_duplicators(int _first, int _second)
{
	if (_first > 0)
		dup2(_first, STDIN_FILENO);
	if (_second > 0)
		dup2(_second, STDOUT_FILENO);
	return (1);
}
