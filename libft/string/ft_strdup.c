/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:13:07 by ychibani          #+#    #+#             */
/*   Updated: 2021/11/22 18:01:24 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*final_str;

	i = 0;
	while (s1[i])
		i++;
	final_str = (char *)malloc(sizeof(char) * (i + 1));
	if (!(final_str))
		return (0);
	i = 0;
	while (s1[i])
	{
		final_str[i] = s1[i];
		i++;
	}
	final_str[i] = 0;
	return (final_str);
}
