NAME = libft.a

SRCS = ${wildcard *.c}

RM = /bin/rm -f 

CC = gcc

CFLAGS = -Wall -Wextra -Werror -c  

OBJS = ${SRCS:.c=.o}

%.o: %.c
	${CC} ${CFLAGS} $<

all: ${NAME}

$(NAME): ${OBJS}
	ar -rc ${NAME} ${OBJS}
	ranlib ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
