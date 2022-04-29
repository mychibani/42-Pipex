/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 16:32:02 by root              #+#    #+#             */
/*   Updated: 2021/11/23 14:09:12 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*tab;
	int		len_tot;

	if (!count || !size)
		return (malloc(0));
	len_tot = count * size;
	if (len_tot / count != size)
		return (malloc(0));
	tab = (void *)malloc(len_tot);
	if (!tab)
		return (NULL);
	ft_bzero((unsigned char *)tab, len_tot);
	return (tab);
}
