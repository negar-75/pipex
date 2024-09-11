/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:57:54 by nnasiri           #+#    #+#             */
/*   Updated: 2024/09/03 10:57:57 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pipex
{
	int		argc;
	char	**argv;
	char	**env;
	int		infile_fd;
	int		outfile_fd;
	int		end[2];
	char	**paths;
	char	**cmd1;
	char	**cmd2;
}			t_pipex;

void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putstr_fd(char *s, int fd);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		**ft_split(char const *s, char c);
size_t		ft_strlen(const char *s);

void		free_str(char **str);
void		random_err(char *msg);
void		system_error(char *msg, t_pipex *store, int error_code);
void		free_store(t_pipex *store);

int			open_infile(char *infile);
int			open_outfile(char *outfile, t_pipex *store);
void		init_store(t_pipex *store, int argc, char **argv, char **env);
void		child_process_1(t_pipex *store);
void		child_process_2(t_pipex *store);
char		**get_path(char **env);
void		exe_cmd(t_pipex *store, char **cmd_args);
char		**get_cmd(char *cmd_str);
char		*create_full_cmd_path(char *path, char *cmd);
#endif