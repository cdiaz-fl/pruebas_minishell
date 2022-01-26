# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ioromero <ioromero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/07 11:49:38 by cdiaz-fl          #+#    #+#              #
#    Updated: 2022/01/25 07:55:11 by cdiaz-fl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= 	minishell.c			\
			src/cd.c			\
			src/env.c			\
			src/free.c			\
			src/utils.c			\
			src/signals.c		\
			src/builtin_cmd.c	\
			src/split_tokens.c	\
			src/pipe.c	\
			src/system_cmd.c	\
			src/debug.c	\
			src/expand.c	\

OBJS	= ${SRCS:.c=.o}

NAME	= minishell

SNAME	= fsanitize

RM		= rm -rf

CC		= gcc

RED		= \033[0;31m

GREEN		= \033[0;32m

WHITE		= \033[0;37m

SFLAGS	= -fsanitize=address -g3

CFLAGS	= -Wall -Werror -Wextra

LIBFT 	=  -C ./libft

READLINE = -lreadline -L ~/.brew/opt/readline/lib -I ~/.brew/opt/readline/include# -lreadline -L /Users/$(USER)/.brew/opt/readline/lib -I/Users/$(USER)/.brew/opt/readline/include

all:	
		@ $(MAKE) -s $(NAME)
		@ echo "$(GREEN)Compiled	✅$(WHITE)"

$(NAME) :	${OBJS}
			@ ${MAKE} ${LIBFT}
			@ echo "$(RED)Compiling...	⏳$(WHITE)"
			@ $(CC) ${CFLAGS} ${OBJS} ./libft/libft.a ${READLINE} -o $(NAME)

s:		
		@ $(MAKE) -s fsanitize
		@ echo "$(GREEN)Compiled with fsanitize	✅$(WHITE)"

$(SNAME):	${OBJS}
			@ ${MAKE} ${LIBFT}
			@ echo "$(RED)Compiling with fsanitize...	⏳$(WHITE)"
			@ $(CC) ${CFLAGS} $(SFLAGS) ${OBJS} ./libft/libft.a ${READLINE} -o $(NAME)
			
clean:
		@ echo "$(RED)Clean in progress...	⏳$(WHITE)"
		@ $(RM) minishell.dSYM
		@ $(RM) $(OBJS)
		@ echo "$(GREEN)Clean done	✅$(WHITE)"

fclean: 
		@ echo "$(RED)Fclean in progress... ⏳$(WHITE)"
		@ $(RM) *.dSYM
		@ $(RM) $(OBJS)
		@ $(RM) $(NAME)
		@ echo "$(GREEN)Fclean done	✅$(WHITE)"

re:		fclean all

.PHONY: all s clean fclean re
