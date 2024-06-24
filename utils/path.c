#include "../pipex.h"
char    *find_path(char **env)
{
   while(ft_strncmp("PATH",*env,4))
        env++;
    return(*env+5);
}

char    **get_path(char **env)
{
    char *path;
    char **split_path;

    path = find_path(env);
    split_path = ft_split(path,':');
    if(!split_path)
        random_err("ERROR IN ALLOCATION");
    return (split_path);
}