CC	=	gcc

CFLAGS	=	-Wall -Wextra -Werror 

CFLAGS2	=	-Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

NAME	=	Cub3D

AR	= 	ar rc

RM	=	rm -rf

FILES	=	cub3d.c	\
			utils/utils.c	\
			utils/win_utils.c	\
			utils/get_next_line.c	\
			utils/ft_strrstr.c	\
			utils/textures_init.c	\
			utils/sprite_init.c	\
			utils/player_init.c	\
			parsing_checking/struct_checker.c	\
			parsing_checking/map_validator.c	\
			parsing_checking/map_filling.c	\
			parsing_checking/map_checker.c	\
			parsing_checking/file_reading.c	\

OBJS = $(FILES:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			make -C libft
			make -C minilibx
			mv libft/libft.a .
			mv minilibx/libmlx.dylib .
			$(CC) $(CFLAGS2) $(OBJS) libft.a libmlx.dylib -o $(NAME)

clean:
			$(RM) $(OBJS)
			make clean -C libft
			make clean -C minilibx

fclean:	clean
			$(RM) $(NAME)
			$(RM) libft.a
			$(RM) libmlx.dylib

re:		fclean all
