/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:58:51 by tpotilli          #+#    #+#             */
/*   Updated: 2023/10/04 10:52:12 by tpotilli         ###   ########.fr       */
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
	close(end[0]);
    /*if (dup2 < 0)
		return (1);*/
	execve(argv[1], argv, envp);
	dup2(fd1, end[0]);
    close(end[0]);
	close(fd1);
	exit(EXIT_SUCCESS);
}
