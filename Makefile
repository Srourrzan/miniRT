# !--Makefile--

CC = cc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I. -Imatrix
LDFLAGS += -lm
SRCS += main.c								\
		info.c								\
		color.c								\
		projectile.c						\
		matrix/math.c						\
		matrix/math_utils.c					\
		matrix/tuple.c						\
		matrix/tuple_ops_immutable.c		\
		matrix/tuple_ops_mutable.c			\
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
