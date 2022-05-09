/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner_prog.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 16:08:04 by ychibani          #+#    #+#             */
/*   Updated: 2022/05/04 12:22:13 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    _clean_char_tab(char **tab)
{
	int i;

	i = 0;
	if (!tab || !tab[i])
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_content(t_list **lst)
{
	t_list *move;

	move = *lst;
	while (move)
	{
		if (move->content)
			_clean_char_tab(move->content);
		move = move->next;
	}
}

void useless_fct(void *elem)
{
	(void)elem;
}

void    clean(t_program_data *data)
{
	t_list *temp;
	
	temp = data->head;
	if (data->limiter)
		unlink("/tmp/heredoc.tmp");
	_clean_char_tab(data->path);
	free_content(&temp);
	ft_lstclear(&temp, useless_fct);
	free(data);
}