NAME = libftprintf.a

CC = clang
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_formats.c ft_memcpy.c ft_printf.c ft_printf_nbr.c ft_printf_str.c ft_strdup.c ft_strlen.c ft_itoa.c ft_parse.c ft_printf_chr.c ft_printf_lhex.c ft_printf_ptr.c ft_printf_uhex.c ft_strlcpy.c

OBJS = $(SRCS:.c=.o)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS) $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re