NAME = libftprintf.a
SOURCES = \
	ft_support_char.c \
	ft_support_dig.c \
	ft_printf.c \

OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
