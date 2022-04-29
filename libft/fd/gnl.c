/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 10:09:08 by ychibani          #+#    #+#             */
/*   Updated: 2022/03/24 12:43:42 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	_is_newline(char c)
{
	if (c == '\n')
		return (1);
	return (0);
}

char	*_get_line(char *str)
{
	int		i;
	char	*final_str;

	i = 0;
	if (!str)
		return (NULL);
	final_str = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!(final_str))
		return (0);
	while (str[i])
	{
		final_str[i] = str[i];
		i++;
		if (str[i - 1] == '\n')
			break ;
	}
	final_str[i] = 0;
	return (final_str);
}

int	_is_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (_is_newline(str[i]))
			return (1);
		i++;
	}
	return (0);
}

char	*_get_save(char *save)
{
	int		i;
	int		j;
	char	*new_save;

	i = 0;
	j = 0;
	if (!save)
		return (NULL);
	while (save[i] && !_is_newline(save[i]))
		i++;
	if (!save[i] || !save[i + 1])
		return (free(save), NULL);
	if (save[i])
		i++;
	new_save = (char *)malloc(sizeof(char) * (ft_strlen(save + i) + 1));
	if (!new_save)
		return (0);
	while (save[i])
	{
		new_save[j] = save[i];
		i++;
		j++;
	}
	new_save[j] = 0;
	return (free(save), new_save);
}

char	*__gnl(int fd)
{
	static char	*save;
	char		buffer[BUFFER_READ + 1];
	char		*line;
	int			ret;

	if (BUFFER_READ < 1 || fd < 0)
		return (0);
	ret = 1;
	while (ret && !_is_line(save))
	{
		ret = read(fd, buffer, BUFFER_READ);
		if (ret <= 0)
			break ;
		buffer[ret] = '\0';
		save = _strjoin(save, buffer);
	}
	line = _get_line(save);
	save = _get_save(save);
	return (line);
}
