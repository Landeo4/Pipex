/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parent_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:59:09 by tpotilli          #+#    #+#             */
/*   Updated: 2023/10/05 09:55:02 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int parent_process(int fd4, char *argv[], char *envp[], int *end)
{
	char	*path;
	char	*cmd;
	char	**mypath;
	char	**cmdarg;
	int		i;

	i = -1;
	path = ft_substr(envp[22], 22, 1);
	mypath = ft_split(path, ':');
	cmdarg = ft_split(argv[2], ' ');
	close(end[1]);
	dup2(fd4, STDOUT_FILENO);
	dup2(end[0], STDIN_FILENO);
	while (mypath[++i])
	{
		cmd = ft_strjoin(mypath[i], argv[2]);
		if (!cmd)
			return (-1);
		if (execve(cmd, cmdarg, envp))
			break ;
		free(cmd);
	}
	close(end[0]);
	close(fd4);
	exit(EXIT_SUCCESS);
}
