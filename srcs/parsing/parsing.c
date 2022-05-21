/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:21:48 by ychibani          #+#    #+#             */
/*   Updated: 2022/04/19 14:55:52 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path(char **envp)
{
	int	i;

	i = 0;
	if (!envp)
		return (NULL);
	while (envp[i])
	{
		if (!ft_strncmp("PATH=", envp[i], 5))
			return (ft_split(&envp[i][5], ':'));
		i++;
	}
	return (NULL);
}

char	*pipex_join(char *path, char *instructions)
{
	int		i;
	int		j;
	int		size;
	char	*command_path;

	i = 0;
	j = 0;
	size = ft_strlen(path) + ft_strlen(instructions) + 2;
	command_path = (char *)malloc(sizeof(char) * (size));
	if (!command_path)
		return (NULL);
	while (path[i])
	{
		command_path[i] = path[i];
		i++;
	}
	command_path[i++] = '/';
	if (!instructions)
		return (free(command_path), NULL);
	while (instructions[j])
		command_path[i++] = instructions[j++];
	command_path[i] = '\0';
	return (command_path);
}

char	*find_command_path(t_program_data *data)
{
	char	**bin;
	char	*inst;
	int		i;

	i = 0;
	bin = data->elem->content;
	if (!bin[0])
		return (NULL);
	if (access(bin[0], F_OK) == 0)
		return (bin[0]);
	inst = pipex_join(".", bin[0]);
	if (access(inst, F_OK) == 0)
		return (inst);
	free(inst);
	if (!data->path)
		return (NULL);
	while (data->path[i])
	{
		inst = pipex_join(data->path[i++], bin[0]);
		if (access(inst, F_OK) == 0)
			return (inst);
		free(inst);
	}
	return (NULL);
}
