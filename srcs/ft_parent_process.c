/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parent_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:59:09 by tpotilli          #+#    #+#             */
/*   Updated: 2023/10/04 14:15:07 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int parent_process(int fd4, char *argv[], char *envp[], int *end)
{
	close(end[1]);
	dup2(fd4, STDIN_FILENO);
	close(end[0]);
	close(end[1]);
	execve(argv[4], argv, envp);
	exit(EXIT_SUCCESS);
}
