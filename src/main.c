/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:54:32 by nnasiri           #+#    #+#             */
/*   Updated: 2024/09/03 16:00:47 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"
#include <stdio.h>

void	clean_up(t_pipex *store, pid_t id, pid_t id_2)
{
	int	status;

	free_store(store);
	waitpid(id, &status, 0);
	waitpid(id_2, &status, 0);
}

int	main(int argc, char **argv, char **env)
{
	pid_t	id;
	pid_t	id_2;
	t_pipex	store;

	if (!env || !env[0])
		random_err("NO ENV");
	if (argc != 5)
		random_err("Wrong Argument");
	init_store(&store, argc, argv, env);
	if (pipe(store.end) == -1)
		system_error("PIPE ERROR", &store, 1);
	id = fork();
	if (id < 0)
		system_error("FORK ERROR", &store, 1);
	if (id == 0)
		child_process_1(&store);
	id_2 = fork();
	if (id_2 < 0)
		system_error("FORK ERROR", &store, 1);
	if (id_2 == 0)
		child_process_2(&store);
	clean_up(&store, id, id_2);
	return (0);
}
