/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:13:33 by ychibani          #+#    #+#             */
/*   Updated: 2022/03/24 12:44:02 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*final_line;

	i = 0;
	j = 0;
	if (!s1)
		s1 = ft_strdup("");
	if (!s2)
		return (NULL);
	final_line = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!final_line)
		return (0);
	while (s1[i])
	{
		final_line[i] = s1[i];
		i++;
	}
	while (s2[j])
		final_line[i++] = s2[j++];
	final_line[i] = 0;
	return (free(s1), final_line);
}
