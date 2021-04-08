NAME			= cub3D

SRCS			= 	world.c

OBJS			= ${SRCS:.c=.o}

MLX				=  mlx

CC				= gcc
CFLAGS 			= -Wall #-Wextra -Werror
RM				= rm -f

LIBS			= -Lmlx -lmlx -framework OpenGL -framework AppKit -lm
MLX				= libmlx.dylib

NAME			= cub3D

all:			$(NAME)

$(NAME):		$(MLX) $(OBJS)
				gcc ${CFLAGS} -o ${NAME} ${OBJS} ${LIBS}

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

