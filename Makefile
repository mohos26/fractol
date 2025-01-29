SRCS = hooks.c utils.c main.c julia.c complex.c mandelbrot.c ft_is_number.c
OBJS = ${SRCS:.c=.o}

SRCSB = bonus/complex_bonus.c bonus/julia_bonus.c bonus/mandelbrot_bonus.c bonus/utils_bonus.c bonus/ft_is_number_bonus.c bonus/hooks_bonus.c bonus/main_bonus.c bonus/tricorn_bonus.c
OBJSB = ${SRCSB:.c=.o}

NAME = fractol
NAME_BONUS = fractol_bonus
libmlx = libmlx.a

all: $(NAME)

$(NAME): ${OBJS}
	cc -lm $^ libmlx.dylib -o $(NAME)

# $(libmlx):
# 	make -sC mlx

bonus: $(NAME_BONUS)

$(NAME_BONUS): ${OBJSB}
	cc $^ -lm libmlx.dylib -o $(NAME_BONUS)

%.o: %.c header.h
	cc -Wall -Wextra -Werror -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJSB)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: clean
