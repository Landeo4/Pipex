/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:58:51 by tpotilli          #+#    #+#             */
/*   Updated: 2023/10/13 17:30:52 by tpotilli         ###   ########.fr       */
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

void	child_process(int fd1, char *argv[], char *envp[], int *end)
{
	char	**path;

	path = ft_take_line(envp, "PATH=");
	close(end[0]);
	/*if (dup2 < 0)
		return (1);*/
	dup2(fd1, STDIN_FILENO);
	dup2(end[1], STDOUT_FILENO);
	ft_do_process(envp, argv[2], path);
	close(end[1]);
	close(fd1);
}

void	ft_do_process(char *envp[], char *cmd, char *path[])
{
	int		i;
	char	**cmdarg;
	char	*fullpath;

	i = -1;
	cmdarg = ft_split(cmd, ' ');
	while (path[++i])
	{
		fullpath = ft_strjoin(path[i], cmd);
		if (!fullpath)
		{
			ft_freedb(cmdarg);
			return ;
		}
		execve(fullpath, cmdarg, envp);
		free(fullpath);
	}
	ft_freedb(cmdarg);
	write(1, "Command not found\n", 19);
}

void	ft_freedb(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	**ft_take_line(char **big, char *little)
{
	int		little_length;
	int		i;
	char	**tmp;

	tmp = NULL;
	i = 0;
	if (!big || !little)
		return (NULL);
	little_length = strlen(little);
	while (big[i])
	{
		if (strncmp(big[i], little, little_length) == 0)
		{
			tmp = ft_split(big[i] + little_length, ':');
			return (tmp);
		}
		i++;
	}
	return (NULL);
}
