NAME = fract-ol
SRCS =	sources/core/main.c\
		sources/core/fractal.c\
		sources/core/draw.c\
		sources/fractals/julia.c\
		sources/fractals/mandelbrot.c\
		sources/controls/event.c\
		sources/controls/mouse_event.c\
		sources/colors/HSV.c\
		sources/colors/ARGB.c\
		sources/colors/color.c



OBJS = ${SRCS:.c=.o}
LIBFT = ./libft
CFLAGS = -Werror -Wall -Wextra
LIBFTFLAGS = -L $(LIBFT) -lft
MLX = ./mlx
MLXFLAGS = -I $(MLX) -L $(MLX) -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	make -C $(MLX)
	$(CC) $(OBJS) $(LIBFTFLAGS) $(MLXFLAGS) -o $(NAME)
clean:
	rm -rf ${OBJS}
fclean : clean
	make fclean -C $(LIBFT)
	rm -rf ${NAME}
re: all fclean

.PHONY: re fclean clean all