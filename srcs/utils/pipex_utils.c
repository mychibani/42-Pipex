/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:21:38 by ychibani          #+#    #+#             */
/*   Updated: 2022/05/03 14:49:03by ychibani         ###   ########.fr       */
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

int	__is_same(char *str, char *is_same)
{
	if (!ft_strcmp(str, is_same))
		return (1);
	return (0);
}

int	_close_file_descriptors(int _first, int _second)
{
	if (close(_first) < 0 || close(_second) < 0)
	{
		return (_ERROR_);
	}
	return (_SUCCESS_);
}

int	_file_descriptors_duplicators(int _first, int _second)
{
	if ((dup2(_first, STDIN_FILENO < 0)) || (dup2(_second, STDOUT_FILENO) < 0))
		return (1);
	return (0);
}

void	print_list(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)	
	{
		while (lst->content[i])
		{
			printf("%s\t", (char *)lst->content[i]);
			i++;
		}
		lst = lst->next;
		i = 0;
	}
}

void	print_tab(char **tab)
{
	int i;

	i = 0;
	if (!tab)
	{
		printf("ah bah y'a rien\n");
		return ;
	}
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
}

void print_data(t_program_data *data)
{
	printf("fd of prev_read = %d\n", data->prev_read);
	printf("fd of read_pipe = %d\n", data->pipe[0]);
	printf("fd of write_pipe = %d\n", data->pipe[1]);
	printf("fd of outfile = %d\n", data->outfile);
	printf("limiter = %s\n", data->limiter);
	printf("path = \t");
	print_tab(data->path);
	printf("------------------------\n");
	printf("inst list = \t");
	print_list(data->elem);
	printf("\n");
	printf("nombre de commande %ld\n", data->ninst);
	printf("index == %ld\n", data->index);
}