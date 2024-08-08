/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:08:51 by nnasiri           #+#    #+#             */
/*   Updated: 2024/06/24 17:13:55 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

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