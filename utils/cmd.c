/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:31:15 by nnasiri           #+#    #+#             */
/*   Updated: 2024/06/24 17:40:52 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	**get_cmd(char *cmd_str)
{
	char	**cmd;

	cmd = ft_split(cmd_str, ' ');
	return (cmd);
}

void	exe_cmd(t_pipex *store, char **cmd_args)
{
	char **paths;
	char *cmd_path;
	
	printf("exe_cmd");
	paths = store->paths;
	while (*paths)
	{
		printf("%s \n",*paths);
		fflush(stdout);

		cmd_path = create_full_cmd_path(*paths, cmd_args[0]);
		if (!cmd_path)
			system_error("ERROR IN ALLOCATION", store);
		if(access(cmd_path,X_OK) == 0)
		{
			if(execve(cmd_path,cmd_args,store->env) == -1)
				system_error("Error Executing",store);
		}
		free(cmd_path);
		paths++;
	}
	system_error("COMMAND NOT FOUND", store);
}