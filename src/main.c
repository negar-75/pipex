/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:54:32 by nnasiri           #+#    #+#             */
/*   Updated: 2024/06/19 15:55:45 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int argc, char **argv, char **env)
{
	pid_t	id;
	t_pipex	store;

	if (argc != 5)
		err_message("Wrong Argument");
	init_store(&store, argc, argv, env);
	if (pipe(store.end) == -1)
		system_error("PIPE ERROR", &store);
	id = fork();
	if (id < 0)
		system_error("FORK ERROR", &store);
    if(id == 0)
        child_process(&store);
	return (0);
}
