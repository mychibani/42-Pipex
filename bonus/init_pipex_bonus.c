/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:30:12 by ychibani          #+#    #+#             */
/*   Updated: 2022/05/13 22:31:45 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_list	*init_inst_list(int ac, char **av, int i)
{
	t_list	*head;

	head = NULL;
	while (i < ac - 1)
	{
		ft_lstadd_back(&head, ft_lstnew(ft_split(av[i], ' ')));
		i++;
	}
	return (head);
}

void	init_data_heredoc(t_program_data *data, int ac, char **av, char **env)
{
	data->mode = HERE_DOC;
	data->outfile_name = av[ac - 1];
	data->prev_read = here_doc(av[2]);
	data->elem = init_inst_list(ac, av, 3);
	data->ninst = ft_lstsize(data->elem);
	data->env = env;
	data->path = get_path(env);
	data->limiter = av[2];
	data->index = 0;
	data->head = data->elem;
	data->pid = (int *)malloc(sizeof(int) * (data->ninst));
	if (!data->pid)
		_error_prompt("error");
}

void	init_usual_data(t_program_data *data, int ac, char **av, char **env)
{
	data->mode = USUAL;
	data->infile_name = av[1];
	data->outfile_name = av[ac - 1];
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
	data->mode = 0;
	data->infile_name = NULL;
	data->prev_read = 0;
	data->outfile = 0;
	data->elem = NULL;
	data->ninst = 0;
	data->env = NULL;
	data->path = NULL;
	data->limiter = NULL;
	data->index = 0;
	data->head = NULL;
	data = NULL;
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
