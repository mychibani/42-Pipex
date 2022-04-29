/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:20:02 by ychibani          #+#    #+#             */
/*   Updated: 2021/11/23 15:49:55 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*final_str;
	unsigned int	len_tot;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	len_tot = ft_strlen(s + start);
	if (len_tot < len)
		len = len_tot;
	final_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!(final_str))
		return (0);
	ft_strlcpy(final_str, s + start, len + 1);
	return (final_str);
}
