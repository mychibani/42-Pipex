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

// #include "pipex.h"

// static t_list    *init_inst_list(int ac, char **av, int i)
// {
// 	t_list *head;

// 	head = NULL;
//     while (i < ac - 1)
//     {
//         ft_lstadd_back(&head, ft_lstnew(av[i]));
//         i++;
//     }
// 	return (head);
// }

// static void	init_data_heredoc(t_program_data *data, int ac, char **av, char **env)
// {
// 	data->infile = 0;
// 	data->outfile = open(av[ac - 1], O_RDWR | O_APPEND | O_CREAT, 0644);
//     data->elem = init_inst_list(ac, av, 3);
// 	data->ninst = ft_lstsize(data->elem) - 1;
// 	data->npipe = data->ninst - 1;
// 	data->env = env;
// 	data->path = get_path(env);
// 	data->limiter = av[2];
// 	data->pid = (pid_t *)malloc(sizeof(pid_t) * data->ninst);
// 	data->fd = (int(*)[2])malloc((2 * sizeof(int)) * data->npipe);
// 	data->index = 0;
// }

// static void	init_usual_data(t_program_data *data, int ac, char **av, char **env)
// {
// 	data->infile = 0;
// 	data->outfile = open(av[ac - 1], O_RDWR | O_TRUNC | O_CREAT, 0644);
//     data->elem = init_inst_list(ac, av, 2);
// 	data->ninst = ft_lstsize(data->elem);
// 	data->npipe = data->ninst - 1;
// 	data->env = env;
// 	data->path = get_path(env);
// 	data->limiter = NULL;
// 	data->pid = (pid_t *)malloc(sizeof(pid_t) * data->ninst);
// 	data->fd = (int(*)[2])malloc((2 * sizeof(int)) * data->npipe);
// 	data->index = 0;
// }

// t_program_data	*init_data(int ac, char **av, char **env, t_program_data *data)
// {
// 	data = (t_program_data *)malloc(sizeof(t_program_data));
// 	if (!data)
// 		return (NULL);
// 	if (__is_same(av[1], "here_doc"))
// 		init_data_heredoc(data, ac, av, env);
// 	else
// 		init_usual_data(data, ac, av, env);
// 	return (data);
// }