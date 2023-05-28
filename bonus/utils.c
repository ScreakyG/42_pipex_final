/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 01:41:24 by fgonzale          #+#    #+#             */
/*   Updated: 2023/05/28 22:31:22 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*get_paths_envp(char **envp)
{
	while (*envp)
	{
		if (!ft_strncmp(*envp, "PATH", 4))
			return (*envp + 5);
		envp++;
	}
	return (NULL);
}

char	*get_cmd(char **cmd_paths, char *cmd_args)
{
	char	*cmd;
	char	*temp;

	if (access(cmd_args, F_OK | X_OK) == 0)
		return (cmd_args);
	while (cmd_paths && *cmd_paths)
	{
		temp = ft_strjoin(*cmd_paths, "/");
		cmd = ft_strjoin(temp, cmd_args);
		free(temp);
		if (access(cmd, 0) == 0)
			return (cmd);
		free(cmd);
		cmd_paths++;
	}
	return (NULL);
}
