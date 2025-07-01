#include <unistd.h>


int ft_strlen(char *str)
{
		int i = 0;
		while (str[i])
		{
				i++;
		}
		return (i);
}

char *rev_print(char *str)
{
		int i = 0;
		int j = 0;
		while (str[i])
		{
			j = ft_strlen(str);
			write(1, &str[i], j--);
			i++;
		}
		return (str);
}

int main(int argc, char **argv)
{
		//int i = 0;

		if (argc == 2)
		{
				rev_print(argv[1]);
		}
		else
				write(1, "\n", 1);
		return (0);
}
