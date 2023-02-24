# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clvicent <clvicent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/01 16:26:04 by clvicent          #+#    #+#              #
#    Updated: 2023/02/17 09:55:59 by clvicent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_atoi.c \
ft_isprint.c \
ft_putchar_fd.c \
ft_striteri.c \
ft_strnstr.c \
ft_bzero.c \
ft_itoa.c \
ft_putendl_fd.c \
ft_strjoin.c \
ft_strrchr.c \
ft_calloc.c \
ft_memchr.c \
ft_putnbr_fd.c \
ft_strlcat.c \
ft_strtrim.c \
ft_isalnum.c \
ft_memcmp.c \
ft_putstr_fd.c \
ft_strlcpy.c \
ft_substr.c \
ft_isalpha.c \
ft_memcpy.c \
ft_split.c \
ft_strlen.c \
ft_tolower.c \
ft_isascii.c \
ft_memmove.c \
ft_strchr.c \
ft_strmapi.c \
ft_toupper.c \
ft_isdigit.c \
ft_memset.c \
ft_strdup.c \
ft_strncmp.c \
ft_putchar.c \
ft_putstr.c \
_get_next_line.c \
_ft_print_bits.c \
_get_index.c \
_ft_get_char.c \
_ft_print_ptr.c \
_ft_printf.c \
_ft_putnbrs.c \
_free_tab.c \
m_ft_abs.c \
_ft_gen_tab.c \
_ft_set_tab.c \
_get_file_len.c \
_tab_filler.c \
_ft_putstrs_fd.c \
_printab.c \
_ft_strslen.c \
_check_ext.c \
_close_gnl.c


SRCSB	= ft_lstnew.c \
ft_lstadd_front.c \
ft_lstsize.c \
ft_lstlast.c \
ft_lstadd_back.c \
ft_lstdelone.c \
ft_lstclear.c \
ft_lstiter.c \
ft_lstmap.c

OBJS    = ${SRCS:.c=.o}

OBJSB	= ${SRCSB:.c=.o}

FLAGS    = -Wall -Wextra -Werror

NAME    = libft.a

.c.o:
	gcc -I includes ${FLAGS} -c $< -o ${<:.c=.o}

all:        ${NAME}

${NAME}: ${OBJS}
	ar rc ${NAME} ${OBJS}

clean:
	rm -f ${OBJS} ${OBJSB}

fclean: clean
	rm -f ${NAME}

bonus:	${OBJS} ${OBJSB}
	ar rc ${NAME} ${OBJS} ${OBJSB}

re:            fclean    all

.PHONY:        all clean fclean re bonus
