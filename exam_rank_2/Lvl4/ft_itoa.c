#include <unistd.h>
#include <stdlib.h>

char *ft_itoa (int nbr)
{
	char *result;
	int n;
	n = nbr;
	int len = 0;

	if (nbr == -2147483648)
		return ("-2147483648\0");
	if (n < 0)
		len++;
	while (n)
	{
		len++;
		n = n / 10;
	}
	result = malloc(sizeof(char)*(len + 1));
	if (!result)
		return NULL;
	result[len] = '\0';
	if (nbr == 0)
	{
		result[0] = '0';
		return (result);
	}
	if (nbr < 0)
	{
		nbr = -nbr;
		result[0] = '-';
	}
	while (nbr)
	{
		result[--len] = nbr % 10 + '0';
		nbr /=10;
	}
	return result;
}
