#include "ft_printf.h"
#include "libft.h"
#include <limits.h>


int		main(void)
{
	char	format[1000] = "|%-5.i|\n";
	char	format2[1000] = "|%-0 10.3i|\n";
	char	format3[1000] = "|%0-3.189i|\n";
	char	format4[1000] = "|% -10.10i|\n";
	char	c1 = '\t';
	char	*s1 = "Hello w";
	int		i1 = 37;
	int		i2 = 5;
	int		i3 = 123456789;
	double	d1 = 4.1234567;
	printf("-----TEST 1-----\n");
	printf(format, i1);
	ft_printf(format, i1);
	printf("-----TEST 2-----\n");
	printf(format2, i1);
	ft_printf(format2, i1);
	printf("-----TEST 3-----\n");
	printf(format3, i1);
	ft_printf(format3, i1);
	printf("-----TEST 4-----\n");
	printf(format4, i1);
	ft_printf(format4, i1);
}
