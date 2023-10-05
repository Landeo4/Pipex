/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parent_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:59:09 by tpotilli          #+#    #+#             */
/*   Updated: 2023/10/05 07:28:28 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int parent_process(int fd4, char *argv[], char *envp[], int *end)
{
	close(end[1]);
	dup2(fd4, STDOUT_FILENO);
	dup2(end[0], STDIN_FILENO);
	execve(argv[4], argv, envp);
	close(end[0]);
	close(fd4);
	exit(EXIT_SUCCESS);
}
