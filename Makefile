# !--Makefile--

CC = cc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I. -Imatrix -Icolor
LDFLAGS += -lm
SRCS += main.c								\
		info.c								\
		projectile.c						\
		color/color.c						\
		color/canvas.c						\
		matrix/math.c						\
		matrix/tuple.c						\
		matrix/math_utils.c					\
		matrix/tuple_ops_mutable.c			\
		matrix/tuple_ops_immutable.c		\
		matrix/matrix_multiplication.c		
OBJS=$(SRCS:.c=.o)
TARGET=miniRT

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

re: fclean all

run:
	./$(TARGET)

fclean: clean
	rm -f $(TARGET)

clean:
	rm -f $(OBJS)

.PHONY: all re fclean clean
