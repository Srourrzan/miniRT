# !--Makefile--

CC=cc
CFLAGS=-Wall -Wextra -Werror
LDFLAGS+=-lm
SRCS=main.c						\
		info.c					\
		math.c					\
		math_utils.c			\
		tuple.c					\
		tuple_ops_immutable.c	\
		tuple_ops_mutable.c
OBJS=$(SRCS:.c=.o)
TARGET=miniRT

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

re: fclean all

run:
	./$(TARGET)

fclean: clean
	rm -f $(TARGET)

clean:
	rm -f $(OBJS)

.PHONY: all re fclean clean
