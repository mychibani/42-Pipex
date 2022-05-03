/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:45:58 by ychibani          #+#    #+#             */
/*   Updated: 2022/04/19 14:44:25by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static t_list    *init_inst_list(int ac, char **av, int i)
{
	t_list *head;

	head = NULL;
    while (i < ac - 1)
    {
        ft_lstadd_back(&head, ft_lstnew(ft_split(av[i], ' ')));
        i++;
    }
	return (head);
}

static void	init_data_heredoc(t_program_data *data, int ac, char **av, char **env)
{
	data->outfile = open_file(av[1], av[ac - 1], 0, data);
	data->prev_read = open("/tmp/here_doc", O_CREAT | O_RDWR | O_APPEND, 0644);
    data->elem = init_inst_list(ac, av, 3);
	data->ninst = ft_lstsize(data->head) - 1;
	data->env = env;
	data->path = get_path(env);
	data->limiter = av[2];
	data->index = 0;
	data->head = data->elem;
	data->pid = (int *)malloc(sizeof(int) * (data->ninst));
	if (!data->pid)
		_error_prompt("error :");
}

static void	init_usual_data(t_program_data *data, int ac, char **av, char **env)
{
	data->outfile = open_file(av[1], av[ac - 1], 0, data);
	data->prev_read = open_file(av[1], av[ac - 1], 1, data);
    data->elem = init_inst_list(ac, av, 2);
	data->ninst = ft_lstsize(data->elem);
	data->env = env;
	data->path = get_path(env);
	data->limiter = NULL;
	data->index = 0;
	data->head = data->elem;
	data->pid = (int *)malloc(sizeof(int) * (data->ninst));
	if (!data->pid)
		_error_prompt("error :");
}

void	init(t_program_data *data)
{
	data->prev_read = 0;
	data->outfile = 0;
	data->elem = NULL;
	data->ninst = 0;
	data->env = NULL;
	data->path = NULL;
	data->limiter = NULL;
	data->index = 0;
	data->head = NULL;
}

t_program_data	*init_data(int ac, char **av, char **env, t_program_data *data)
{
	init(data);
	if (__is_same(av[1], "here_doc"))
		init_data_heredoc(data, ac, av, env);
	else
		init_usual_data(data, ac, av, env);
	return (data);
}