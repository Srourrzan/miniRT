# !--Makefile--

CC = cc
CFLAGS = -Wall -Wextra -Werror -g #-std=c99
CPPFLAGS = -I. -Imatrix -Icolor -IMLX42/include
LDFLAGS = -lmlx42 -lm -ldl -lglfw -pthread -Lbuild
SRCS += main.c								\
		info.c								\
		hooks.c								\
		window.c							\
		projectile.c						\
		color/color.c						\
		color/canvas.c						\
		color/color_operations.c			\
		matrix/math.c						\
		matrix/tuple.c						\
		matrix/sub_matrix.c					\
		matrix/math_utils.c					\
		matrix/minor_matrix.c				\
		matrix/matrix_cofactor.c			\
		matrix/matrix_comparison.c			\
		matrix/matrix_operations.c			\
		matrix/tuple_ops_mutable.c			\
		matrix/matrix_determinant.c			\
		matrix/tuple_ops_immutable.c		\
		matrix/matrix_initialization.c		\
		matrix/matrix_multiplication.c		
OBJS=$(SRCS:%.c=build/%.o)
TARGET=miniRT

ifeq ($(MAT), 1)
	CFLAGS += -DMAT
endif

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

run: ./$(TARGET)
	@./$(TARGET) $(ARGS)

fclean: clean
	rm -f $(TARGET)

clean:
	rm -f $(OBJS)

.PHONY: all re fclean clean MLX42 run
