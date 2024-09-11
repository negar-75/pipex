/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:54:15 by nnasiri           #+#    #+#             */
/*   Updated: 2024/09/03 10:58:29 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	random_err(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(1);
}

void	system_error(char *msg, t_pipex *store, int error_code)
{
	ft_putendl_fd(msg, 2);
	free_store(store);
	exit(error_code);
}
