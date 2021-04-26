# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/26 16:15:19 by ametta            #+#    #+#              #
#    Updated: 2021/04/26 14:45:51 by ametta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	=	gcc

CFLAGS	=	-Wall -Wextra -Werror

NAME	=	libft.a

AR	= 	ar rc

RM	=	rm -rf

FILES	=	ft_atoi.c	\
		ft_strcmp.c		\
		ft_realloc.c		\
		ft_strcpy.c		\
		ft_isprint.c	\
		ft_memset.c	\
		ft_strjoin.c	\
		ft_strtrim.c	\
		ft_bzero.c	\
		ft_itoa.c	\
		ft_putchar_fd.c	\
		ft_strlcat.c	\
		ft_substr.c	\
		ft_calloc.c	\
		ft_memccpy.c	\
		ft_putendl_fd.c	\
		ft_strlcpy.c	\
		ft_tolower.c	\
		ft_isalnum.c	\
		ft_memchr.c	\
		ft_putnbr_fd.c	\
		ft_strlen.c	\
		ft_toupper.c	\
		ft_isalpha.c	\
		ft_memcmp.c	\
		ft_putstr_fd.c	\
		ft_strncmp.c	\
		ft_isascii.c	\
		ft_memcpy.c	\
		ft_strchr.c	\
		ft_strnstr.c	\
		ft_isdigit.c	\
		ft_memmove.c	\
		ft_strdup.c	\
		ft_strrchr.c	\
		ft_strmapi.c	\
		ft_split.c	\

OBJS = $(FILES:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)
			ranlib $(NAME)

clean:
			$(RM) $(OBJS)

fclean:	clean
			$(RM) $(NAME)

re:		fclean all
