/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:15:48 by ychibani          #+#    #+#             */
/*   Updated: 2021/11/23 15:57:39 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*final_str;

	i = 0;
	if (!s)
		return (0);
	final_str = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!(final_str))
		return (0);
	while (s[i])
	{
		final_str[i] = (*f)(i, s[i]);
		i++;
	}
	final_str[i] = '\0';
	return (final_str);
}
