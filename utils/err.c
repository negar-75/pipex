#include "../pipex.h"

void err_message(char *msg)
{
    ft_putendl_fd(msg,2);
    exit(EXIT_FAILURE);
}