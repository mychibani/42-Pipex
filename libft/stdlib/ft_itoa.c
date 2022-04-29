/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:34:00 by ychibani          #+#    #+#             */
/*   Updated: 2021/11/23 15:57:10 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int nb)
{
	int	i;

	i = 0;
	if (nb < 0)
		i++;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*final_str;
	int		size;
	long	nb;

	size = ft_intlen(n);
	nb = (long)n;
	final_str = (char *)malloc(sizeof(char) * size + 1);
	if (!(final_str))
		return (0);
	if (nb == 0)
		final_str[0] = '0';
	if (nb < 0)
	{
		final_str[0] = '-';
		nb *= -1;
	}
	final_str[size--] = 0;
	while (nb)
	{
		final_str[size] = (nb % 10) + '0';
		nb /= 10;
		size--;
	}
	return (final_str);
}
