#include <unistd.h>

int main(int argc, char **argv)
{
	int i = 0;
	char c;
	char *str = argv[1];
	if (argc == 2)
	{
		while (str[i])
		{
			if ((str[i] >= 'A' && str[i] <= 'M') 
					|| (str[i] >= 'a' && str[i] <= 'm'))
				c = str[i] + 13;
			else if ((str[i] >= 'N' && str[i] <= 'Z') 
					|| (str[i] >= 'n' && str[i] <= 'z'))
				c = str[i] - 13;
			else
				c = str[i];
			write(1, &c, 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
