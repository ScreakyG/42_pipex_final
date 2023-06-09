/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 06:11:52 by fgonzale          #+#    #+#             */
/*   Updated: 2023/05/27 22:21:27 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	exit_here_doc(int temp_stdin, char **line)
{
	close(temp_stdin);
	free(*line);
	*line = get_next_line(temp_stdin);
}

void	get_here_doc(char **argv, t_data *data)
{
	char	*line;
	int		temp_fd;
	int		temp_stdin;

	temp_stdin = dup(0);
	temp_fd = open(".here_doc.tmp", O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (temp_fd < 0)
		exit_error(msg(ERR_HEREDOC, strerror(errno), " : ", 1), data);
	while (1)
	{
		ft_putstr_fd("heredoc > ", 1);
		line = get_next_line(temp_stdin);
		if (!line)
			break ;
		if (ft_strlen(argv[2]) + 1 == ft_strlen(line) && \
			!ft_strncmp(argv[2], line, ft_strlen(argv[2])))
		{
			exit_here_doc(temp_stdin, &line);
			break ;
		}
		else
			ft_putstr_fd(line, temp_fd);
		free(line);
	}
	close(temp_fd);
}
