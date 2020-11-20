#include "ft_printf.h"
#include "libft.h"
#include <limits.h>

int		main(void)
{
	int res;
	char	nothing1[100]	= "|%i| ";
	char	width2[100]		= "|%25.10i| ";
	char	precision3[100]	= "|%3.50i| ";
	char	same4[100]		= "|%25.25i| ";
	char	test5[100]		= "|%.2i| ";
	int f = -236;

	printf("----- TEST 1 -----\n");
	res = printf(nothing1, f);
	printf("%i\n", res);
	res = ft_printf(nothing1, f);
	printf("%i\n", res);
	printf("----- TEST 2 -----\n");
	res = printf(width2, f);
	printf("%i\n", res);
	res = ft_printf(width2, f);
	printf("%i\n", res);
	printf("----- TEST 3 -----\n");
	res = printf(precision3, f);
	printf("%i\n", res);
	res = ft_printf(precision3, f);
	printf("%i\n", res);
	printf("----- TEST 4 -----\n");
	res = printf(same4, f);
	printf("%i\n", res);
	res = ft_printf(same4, f);
	printf("%i\n", res);
	printf("----- TEST 5 -----\n");
	res = printf(test5, f);
	printf("%i\n", res);
	res = ft_printf(test5, f);
	printf("%i\n", res);
}
