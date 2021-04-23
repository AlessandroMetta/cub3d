NAME	=	cub3D
LIBFT	=	./libft/libft.a
GNL		=	./get_next_line/get_next_line.a
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f
LIBS	=	-Lmlx -lmlx -framework OpenGL -framework AppKit -lm
MLX		=	libmlx.dylib
SRCS	=	srcs/parse/parse_args.c \
			srcs/parse/parse_main.c \
			srcs/parse/parse_utils.c \
			srcs/parse/useless.c \
			srcs/parse/parse_map.c \
			srcs/engine/window_main.c \
			srcs/engine/raycaster.c \
			srcs/engine/save.c \
			srcs/engine/engine_utils.c \
			srcs/engine/hooks.c \
			srcs/engine/sprites.c \
			srcs/engine/draw_sprites.c \
			srcs/main/main.c 

OBJ		=	$(SRCS:.c=.o)

%.o	:	%.c
			$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME)	:	$(MLX) $(OBJ)
			make -C ./libft
			make -C ./get_next_line
			$(CC) $(CFLAGS) -o $(NAME) $(LIBFT) $(GNL) $(OBJ) $(LIBS)

$(MLX)	:
			@$(MAKE) -C mlx
			@mv mlx/$(MLX) .

debug	:	$(MLX) $(OBJ)
			make -C ./libft
			make -C ./get_next_line
			$(CC) -g $(CFLAGS) -o $(NAME) $(LIBFT) $(GNL) $(OBJ) $(LIBS)

all		:	$(NAME)

clean	:
			make -C mlx clean
			$(RM) $(OBJ)
			$(RM) libmlx.dylib
			$(RM) deepthought.bmp
			make clean -C ./libft
			make clean -C ./get_next_line

fclean	:	clean
			$(RM) $(NAME) $(MLX)
			make fclean -C ./libft
			make fclean -C ./get_next_line

re		:	fclean all

.PHONY	:	all clean fclean re
