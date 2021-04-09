# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ametta <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/26 16:15:19 by ametta            #+#    #+#              #
#    Updated: 2021/04/09 11:51:47 by ametta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	=	gcc

CFLAGS	=	-Wall -Wextra -Werror

NAME	=	libft.a

AR	= 	ar rc

RM	=	rm -rf

FILES	=	ft_atoi.c	\
		ft_isprint.c	\
		ft_memset.c	\
		ft_strjoin.c	\
		ft_strtrim.c	\
		ft_bzero.c	\
		ft_itoa.c	\
		ft_strlcat.c	\
		ft_substr.c	\
		ft_calloc.c	\
		ft_memccpy.c	\
		ft_strlcpy.c	\
		ft_isalnum.c	\
		ft_memchr.c	\
		ft_strlen.c	\
		ft_isalpha.c	\
		ft_memcmp.c	\
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
		get_next_line.c

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
