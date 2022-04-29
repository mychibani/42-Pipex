/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 08:33:36 by ychibani          #+#    #+#             */
/*   Updated: 2022/03/29 14:37:28 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
#endif

typedef struct s_cmd    t_cmd;
typedef struct s_program_data    t_program_data;

struct s_cmd
{
    char    **opt;
    char    *cmd;
    t_cmd   *next;
};

struct s_program_data
{
    int fd[2];
    char *instruction_path;
};