/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:21:38 by ychibani          #+#    #+#             */
/*   Updated: 2022/04/27 17:53:05 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int __is_child(pid_t process)
{
    if (process == 0)
        return (_TRUE_);
    else
        return (_FALSE_);
}

// char **_trim_strstr(char **str, int i, int size)
// {
// 	char	**final_tab;
// 	int		tab_index;

// 	final_tab =	(char **)malloc(sizeof(char *) * ((size - i) + 1));
// 	if (!final_tab)
// 		return (NULL);
// 	while (i < size && str[i])
// 	{
// 		final_tab[tab_index] = ft_strdup(str[i]);
// 		tab_index++;
// 		i++;
// 	}
// 	final_tab[tab_index] = 0;
// 	return (final_tab);
// }
// int	__is_same(char *str, char *is_same)
// {
// 	if (!ft_strcmp(str, is_same))
// 		return (1);
// 	return (0);
// }

// void	print_list(t_list *lst)
// {
// 	while (lst)	
// 	{
// 		printf("%s\t", (char *)lst->content);
// 		lst = lst->next;
// 	}
// }

// void	print_tab(char **tab)
// {
// 	int i;

// 	i = 0;
// 	if (!tab)
// 	{
// 		printf("ah bah y'a rien\n");
// 		return ;
// 	}
// 	while (tab[i])
// 	{
// 		printf("%s\n", tab[i]);
// 		i++;
// 	}
// }

// void print_data(t_program_data *data)
// {
// 	printf("fd of infile = %d\n", data->infile);
// 	printf("fd of outfile = %d\n", data->outfile);
// 	printf("limiter = %s\n", data->limiter);
// 	printf("path = \t");
// 	print_tab(data->path);
// //	printf("env = \t");
// 	//print_tab(data->env);
// 	printf("inst list = \t");
// 	print_list(data->elem);
// 	printf("\n");
// 	printf("nombre de commande %ld\n", data->ninst);
// 	printf("nombre de pipe %ld\n", data->npipe);
// }

// int
// _trn(int condition, int success, int failure)
// {
// 	if (condition)
// 		return (success);
// 	return (failure);
// }