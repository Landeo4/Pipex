# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 16:41:59 by tpotilli          #+#    #+#              #
#    Updated: 2023/10/05 07:55:23 by tpotilli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Pipex

SRCS	=	srcs/main.c\
			srcs/pipex.c\
			srcs/ft_create_and_verify.c\
			srcs/ft_child_process.c\
			srcs/ft_parent_process.c\
			libft/ft_split.c\
			libft/ft_strlen.c\
			libft/ft_strncmp.c\
			libft/ft_strnstr.c\
			libft/ft_substr.c\
			libft/ft_strdup.c\
			libft_ft_str_join.c\

OBJS = $(SRCS:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra -g3 -g
.c.o:
		${CC} ${CFLAGS} -Iincludes -c $< -o ${<:.c=.o}

all : ${NAME}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:
			rm -rf ${OBJS}

fclean:		clean
			rm -rf ${NAME}

re:			fclean all

.PHONY:	all clean fclean re