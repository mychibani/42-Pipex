/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 16:32:02 by root              #+#    #+#             */
/*   Updated: 2021/11/29 09:42:40 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define LONG_MAX 0x7fffffffffffffff

static int	limit(unsigned long long *result, int *sign)
{
	if (*result >= LONG_MAX && *sign == 1)
		*result = -1;
	if (*result > LONG_MAX && *sign == -1)
		*result = 0;
	if (*result < LONG_MAX && *result > 2147483647)
		*result = *result - LONG_MAX - 1;
	return (*result * *sign);
}

int	ft_atoi(const char *str)
{
	int					i;
	unsigned long long	res;
	int					sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + str[i++] - '0';
	return (limit(&res, &sign));
}
