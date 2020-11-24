NAME	=	libftprintf.a

SRCS	=	srcs/ft_printf.c				\
			srcs/convert.c					\
			srcs/specs.c					\
			srcs/specs2.c					\
			srcs/putchar_specs.c			\
			srcs/putstr_specs.c				\
			srcs/hex_utils.c				\
			srcs/putptr_specs.c				\
			srcs/nbr_utils.c				\
			srcs/putnbr_specs.c				\
			srcs/puthex_specs.c				\
			srcs/float_utils.c				\
			srcs/putfloat_specs.c			\
			srcs/exponent_utils.c			\
			srcs/putexponent_specs.c

OBJS	=	$(SRCS:.c=.o)

LIBFT	=	libft/libft.a

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -I./

all		:	$(NAME)

$(LIBFT):
			make bonus -C libft/

$(NAME)	:	$(LIBFT) $(OBJS)
			cp libft/libft.a $(NAME)
			ar rcs $(NAME) $(OBJS)

bonus	:	$(NAME)

clean	:
			make -C libft/ clean
			rm -f $(OBJS)

fclean	:	clean
			make -C libft/ fclean 
			rm -f $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
