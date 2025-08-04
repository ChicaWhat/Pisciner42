#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
		int i = 0;
		char *str = argv[1];
		char c;
		//printf("%d", argc);
		if (argc == 2)
		{
			while (str[i])
			{
					if (str[i] >= 'A' && str[i] <= 'Z')
							c = str[i] + 32;
					else if (str[i] >= 'a' && str[i] <= 'z')
							c = str[i] - 32;
					else
							c = str[i];
					write(1, &c, 1);
					i++;
			}
		}
			write(1, "\n", 1);
			return (0);
}
