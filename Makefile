NAME	=	libftprintf.a

SRCS	=	srcs/ft_printf.c	\
			srcs/convert.c		\
			srcs/specs.c		\
			srcs/putnbr_specs.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -Iincludes -L. -lft

all		:	$(NAME)

libft.a	:
			make -C libft/
			cp libft/libft.a .
			cp libft/libft.h includes/

$(NAME)	:	libft.a $(OBJS)
			cp libft.a $(NAME)
			ar rcs -o $(NAME) $(OBJS)


main	:	$(NAME)
			$(CC) main.c debug.c -L. -lftprintf -Iincludes

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