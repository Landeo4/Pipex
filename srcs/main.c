/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:00:57 by tpotilli          #+#    #+#             */
/*   Updated: 2023/07/14 17:56:09 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pipex.h"

int main(int argc, char **argv, char *envp[])
{
	(void)argc;
	(void)argv;
	char **buff;
	int i;
	int j;

	j = 0;
	i = ft_envp_found(envp);
	//printf("i = %d\n", i);
	buff = ft_recup_env(envp, i);
	//printf("%s\n", buff[0]);
	i = 0;
	while (buff[i])
	{
		while (buff[i][j])
		{
			printf("%c", buff[i][j]);
			j++;
		}
		j = 0;
		i++;
		printf("\n");
	}
	return (0);
}

char **ft_recup_env(char **envp, int i)
{
	char	**recup;

	recup = ft_split(envp[i], ':');
	//printf("env = %s\n", recup[i]);
	if (!recup)
		return (NULL);
	return (recup);
}

int	ft_envp_found(char *envp[])
{
	int 	i;
	const char	*word;
	int		j;
	int		cpt;

	j = 0;
	cpt = 0;
	word = "PATH=";
	i = 0;
	while (envp[i])
	{
		//printf("%s\n", envp[i]);
		while (envp[i][j] == word[j])
		{
			cpt++;
			if (cpt == 5)
				return (i);
			j++;
			//printf("j = %d\n", j);
		}
		j = 0;
		cpt = 0;
		i++;
	}
	return (0);
}