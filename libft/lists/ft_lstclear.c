/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:02:34 by ychibani          #+#    #+#             */
/*   Updated: 2022/04/15 10:53:19 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdint.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*to_delete;
	int		i;

	i = 0;
	while (*lst)
	{
		to_delete = *lst;
		(*del)(to_delete->content);
		*lst = to_delete->next;
		free(to_delete);
		i++;
	}
	*lst = NULL;
}

int
trn32(int condition, int succes, int failure)
{
	if (condition)
		return (succes);
	else
		return (failure);
}

int is_egal_a_42(int a)
{
	return (trn32((a == 42), 78, -1312));
}