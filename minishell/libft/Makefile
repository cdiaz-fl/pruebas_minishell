# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ioromero <ioromero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/28 10:17:48 by ioromero          #+#    #+#              #
#    Updated: 2021/11/26 12:02:10 by ioromero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_isalpha.c ft_memccpy.c ft_memset.c ft_realloc.c ft_strlcat.c ft_strnstr.c ft_toupper.c\
ft_atoi.c ft_isascii.c ft_memchr.c ft_putchar_fd.c ft_split.c ft_strlcpy.c ft_strrchr.c ft_strcpy.c\
ft_bzero.c ft_isdigit.c ft_memcmp.c ft_putendl_fd.c ft_strchr.c ft_strlen.c ft_strtrim.c\
ft_calloc.c ft_isprint.c ft_memcpy.c ft_putnbr_fd.c  ft_strdup.c ft_strmapi.c ft_substr.c\
ft_isalnum.c ft_itoa.c ft_memmove.c ft_putstr_fd.c  ft_strjoin.c ft_strncmp.c ft_tolower.c\
ft_printf.c get_next_line.c

SRCS_BONUS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c\
ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c\
		
OBJS	= ${SRCS:.c=.o}

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

NAME	= libft.a

AR		= ar rcs

RM		= rm -f

CFLAGS	= -Wall -Werror -Wextra

.c.o:
			@gcc ${CFLAGS} -g -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			@${AR} ${NAME} ${OBJS}

bonus:	${OBJS} ${OBJS_BONUS}
			@${AR} ${NAME} ${OBJS} ${OBJS_BONUS}

all:		${NAME}

clean:
			@${RM} ${OBJS} ${OBJS_BONUS}

fclean:		clean
			@${RM} ${NAME}
			
re:			fclean all

.PHONY:		all clean fclean re bonus