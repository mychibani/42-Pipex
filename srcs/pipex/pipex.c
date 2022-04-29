/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 08:42:29 by ychibani          #+#    #+#             */
/*   Updated: 2022/04/29 19:12:59 by ychibani         ###   ########.fr       */
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


void	close_write_and_read(int pipe[2])
{
	if (close(pipe[0]) == _ERROR_)
		perror("cant close read pipe");
	if (close(pipe[1]) == _ERROR_)
		perror("cant close write pipe");
}

void	starter_child(char *command, char **env)
{
	char **final_command;

	final_command = ft_split(command, ' ');
	execve(final_command[0], final_command, env);
	perror("uyfuyfuyf");
	exit(1);
}

void	runner_child(char *command, char **env)
{
// 	char buff[100];
	char **final_command;

	final_command = ft_split(command, ' ');
	// parcequ'on laisse que 3 fd ouverts
	execve(final_command[0], final_command, env);
	perror(final_command[0]);
	exit(127);
}

void	finisher_child(char *command, char **env)
{
	char **final_command;

	final_command = ft_split(command, ' ');
	// parcequ'on laisse que 3 fd ouverts
	execve(final_command[0], final_command, env);
	perror(final_command[0]);
	exit(127);
}

void	_wait(int *pid, t_program_data *data)
{
	int	i;

	i = 0;
	while (i < data->ninst)
		waitpid(pid[i++], 0, 0);	
	free(pid);
}

int	_close_file_descriptors(int _first, int _second)
{
	if ((close(_first) < 0) || close(_second) < 0))
		return (_ERROR_);
	return (_SUCCESS_);
}

int	_file_descriptors_duplicators(int _first, int _second)
{
	if ((dup2(_first, STDIN_FILENO < 0)) || (dup2(_second, STDOUT_FILENO) < 0))
		return (1);
	return (0);
}
int	main(int ac, char **av, char **env)
{
	t_program_data	*data;
	int     		*pid;

	if (ac < 5)
		return (ft_putstr_fd("Invalid number of arguments\n", 2), 0);
	if (!init_data(ac, av, env, data))
		return (2);
	pid = (int *)malloc(sizeof(int) * data->ninst);
	if (!pid)
		return (clean(data), 2);
	while (data->index < ac - 3)
	{
		if (pipe(data->pipe) < 0)
		{	
			_error_prompt("pipe :");
			exit(0);
		}
		pid[data->index] = fork();
		if (pid[data->index] < 0)
			return (perror("fork "), 2);
		if (!__is_child(pid[data->index]))
			children_work(ac, av, data);
		if (__is_child(pid[data->index]))
		{
			close(data->prev_read);
			close(data->pipe[1]);
			data->prev_read = data->pipe[0];
		}
		data->index++;
		data->elem = data->elem->next;
	}
	_wait(pid, data);
	if (_close_file_descriptors(data->prev_read, data->outfile) == _ERROR_)
		return (_error_prompt("close :"), 2);
	return (clean(data), _SUCCESS_);
}
