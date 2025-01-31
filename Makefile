NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
	   error.c \
	   map.c \
	   ft_split.c \
	   get_next_line.c \
	   get_next_line_utils.c \
	   valide_map.c \
	   check_path.c

OBJS = $(SRCS:.c=.o)

HEADERS = so_long.h get_next_line.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 