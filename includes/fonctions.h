/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 08:28:22 by ychibani          #+#    #+#             */
/*   Updated: 2022/04/29 12:38:04 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FONCTION_H
# define _FONCTION_H
# include "libft.h"

typedef struct s_program_data	t_program_data;
typedef struct s_inst			t_inst;


struct s_program_data
{
	int		pipe[2];
	int		prev_read;
	int		outfile;
	char	**path;
	char    **env;
	char 	*limiter;
	t_list	*elem;
	size_t	ninst;
	size_t	index;
};

/*parsing*/
char	**get_path(char **envp);
char	*pipex_join(char *path, char *instructions);
char	*find_command_path(t_program_data *data, char *command);
int		parsing(int ac, char **av, char **envp, t_program_data *data);


/*utils*/
void	print_data(t_program_data *data);
void	print_tab(char **tab);
int		__is_child(pid_t process);
int		__is_same(char *str, char *is_same);


/*init*/
t_program_data	*init_data(int ac, char **av, char **env, t_program_data *data);


/*error*/
void	_error_prompt(char *str);


/*clean*/
void    clean(t_program_data *data);


/*libft*/
char	**ft_split(char const *s, char c);
void	ft_putstr_fd(char *str, int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);

#endif