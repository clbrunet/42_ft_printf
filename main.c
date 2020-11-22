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
	int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";

	printf("-- %d --\n", printf("%*.*i1m4%.1xPKUqgM0GHn%5.3sX%X%07.5X", -3, 2, 0, 4838126, "vrk3ltILPwh25cjf98grtvlxgARhxSaospkQl 1iv2dqnPQZN36q4xf3GdNIadH F27GFYRjCurfEo9h8O1GU7nEG", 2147483647, 0));
	ft_printf("-- %d --\n", ft_printf("%*.*i1m4%.1xPKUqgM0GHn%5.3sX%X%07.5X", -3, 2, 0, 4838126, "vrk3ltILPwh25cjf98grtvlxgARhxSaospkQl 1iv2dqnPQZN36q4xf3GdNIadH F27GFYRjCurfEo9h8O1GU7nEG", 2147483647, 0));
	/* printf("----- TEST 1 -----\n"); */
	/* res = printf(nothing1, u); */
	/* printf("%i\n", res); */
	/* res = ft_printf(nothing1, u); */
	/* printf("%i\n", res); */
	/* printf("----- TEST 2 -----\n"); */
	/* res = printf(width2, u); */
	/* printf("%i\n", res); */
	/* res = ft_printf(width2, u); */
	/* printf("%i\n", res); */
	/* printf("----- TEST 3 -----\n"); */
	/* res = printf(precision3, u); */
	/* printf("%i\n", res); */
	/* res = ft_printf(precision3, u); */
	/* printf("%i\n", res); */
	/* printf("----- TEST 4 -----\n"); */
	/* res = printf(same4, u); */
	/* printf("%i\n", res); */
	/* res = ft_printf(same4, u); */
	/* printf("%i\n", res); */
	/* printf("----- TEST 5 -----\n"); */
	/* res = printf(test5, u); */
	/* printf("%i\n", res); */
	/* res = ft_printf(test5, u); */
	/* printf("%i\n", res); */
}
