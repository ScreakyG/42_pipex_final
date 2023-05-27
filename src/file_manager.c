/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 05:29:50 by fgonzale          #+#    #+#             */
/*   Updated: 2023/04/15 19:01:11 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	get_infile(t_data *data, char **argv)
{
	data->is_heredoc = 0;
	data->infile = open(argv[1], O_RDONLY, 0644);
	if (data->infile < 0)
		msg(strerror(errno), " : ", argv[1], 1);
}

void	get_outfile(t_data *data, char **argv, int argc)
{
	if (data->is_heredoc == 1)
		data->outfile = open(argv[argc - 1], O_CREAT | O_APPEND | O_RDWR, 0644);
	else
		data->outfile = open(argv[argc - 1], O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (data->outfile < 0)
		msg(strerror(errno), " : ", "", 1);
}
