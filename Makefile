NAME	=	libftprintf.a

SRCS	=	srcs/ft_printf.c				\
			srcs/convert.c					\
			srcs/specs.c					\
			srcs/putchar_specs.c			\
			srcs/putstr_specs.c				\
			srcs/nbr_utils.c				\
			srcs/putnbr_specs.c				\
			srcs/puthex_specs.c				\
			srcs/float_utils.c				\
			srcs/putfloat_specs.c			\
			srcs/putcompactfloat_specs.c	\
			srcs/putexponent_specs.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -Iincludes -L. -lft -g

all		:	$(NAME)

libft.a	:
			make -C libft/
			cp libft/libft.a .
			cp libft/libft.h includes/

$(NAME)	:	libft.a $(OBJS)
			cp libft.a $(NAME)
			ar rcs -o $(NAME) $(OBJS)


main	:	$(NAME)
			$(CC) -static main.c debug.c -L. -lftprintf -Iincludes -g

test	:	main
			@echo "=================================================================================\n"
			@./a.out

clean	:
			make -C libft/ clean
			rm -f $(OBJS)

fclean	:	clean
			make -C libft/ fclean 
			rm -f $(NAME) libft.a includes/libft.h

re		:	fclean all

.PHONY	:	all clean fclean re
