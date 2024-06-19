#include "../pipex.h"

int open_infile(char *infile)
{
    int fd;
    fd = open(infile,O_RDONLY);
    if(fd < 0)
    {
        perror("Error infile");
        exit(EXIT_FAILURE);
    }
    return fd;
}

int open_outfile(char *outfile,t_pipex *store)
{
    int fd;
    fd = open(outfile,O_RDWR | O_CREAT | O_TRUNC, 0666);
    if(fd < 0)
    {
        perror("Error infile");
        free_store(store);
        exit(EXIT_FAILURE);
    }
    return fd;
}