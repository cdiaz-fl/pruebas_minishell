/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioromero <ioromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 09:04:53 by ioromero          #+#    #+#             */
/*   Updated: 2021/11/24 09:50:41 by ioromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*nx;
}					t_listt;

typedef struct s_info
{
	va_list	args;
	size_t	size;
}	t_info;

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_atoi(const char *str);
int		ft_printf(const char *format, ...);
int		ft_strncmp(char *s1, char *s2, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

void	ft_bzero(void *str, size_t len);
void	*ft_realloc(void *ptr, size_t size);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *str, int c, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);

char	*ft_itoa(int n);
char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_substr(char const *s, unsigned int start, size_t len);

void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);

int		ft_lstsize(t_listt *lst);

void	ft_lstadd_back(t_listt **lst, t_listt *new);
void	ft_lstiter(t_listt *lst, void (*f)(void *));
void	ft_lstadd_front(t_listt **alst, t_listt *new);
void	ft_lstdelone(t_listt *lst, void (*del)(void*));
void	ft_lstclear(t_listt **lst, void (*del)(void *));

t_listt	*ft_lstlast(t_listt *lst);
t_listt	*ft_lstnew(void *content);
t_listt	*ft_lstmap(t_listt *lst, void *(*f)(void *), void (*del)(void *));

#endif
