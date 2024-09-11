/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:31:15 by nnasiri           #+#    #+#             */
/*   Updated: 2024/09/03 10:57:16 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	**get_cmd(char *cmd_str)
{
	char	**cmd;

	cmd = ft_split(cmd_str, ' ');
	return (cmd);
}

void	absoloute_path(t_pipex *store, char **cmd_args)
{
	if (access(cmd_args[0], X_OK) == 0)
	{
		if (execve(cmd_args[0], cmd_args, store->env) == -1)
			system_error("Error Executing Command", store, 1);
	}
	else
		system_error("Command Not Found", store, 127);
}

void	exe_cmd(t_pipex *store, char **cmd_args)
{
	char	*cmd_path;
	char	**paths;

	if (cmd_args[0] == NULL)
		system_error("COMMAND NOT FOUND", store, 127);
	if (cmd_args[0][0] == '/' || cmd_args[0][0] == '.')
		absoloute_path(store, cmd_args);
	else
	{
		paths = store->paths;
		while (*paths)
		{
			cmd_path = create_full_cmd_path(*paths, cmd_args[0]);
			if (!cmd_path)
				system_error("ERROR IN ALLOCATION", store, 1);
			if (access(cmd_path, X_OK) == 0)
			{
				if (execve(cmd_path, cmd_args, store->env) == -1)
					system_error("Error Executing", store, 1);
			}
			free(cmd_path);
			paths++;
		}
		system_error("Command Not Found", store, 127);
	}
}
