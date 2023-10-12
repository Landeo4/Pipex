/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:58:51 by tpotilli          #+#    #+#             */
/*   Updated: 2023/10/12 14:28:46 by tpotilli         ###   ########.fr       */
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
*/

void child_process(int fd1, char *argv[], char *envp[], int *end)
{
	close(end[0]);
    /*if (dup2 < 0)
		return (1);*/
	dup2(fd1, STDIN_FILENO);
	dup2(end[1], STDOUT_FILENO);
	ft_do_process(envp, argv[2]);
    close(end[1]);
	close(fd1);
}

void ft_do_process(char *envp[], char *cmd)
{
	int		i;
	char	*path;
	char	**mypath;
	char	**cmdarg;

	i = -1;
	//path = ft_substr("PATH=", 22, 1);
	path = ft_strnstr("envp", "PATH=", 50);
	mypath = ft_split(path, ':');
	cmdarg = ft_split(cmd, ' ');
	while (mypath[++i])
	{
		cmd = ft_strjoin(mypath[i], cmd);
		if (!cmd)
			return ;
		execve(mypath[i], cmdarg, envp);
	}
}

char *ft_get_line(char *start, char end)
{
	char	*result;
	int		i;

	i = 0;
	result = NULL;
	if (!start || !end)
		return (NULL);
	while (start[i] && start[i] != end)
	{
		result[i] = start[i];
		i++;
	}
	return (result);
}
