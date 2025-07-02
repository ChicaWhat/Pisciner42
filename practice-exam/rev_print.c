#include <unistd.h>


int ft_strlen(char *str)
{
		int i = 0;
		while (str[i])
			i++;
		return (i);
}

void rev_print(char *str)
{
		//int i = 0;
		int len = ft_strlen(str) - 1;
		while (str[len])
		{
			write(1, &str[len], 1);
			len--;
		}
}

int main(int argc, char **argv)
{
		//int i = 0;

		if (argc == 2)
		{
				rev_print(argv[1]);
		}

		write(1, "\n", 1);
		return (0);
}
