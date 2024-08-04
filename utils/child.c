/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:54:23 by nnasiri           #+#    #+#             */
/*   Updated: 2024/06/24 17:51:46 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	child_process(t_pipex *store)
{
	if (dup2(store->infile_fd, STDIN_FILENO) == -1)
		system_error("dup2 infile error", store);
	if (dup2(store->end[1], STDOUT_FILENO) == -1)
		system_error("dup2 end[1] error", store);
	close(store->end[0]);
	close(store->end[1]);
    exe_cmd(store, store->cmd1);
}
