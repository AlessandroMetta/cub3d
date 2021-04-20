CC	=	gcc

CFLAGS	=	-Wall #-Wextra -Werror 

CFLAGS2	=	-Lmlx -lmlx -framework OpenGL -framework AppKit -lm

NAME	=	Cub3D

AR	= 	ar rc

RM	=	rm -rf

FILES	=	untexuredmap.c \
			raycasting.c \
			utils.c \

OBJS = $(FILES:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			make -C minilibx
			mv minilibx/libmlx.dylib .
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(CFLAGS2)

clean:
			$(RM) $(OBJS)
			make clean -C minilibx

fclean:	clean
			$(RM) $(NAME)
			$(RM) libmlx.dylib
			make clean -C minilibx

re:		fclean all
