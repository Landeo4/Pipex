/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: landeo <landeo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:00:57 by tpotilli          #+#    #+#             */
/*   Updated: 2023/07/19 17:46:16 by landeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pipex.h"

int main(int argc, char **argv, char *envp[])
{
	(void)argc;
	(void)envp;
	if (ft_pasing_manager(argv) == -1)
		return (write(1, "error", 5));
	return (0);

}

int	ft_pasing_manager(char **argv)
{
	int		i;

	i = 0;
	while (argv[i])
		i++;
	if (i == 4)
		return (1);
	return (-1);
}
