/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_here_doc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:35:40 by ychibani          #+#    #+#             */
/*   Updated: 2022/05/10 14:36:10 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_until_open(void)
{
	int	i;
	int	temp;

	i = 5000;
	if (access("/tmp/heredoc.tmp", F_OK) == 0)
		unlink("/tmp/heredoc.tmp");
	while (i >= 0)
	{
		temp = open("/tmp/heredoc.tmp", O_CREAT | O_APPEND | O_RDWR, 0644);
		if (temp > 0)
			return (temp);
		i--;
	}
	return (_ERROR_);
}

int	here_doc(char *limiter)
{
	int		fd;
	char	*str;

	fd = check_until_open();
	ft_putstr_fd("pipex_here_doc>", 1);
	str = __gnl(0);
	while (str)
	{
		if (!ft_strncmp(str, limiter, ft_strlen(str) - 1))
		{
			close(fd);
			fd = open("/tmp/heredoc.tmp", O_RDONLY);
			return (free(str), fd);
		}
		ft_putstr_fd("pipex_here_doc>", 1);
		ft_putstr_fd(str, fd);
		free(str);
		str = __gnl(0);
	}
	return (fd);
}
