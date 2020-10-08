#include "ft_printf.h"
#include "libft.h"
#include <limits.h>

int		main(void)
{
	int res;
	char	test0[100]		= "%-#22X|\n";
	char	nothing1[100]	= "%-#X|\n";
	char	width2[100]		= "%-#25.6X|\n";
	char	precision3[100]	= "%-#3.25X|\n";
	char	same4[100]		= "%-#25.25X|\n";
	int		i2				= 0;

	printf("----- TEST 0 -----\n");
	ft_putchar('|');
	res = printf(test0, i2);
	printf("%i\n", res);
	ft_putchar('|');
	res = ft_printf(test0, i2);
	printf("%i\n", res);
	printf("----- TEST 1 -----\n");
	ft_putchar('|');
	res = printf(nothing1, i2);
	printf("%i\n", res);
	ft_putchar('|');
	res = ft_printf(nothing1, i2);
	printf("%i\n", res);
	printf("----- TEST 2 -----\n");
	ft_putchar('|');
	res = printf(width2, i2);
	printf("%i\n", res);
	ft_putchar('|');
	res = ft_printf(width2, i2);
	printf("%i\n", res);
	printf("----- TEST 3 -----\n");
	ft_putchar('|');
	res = printf(precision3, i2);
	printf("%i\n", res);
	ft_putchar('|');
	res = ft_printf(precision3, i2);
	printf("%i\n", res);
	printf("----- TEST 4 -----\n");
	ft_putchar('|');
	res = printf(same4, i2);
	printf("%i\n", res);
	ft_putchar('|');
	res = ft_printf(same4, i2);
	printf("%i\n", res);
}
