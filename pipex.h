#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_pipex
{
	int		argc;
	char	**argv;
	char	**env;
	int		infile_fd;
	int		outfile_fd;
	int		end[2];
    char    **paths;
}			t_pipex;

void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putstr_fd(char *s, int fd);
int	        ft_strncmp(const char *s1, const char *s2, size_t n);
char	    **ft_split(char const *s, char c);


void	    random_err(char *msg);
void		system_error(char *msg, t_pipex *store);
void	    free_store(t_pipex *store);

int			open_infile(char *infile);
int			open_outfile(char *outfile, t_pipex *store);
void		init_store(t_pipex *store, int argc, char **argv, char **env);
void	    child_process(t_pipex *store);
char        **get_path(char **env);
void        exe_cmd1(t_pipex *store);


#endif