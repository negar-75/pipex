/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:15:50 by nnasiri           #+#    #+#             */
/*   Updated: 2024/06/24 16:27:56 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*find_path(char **env)
{
	while (ft_strncmp("PATH", *env, 4))
		env++;
	return (*env + 5);
}

char	**get_path(char **env)
{
	char	*path;
	char	**split_path;

	path = find_path(env);
	split_path = ft_split(path, ':');
	if (!split_path)
		random_err("ERROR IN ALLOCATION");
	return (split_path);
}

char	*create_full_cmd_path(char *path, char *cmd)
{
	int		i;
	int		j;
	char	*full_path;

	i = ft_strlen(path);
	j = ft_strlen(cmd);
	full_path = malloc(i + j + 2);
	if (!full_path)
		return (NULL);
	i = -1;
	while (path[++i])
		full_path[i] = path[i];
	full_path[i++] = '/';
	j = -1;
	while (cmd[++j])
	{
		full_path[i] = cmd[j];
		i++;
	}
	full_path[i] = '\0';
	return (full_path);
}
