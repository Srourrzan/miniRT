# !--Makefile--

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -std=c99
CPPFLAGS = -I. -Imatrix -Icolor -IMLX42/include
LDFLAGS = -lmlx42 -lm -ldl -lglfw -pthread -Lbuild
SRCS += main.c								\
		info.c								\
		window.c							\
		projectile.c						\
		color/color.c						\
		color/canvas.c						\
		matrix/math.c						\
		matrix/tuple.c						\
		matrix/math_utils.c					\
		matrix/tuple_ops_mutable.c			\
		matrix/tuple_ops_immutable.c		\
		matrix/matrix_multiplication.c		
OBJS=$(SRCS:%.c=build/%.o)
TARGET=miniRT

all: MLX42 $(TARGET)

MLX42:
	@cmake -S MLX42 -B build -Wno-dev
	@cmake --build build -j4
	@echo "MLX42 is built"

$(TARGET): $(OBJS)
	@$(CC) -o $@ $^ $(LDFLAGS)
	@echo "miniRT is built"

build/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

re: fclean all

run:
	@./$(TARGET)

fclean: clean
	rm -f $(TARGET)

clean:
	rm -f $(OBJS)

.PHONY: all re fclean clean MLX42
