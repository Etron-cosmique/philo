/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:31:56 by clvicent          #+#    #+#             */
/*   Updated: 2023/02/17 09:55:42 by clvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include	<fcntl.h>
# include	<stdlib.h>
# include	<stddef.h>
# include	<stdarg.h>
# include	<unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

// MANDATORY
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
int		ft_isalnum(int i);
int		ft_isalpha(int i);
int		ft_isascii(int i);
int		ft_isdigit(int i);
int		ft_isprint(int i);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *m, const char *a, size_t l);
char	*ft_strrchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t l);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
void	*ft_calloc(size_t n, size_t s);
char	*ft_strdup(const char *s);
int		ft_putstr(char *s);
int		ft_putchar(char c);

// BONUS
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **alst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// GNL
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
int		get_file_len(char *filename);

// printf
int		ft_putnbr_base(unsigned int n, char *b);
int		ft_putnbr(int i);
int		ft_putnbru(unsigned int i);
int		ft_print_ptr(void *p);
int		ft_printf(const char *s, ...);

// HS
int		ft_get_char(const char *s, char c);
int		get_index(char *s);
void	ft_print_bits(char c);
void	free_tab(int **tab, const int ylen);
char	**ft_exit(char **strs);
int		**ft_gen_tab(int xlen, int ylen, int value);
void	ft_set_tab(int xlen, int ylen, int **tab, int value);
void	tab_filler(int **tab, char **data, int index);
int		ft_putstrs_fd(char **strs, int fd);
void	printab(int **tab, int ylen, int xlen);
int		ft_strslen(char **strs);
int		check_ext(char *str, char *ext);
int		close_gnl(int fd);

// MATH
int		ft_abs(int i);

#endif