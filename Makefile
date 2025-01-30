NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a
MLX_DIR = minilibx-linux/
MLX = $(MLX_DIR)libmlx.a
HEADER = fractol.h
MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib -lX11 -lXext -lm

SRC = main.c ft_render.c ft_events.c \
		ft_math_utils.c ft_init.c ft_utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT) $(MLX) $(MLX_FLAGS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)


clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)


fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)


re: fclean all

.PHONY: all clean fclean re
