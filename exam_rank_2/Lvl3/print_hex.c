#include <unistd.h>


int ft_atoi (char *str)
{
	int n = 0;
	while (*str != '\0')
	{
		n = n * 10;
		n = n + *str - '0';
		++str;
	}
	return n;
}

void ft_hex (int n)
{
	char c;
	if (n > 15)
		ft_hex(n / 16);
	n = n % 16;
	if (n < 10)
	{
		c = n + '0';
		write (1, &c, 1);
	} else
	{
		c = 'a' + n - 10;
		write(1, &c,1);
	}

}
int main (int argc, char **argv)
{
	if (argc == 2)
		ft_hex(ft_atoi(argv[1]));
	write (1, "\n",1);
	return 0;
}
