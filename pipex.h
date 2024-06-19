#ifndef PIPEX_H
#define PIPEX_H


# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include  <fcntl.h>



typedef struct s_pipex
{
    int argc;
    char **argv;
    char **env;
    int infile_fd;
    int outfile_fd;
    int end[2];
}t_pipex;

void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);

void err_message(char *msg);

int open_infile(char *infile);
int open_outfile(char *outfile,t_pipex *store);

#endif