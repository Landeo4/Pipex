/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:58:51 by tpotilli          #+#    #+#             */
/*   Updated: 2023/10/04 14:12:49 by tpotilli         ###   ########.fr       */
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
	dup2(fd1, STDOUT_FILENO);
	close(end[0]);
	close(end[1]);
	execve(argv[1], argv, envp);
	exit(EXIT_SUCCESS);
}
