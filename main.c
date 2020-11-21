#include "ft_printf.h"
#include "libft.h"
#include <limits.h>

int		main(void)
{
	/* TODO hu hx hhu hhx */
	int res;
	char	nothing1[100]	= "|%hhu| ";
	char	width2[100]		= "|%-25.10hhu| ";
	char	precision3[100]	= "|%-3.50hhu| ";
	char	same4[100]		= "|%-25.25hhu| ";
	char	test5[100]		= "|%hhu| ";
	unsigned char u = 255;

	/* printf("|%.hhx|\n", x); */
	/* ft_printf("|%.hhx|\n", x); */
	printf("----- TEST 1 -----\n");
	res = printf(nothing1, u);
	printf("%i\n", res);
	res = ft_printf(nothing1, u);
	printf("%i\n", res);
	printf("----- TEST 2 -----\n");
	res = printf(width2, u);
	printf("%i\n", res);
	res = ft_printf(width2, u);
	printf("%i\n", res);
	printf("----- TEST 3 -----\n");
	res = printf(precision3, u);
	printf("%i\n", res);
	res = ft_printf(precision3, u);
	printf("%i\n", res);
	printf("----- TEST 4 -----\n");
	res = printf(same4, u);
	printf("%i\n", res);
	res = ft_printf(same4, u);
	printf("%i\n", res);
	printf("----- TEST 5 -----\n");
	res = printf(test5, u);
	printf("%i\n", res);
	res = ft_printf(test5, u);
	printf("%i\n", res);
}
