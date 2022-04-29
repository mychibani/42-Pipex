/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 08:42:29 by ychibani          #+#    #+#             */
/*   Updated: 2022/04/29 10:17:08 by ychibani         ###   ########.fr       */
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

int open_outfile(int ac, char **av)
{
	int fd;

	fd = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	return (fd);
}


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

void	exec_children_work(int ac, char **av, int outfile, int index, int pipe[2], char **env, int prev_read)
{
	(void)ac;
	if (index == 0)
	{
		close(pipe[0]);
		dup2(prev_read, STDIN_FILENO);
		dup2(pipe[1], STDOUT_FILENO);
		// parcequ'on laisse que 3 fd ouverts
		close(prev_read);
		close(pipe[1]);
		close(outfile);
		starter_child(av[2], env);
	}
	else if (index < (ac - 4))
	{
		close(outfile);
		dup2(prev_read, STDIN_FILENO);
		dup2(pipe[1], STDOUT_FILENO);
		// parcequ'on laisse que 3 fd ouverts
		close(pipe[1]);
		close(prev_read);
		runner_child(av[2], env);
	}
	else
	{
		close(pipe[1]);
		dup2(prev_read, STDIN_FILENO);
		dup2(outfile, STDOUT_FILENO);
		// parcequ'on laisse que 3 fd ouverts
		close(prev_read);
		close(outfile);
		finisher_child(av[3], env);
	}
}

int	main(int ac, char **av, char **env)
{
	int     		*pid;
	int     		_pipe[2];
	int				i;
	int				outfile;
	int				prev_read;

	prev_read = open(av[1], O_RDONLY);
	pid = (int *)malloc(sizeof(int) * 3);
	if (ac < 5)
		return (ft_putstr_fd("Invalid number of arguments\n", 2), 0);
	outfile = open_outfile(ac, av);
	i = 0;
	while (i < ac - 3)
	{
		pipe(_pipe);
		pid[i] = fork();
		if (pid[i] < 0)
			return (perror("fork "), 2);
		if (!__is_child(pid[i]))
			exec_children_work(ac, av, outfile, i, _pipe, env, prev_read);
		if (__is_child(pid[i]))
		{
			close(prev_read);
			close(_pipe[1]);
			prev_read = _pipe[0];
		while (1)
			i++;
		}
		i++;
	}
	i = 0;
	while (i < 3)
		waitpid(pid[i++], 0, 0);
	write(2, "COUCOU\n", 7);
	while (1)
		i++;
	free(pid);
	close(prev_read);
	close(outfile);
	//Clean Everything;
	return (0);
}
