NAME	=	libft.a

SRCS	=	personnals_ft/ft_isupper.c	\
			personnals_ft/ft_islower.c	\
			personnals_ft/ft_isblank.c	\
			personnals_ft/ft_isspace.c	\
			personnals_ft/ft_putchar.c	\
			personnals_ft/ft_putstr.c	\
			personnals_ft/ft_putendl.c	\
			personnals_ft/ft_putnbr.c	\
			libc_ft/ft_memset.c		\
			libc_ft/ft_bzero.c		\
			libc_ft/ft_memcpy.c		\
			libc_ft/ft_memccpy.c	\
			libc_ft/ft_memmove.c	\
			libc_ft/ft_memchr.c		\
			libc_ft/ft_memcmp.c		\
			libc_ft/ft_strlen.c		\
			libc_ft/ft_isalpha.c	\
			libc_ft/ft_isdigit.c	\
			libc_ft/ft_isalnum.c	\
			libc_ft/ft_isascii.c	\
			libc_ft/ft_isprint.c	\
			libc_ft/ft_toupper.c	\
			libc_ft/ft_tolower.c	\
			libc_ft/ft_strchr.c		\
			libc_ft/ft_strrchr.c	\
			libc_ft/ft_strncmp.c	\
			libc_ft/ft_strlcpy.c	\
			libc_ft/ft_strlcat.c	\
			libc_ft/ft_strnstr.c	\
			libc_ft/ft_atoi.c		\
			libc_ft/ft_calloc.c		\
			libc_ft/ft_strdup.c		\
			additionals_ft/ft_substr.c		\
			additionals_ft/ft_strjoin.c		\
			additionals_ft/ft_strtrim.c		\
			additionals_ft/ft_split.c		\
			additionals_ft/ft_itoa.c		\
			additionals_ft/ft_strmapi.c		\
			additionals_ft/ft_putchar_fd.c	\
			additionals_ft/ft_putstr_fd.c	\
			additionals_ft/ft_putendl_fd.c	\
			additionals_ft/ft_putnbr_fd.c	\
			bonus_ft/ft_lstnew.c		\
			bonus_ft/ft_lstadd_front.c	\
			bonus_ft/ft_lstsize.c		\
			bonus_ft/ft_lstlast.c		\
			bonus_ft/ft_lstadd_back.c	\
			bonus_ft/ft_lstdelone.c		\
			bonus_ft/ft_lstclear.c		\
			bonus_ft/ft_lstiter.c		\
			bonus_ft/ft_lstmap.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -I.

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			ar rcs -o $(NAME) $(OBJS)

clean	:
			rm -f $(OBJS)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
