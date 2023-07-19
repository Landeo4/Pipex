/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: landeo <landeo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:39:00 by tpotilli          #+#    #+#             */
/*   Updated: 2023/07/19 17:34:59 by landeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// =======================================================================
//								Colors
// =======================================================================

# define BLACK "\001\033[1;30m\002"
# define RED "\001\033[1;31m\002"
# define GREEN "\001\033[1;32m\002"
# define YELLOW "\001\033[1;33m\002"
# define BLUE "\001\033[1;34m\002"
# define PURPLE "\001\033[1;35m\002"
# define CYAN "\001\033[1;36m\002"
# define WHITE "\001\033[1;37m\002"
# define RESET "\001\033[0m\002"

// =======================================================================
//								Include
// =======================================================================

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <signal.h>

// =======================================================================
//								Libft
// =======================================================================

int		ft_letter(char const *s, char c, int i);
char	**ft_free(char **split, int index_word);
int		ft_word(char const *s, char c);
char	**ft_cpy(char const *s, char c, char **split, int i);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strnstr(const char *big, const char *little, size_t len);

// =======================================================================
//								Pipex
// =======================================================================

int     ft_pasing_manager(char **argv);
void	writestr(int fd, const char *str);
int		test(void);
int		ft_envp_found(char *envp[]);
char **ft_recup_env(char **envp, int i);

#endif
