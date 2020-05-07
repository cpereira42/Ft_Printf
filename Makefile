NAME = libftprintf.a

SRCS = ft_strlen.c ft_strdup.c ft_itoa.c ft_uitoa.c ft_dectohex.c ft_printf.c ft_printf_s.c ft_printf_i.c ft_printf_c.c ft_printf_p.c ft_extra.c

OBJECTS = $(subst .c,.o,$(SRCS))

all: $(NAME)

$(NAME): $(SRCS)
	@gcc -Wall -Wextra -Werror -c $(SRCS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJECTS) 

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re bonus
