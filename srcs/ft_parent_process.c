/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parent_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:59:09 by tpotilli          #+#    #+#             */
/*   Updated: 2023/10/04 10:52:05 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int parent_process(int fd4, char *argv[], char *envp[], int *end)
{
   close(end[1]);
    /*if (dup2 < 0)
		return (1);*/
	execve(argv[1], argv, envp);
	dup2(fd1, end[0]);
    close(end[0]);
	close(fd4);
	exit(EXIT_SUCCESS);
}
