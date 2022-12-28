NAME = libftprintf.a

SRCS = ft_printf.c ft_printf_utils.c ft_print_chr.c
OBJS = $(SRCS:.c=.o)

AR = ar rcs

CC = cc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -o $(@) -c $(<)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
