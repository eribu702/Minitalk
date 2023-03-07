NAME	= libftprintf.a

SRCS	= ft_printf.c \
			ft_putstr.c \
			ft_putnbr.c \
			ft_putchar.c \
			ft_unint.c \
			ft_hex.c \
			ft_point.c \
			ft_atoi.c \
			ft_isdigit.c \
			ft_strlen.c \

OBJS	= $(SRCS:.c=.o)

CC		= gcc

RM		= rm -f

all:	$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
