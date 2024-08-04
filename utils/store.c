/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:54:00 by nnasiri           #+#    #+#             */
/*   Updated: 2024/06/24 15:40:56 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	init_store(t_pipex *store, int argc, char **argv, char **env)
{
	store->argc = argc;
	store->argv = argv;
	store->env = env;
    store->end[0] = -1;
	store->end[1] = -1;
    store->paths = NULL;
	store->cmd1 = NULL;
	store->cmd2 = NULL;
    store->infile_fd = open_infile(argv[1]);
	store->outfile_fd = open_outfile(argv[argc - 1], store);
    store->paths = get_path(env);
	store->cmd1 = get_cmd(argv[2]);
	store->cmd2 = get_cmd(argv[3]);
}

void	free_store(t_pipex *store)
{
	if (store->infile_fd >= 0)
		close(store->infile_fd);
	if (store->outfile_fd >= 0)
		close(store->outfile_fd);
	if (store->end[0] >= 0)
		close(store->end[0]);
	if (store->end[1] >= 0)
		close(store->end[1]);
    if(store->paths)
        free_str(store->paths);
    if(store->cmd1)
        free_str(store->cmd1);
    if(store->cmd2)
        free_str(store->cmd2);
}