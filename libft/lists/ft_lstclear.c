/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:02:34 by ychibani          #+#    #+#             */
/*   Updated: 2022/05/03 14:33:09 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdint.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*to_delete;

	if (!*lst)
		return ;
	while (*lst)
	{
		to_delete = *lst;
		(*del)(to_delete->content);
		*lst = to_delete->next;
		free(to_delete);
	}
	*lst = NULL;
}
