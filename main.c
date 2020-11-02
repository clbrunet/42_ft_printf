#include "ft_printf.h"
#include "libft.h"
#include <limits.h>

int		main(void)
{
	int res;
	char	test0[100]		= "|%.2e| ";
	char	nothing1[100]	= "|%e| ";
	char	width2[100]		= "|%25.10e| ";
	char	precision3[100]	= "|%3.50e| ";
	char	same4[100]		= "|%25.25e| ";
	double	f = 0.09004;

	printf("|%.0f|\n", -2.55);
	ft_printf("|%.0f|\n", -2.55);
	printf("\n");
	printf("|%.0f|\n", -3.5);
	ft_printf("|%.0f|\n", -3.5);
	printf("\n");
	printf("|%.0f|\n", -4.5);
	ft_printf("|%.0f|\n", -4.5);
	printf("\n");
	printf("|%.0f|\n", -5.5);
	ft_printf("|%.0f|\n", -5.5);
	printf("\n");
	printf("|%.0f|\n", -5.5);
	ft_printf("|%.0f|\n", -6.5);
	printf("\n");
	printf("|%.0f|\n", -7.5);
	ft_printf("|%.0f|\n", -7.5);
	printf("\n");
	printf("|%.0f|\n", -8.5);
	ft_printf("|%.0f|\n", -8.5);
	printf("\n");
	printf("|%.0f|\n", -9.5);
	ft_printf("|%.0f|\n", -9.5);
	printf("\n");
	printf("|%.0f|\n", -10.5);
	ft_printf("|%.0f|\n", -10.5);
	printf("\n");
	printf("|%.0f|\n", -11.5);
	ft_printf("|%.0f|\n", -11.5);
	printf("\n");
	printf("|%.0f|\n", -12.5);
	ft_printf("|%.0f|\n", -12.5);
	/* printf("----- TEST 0 -----\n"); */
	/* res = printf(test0, f); */
	/* printf("%i\n", res); */
	/* res = ft_printf(test0, f); */
	/* printf("%i\n", res); */
	/* printf("----- TEST 1 -----\n"); */
	/* res = printf(nothing1, f); */
	/* printf("%i\n", res); */
	/* res = ft_printf(nothing1, f); */
	/* printf("%i\n", res); */
	/* printf("----- TEST 2 -----\n"); */
	/* res = printf(width2, f); */
	/* printf("%i\n", res); */
	/* res = ft_printf(width2, f); */
	/* printf("%i\n", res); */
	/* printf("----- TEST 3 -----\n"); */
	/* res = printf(precision3, f); */
	/* printf("%i\n", res); */
	/* res = ft_printf(precision3, f); */
	/* printf("%i\n", res); */
	/* printf("----- TEST 4 -----\n"); */
	/* res = printf(same4, f); */
	/* printf("%i\n", res); */
	/* res = ft_printf(same4, f); */
	/* printf("%i\n", res); */


	/* double	f = 0.09004; */
	/* char	width2[100]		= "|%25.10g| "; */
}
