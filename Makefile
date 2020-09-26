NAME	=	libftprintf.a

SRCS	=	srcs/ft_printf.c#	\

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -Iincludes -g -fsanitize=address -L. -lft

all		:	$(NAME)

libft.a	:
			make -C libft/
			cp libft/libft.a .
			cp libft/libft.h includes/

$(NAME)	:	libft.a $(OBJS)
			ar rcs -o $(NAME) libft.a $(OBJS)


main	:	$(NAME)
			$(CC) main.c -L. -lft -lftprintf -Iincludes -g -fsanitize=address

test	:	main
			@echo "=================================================================================\n"
			@./a.out

clean	:
			rm -f $(OBJS) libft.a

fclean	:	clean
			rm -f $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
