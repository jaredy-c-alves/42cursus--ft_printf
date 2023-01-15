NAME = libftprintf.a

MAIN = ft_printf.c
UTLS = utils/ft_print_chr.c utils/ft_print_str.c utils/ft_print_addr.c utils/ft_print_nbr.c utils/ft_print_hex.c
OBJS = $(MAIN:.c=.o) $(UTLS:.c=.o)

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
