/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:53:49 by nnasiri           #+#    #+#             */
/*   Updated: 2024/09/03 11:14:39 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	open_infile(char *infile)
{
	int	fd;

	fd = open(infile, O_RDONLY);
	if (fd < 0)
		random_err("INFILE ERROR");
	return (fd);
}

int	open_outfile(char *outfile, t_pipex *store)
{
	int	fd;

	fd = open(outfile, O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (fd < 0)
	{
		if (store->infile_fd)
			close(store->infile_fd);
		random_err("OUTFILE ERROR");
	}
	return (fd);
}
