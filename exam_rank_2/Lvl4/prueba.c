#include <stdlib.h>
#include <stdio.h>
typedef struct    s_list
{
    struct s_list *next;
    int          data;
}                 t_list;

void write_word(char *start, char *end)
{
	while(start < end)
	{
		write(1, start , 1);
		start++;
	}
}

int main (int argc, char **argv)
{
	char *str;
	char *start;
	char *end;
	if (argc > 1)
	{
		str = argv[1];
		while (*str == 32 || *str == 9)
			str++;
		start = str;
		while (*str && *str != 32 && *str != 9)
			str++;
		end = str;
		while(*str)
		{
			while (str)
		}
	}
	write (1, "\n" , 1);
}