/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:54:23 by nnasiri           #+#    #+#             */
/*   Updated: 2024/08/08 19:04:17 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	child_process(t_pipex *store)
{
	close(store->end[0]);
	if (dup2(store->infile_fd, STDIN_FILENO) == -1)
		system_error("dup2 infile error", store);
	if (dup2(store->end[1], STDOUT_FILENO) == -1)
		system_error("dup2 end[1] error", store);
	close(store->infile_fd);
	close(store->end[1]);
    exe_cmd(store, store->cmd1);
}

void parent_process(t_pipex *store)
{
  close(store->end[1]);
  if (dup2(store->end[0], STDIN_FILENO) == -1)
    system_error("dup2 end[0] error", store);
  if (dup2(store->outfile_fd, STDOUT_FILENO) == -1)
    system_error("dup2 outfile_fd error", store);
  close(store->outfile_fd);
  close(store->end[0]);
  exe_cmd(store, store->cmd2);
}