NAME			= cub3D

SRCS		= 	main.c \
				raycasting.c \
				utils.c \
				keys.c \
				ft_strchr.c \

OBJS			= ${SRCS:.c=.o}


MLX				=  mlx

CC				= gcc
CFLAGS 			= -Wall #-Wextra -Werror
RM				= rm -f

MINILIBX		= -Lmlx -lmlx -framework OpenGL -framework AppKit -lm
MLX				= libmlx.dylib

NAME			= prove

all:			$(NAME)

$(NAME):		$(MLX) $(OBJS)
				gcc ${CFLAGS} -o ${NAME} ${OBJS} ${MINILIBX}

$(MLX):
				@$(MAKE) -C mlx
				@mv mlx/$(MLX) .

clean:
				@$(MAKE) -C mlx clean
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME) $(MLX)

re:				fclean $(NAME)

.PHONY:			all clean fclean re

