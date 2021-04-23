NAME = get_next_line.a

SRCS = get_next_line.c get_next_line_utils.c

RM = /bin/rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror -c

OBJS = ${SRCS:.c=.o}

%.o: %.c
	${CC} ${CFLAGS} $< -I .

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