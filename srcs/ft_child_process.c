/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:58:51 by tpotilli          #+#    #+#             */
/*   Updated: 2023/10/05 08:06:44 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
**	This function takes as parameter: 
**
**	int fd
**	char *argv[], 
**  char *envp[],
**  int *end
**
** =====================================================
** =====================================================
**
** 
**
*/

int child_process(int fd1, char *argv[], char *envp[], int *end)
{
	char	*path;
	char	**mypath;
	char	**cmdarg;
	int		i;
	char	*cmd;

	i = -1;
	path = ft_substr(envp, 0, 1);
	printf("path = %s\n", path);
	mypath = ft_split(path, ':');
	printf("my path %s\n", mypath);
	cmdarg = ft_split(argv[2], " ");
	printf("cmdarg %s\n", cmdarg);
	close(end[0]);
    /*if (dup2 < 0)
		return (1);*/
	dup2(fd1, STDIN_FILENO);
	dup2(end[1], STDOUT_FILENO);
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
	close(fd1);
	exit(EXIT_SUCCESS);
}
