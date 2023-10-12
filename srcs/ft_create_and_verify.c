/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_and_verify.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 23:14:04 by tpotilli          #+#    #+#             */
/*   Updated: 2023/10/11 10:51:32 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_parsing(int argc)
{
	if (argc != 5)
	{
		write(0, "error invalid arguments\n", 25);
		write(1, "argument should look like this : ./pipex infile cmd1 cmd2 outfile\n", 46);
		return (1);
	}
	return (0);
}

/*
**	This function takes as parameter: 
**
**	Char *argv
**	int flag
**
** =====================================================
** =====================================================
**
** ft_create_fd will open the file by argv with the flags
** and give octal permission :
** (reading, writing and executionfor users)
** the result is in fd
*/

int ft_create_fd(char *argv, int flag)
{
    int fd;

    fd = open(argv, flag, 0777);
    if (fd < 0)
        perror("ERROR");
    return (fd);
}
