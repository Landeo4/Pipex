/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parent_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:59:09 by tpotilli          #+#    #+#             */
/*   Updated: 2023/10/13 17:29:13 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent_process(int fd4, char *argv[], char *envp[], int *end)
{
	char	**path;

	path = ft_take_line(envp, "PATH=");
	close(end[1]);
	dup2(fd4, STDOUT_FILENO);
	dup2(end[0], STDIN_FILENO);
	ft_do_process(envp, argv[3], path);
	close(end[0]);
	close(fd4);
}
