#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int i = 0;
	char *str = argv[1];
	char c;

	if (argc == 2)
	{
			while (str[i])
			{
				if (str[i] >= 'A' && str[i] <= 'M')
				{
						c = 'Z' - (str[i] % 'A');
						//printf("%s\n", &c);
				}
				else if (str[i] >= 'N' && str[i] <= 'Z')
						c = 'Z' - (str[i] % 'A');
				else if (str[i] >= 'a' && str[i] <= 'm')
						c = 'z' - (str[i] % 'a');
				else if (str[i] >= 'n' && str[i] <= 'z')
						c = 'z' - (str[i] % 'a');
				else
						c = str[i];
				write(1, &c, 1);
				i++;
			}
	}
	write(1, "\n", 1);
	return (0);
}
