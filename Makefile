CC = cc
BUFFER_SIZE = 4546
FILE = readme.md
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=$(BUFFER_SIZE)
CFLAGSG = -Wall -Wextra -Werror -g -D BUFFER_SIZE=$(BUFFER_SIZE)
NAME = gnl
SRCS = get_next_line.c get_next_line_utils.c main.c
RM = rm -f

all: $(NAME)
	./$(NAME) $(FILE)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

debug:
	$(CC) $(CFLAGSG) $(SRCS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all
