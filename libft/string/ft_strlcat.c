/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:14:22 by ychibani          #+#    #+#             */
/*   Updated: 2021/11/30 10:36:03 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strnlen(char *str, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size && str[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len_tot;

	i = 0;
	j = 0;
	len_tot = ft_strlen(src) + ft_strnlen(dst, dstsize);
	if (!dstsize)
		return (ft_strlen(src));
	if (ft_strlen(dst) > dstsize)
		return (ft_strlen(src) + dstsize);
	while (dst[i])
		i++;
	while (src[j] && i < dstsize - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (len_tot);
}
