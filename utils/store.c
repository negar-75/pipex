/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:54:00 by nnasiri           #+#    #+#             */
/*   Updated: 2024/06/19 15:54:04 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	init_store(t_pipex *store, int argc, char **argv, char **env)
{
	store->argc = argc;
	store->argv = argv;
	store->env = env;
	store->infile_fd = open_infile(argv[1]);
	store->outfile_fd = open_outfile(argv[argc - 1], store);
	store->end[0] = -1;
	store->end[1] = -1;
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
}