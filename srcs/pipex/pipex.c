/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 08:42:29 by ychibani          #+#    #+#             */
/*   Updated: 2022/05/03 10:59:30y ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	_error_prompt(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	ft_free(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

// void	exec(t_program_data *data)
// {
// 	char		**cmd;
// 	int			i = 0;

// 	cmd = ft_split(data->elem->content, ' ');
// 	if (cmd)
// 	{
// 		while (cmd[i])
// 		{
// 			printf("command = %s\n", cmd[i]);
// 			i++;
// 		}
// 	}
// 	execve(find_command_path(data, cmd[0]), cmd, data->env);
// 	perror(cmd[0]);
// }




void	_wait(int *pid, t_program_data *data)
{
	int	i;

	i = 0;
	while (i < (int)data->ninst)
		waitpid(pid[i++], 0, 0);	
	free(pid);
}

int	pipex(t_program_data *data)
{	
	while (data->index < data->ninst)
	{
		if (pipe(data->pipe) < 0)
		{	
			_error_prompt("pipe :");
			exit(0);
		}
		data->pid[data->index] = fork();
		if (data->pid[data->index] < 0)
			return (perror("fork "), _FAILURE_);
		if (__is_child(data->pid[data->index]))
			exec_children_work(data);
		if (!__is_child(data->pid[data->index]))
		{
			_close_file_descriptors(data->prev_read, data->pipe[1]);
			data->elem = data->elem->next;
			data->prev_read = data->pipe[0];
		}
		data->index++;
	}
	return (_SUCCESS_);
}

int	main(int ac, char **av, char **env)
{
	t_program_data	*data;

	data = (t_program_data *)malloc(sizeof(t_program_data));
	if (!data)
		return (perror("error : "), 1);
	if (ac < 5)
		return (ft_putstr_fd("Invalid number of arguments\n", 2), 0);
	if (!init_data(ac, av, env, data))
		return (STDERR_FILENO);
	print_data(data);
	return (clean(data), _SUCCESS_);
	// if (!pipex(data))
	// 	return (STDERR_FILENO);
	// _wait(data->pid, data);
	// if (_close_file_descriptors(data->prev_read, data->outfile) == _ERROR_)
	// 	return (_error_prompt("close :"), STDERR_FILENO);
	// return (_SUCCESS_);
}
