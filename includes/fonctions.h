/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 08:28:22 by ychibani          #+#    #+#             */
/*   Updated: 2022/05/13 22:33:56 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FONCTIONS_H
# define FONCTIONS_H

typedef struct s_program_data	t_program_data;
typedef struct s_list			t_list;
typedef int						t_bool;

struct	s_program_data
{
	t_bool	mode;
	int		*pid;
	int		pipe[2];
	int		prev_read;
	int		outfile;
	char	**path;
	char	**env;
	char	*limiter;
	char	*infile_name;
	char	*outfile_name;
	t_list	*head;
	t_list	*elem;
	size_t	ninst;
	size_t	index;
};

struct s_list
{
	char	**content;
	t_list	*next;
};

t_program_data	*init_data(int ac, char **av, char **env, t_program_data *data);
char			**get_path(char **envp);
char			*pipex_join(char *path, char *instructions);
char			*find_command_path(t_program_data *data);
int				parsing(int ac, char **av, char **envp, t_program_data *data);
int				_file_descriptors_duplicators(int _first, int _second);
int				_close_file_descriptors(int _first, int _second);
void			print_data(t_program_data *data);
void			print_tab(char **tab);
int				__is_child(pid_t process);
int				__is_same(char *str, char *is_same);
int				open_infile(char *infile_name, t_program_data *data);
int				open_outfile(char *name, int mode, t_program_data *data);
void			starter_child_worker(t_program_data *data);
void			child_worker(t_program_data *data);
void			finisher_child_worker(t_program_data *data);
void			exec_children_work(t_program_data *data);
int				here_doc(char *limiter);
void			_error_prompt(char *str);
void			clean(t_program_data *data);
void			_clean_char_tab(char **str);
void			_clean_exit(t_program_data *data);
char			**ft_split(char const *s, char c);
void			ft_putstr_fd(char *str, int fd);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strlen(const char *str);
void			ft_lstadd_back(t_list **head, t_list *new);
t_list			*ft_lstnew(void *content);
int				ft_lstsize(t_list *lst);
void			ft_lstclear(t_list **lst, void (*del)(void*));
int				ft_putnbr_fd(int n, int fd);
char			*__gnl(int fd);

#endif