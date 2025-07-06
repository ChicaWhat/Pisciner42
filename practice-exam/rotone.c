#include <unistd.h>

int main(int argc, char **argv)
{
		int i = 0;
		char *str = argv[1];
		char c;
		if (argc == 2)
		{
			while (str[i])
			{
				if ((str[i] >= 'A' && str[i] <= 'Y') 
						|| (str[i] >= 'a' && str[i] <= 'y'))
						c = str[i] + 1;
				else if ((str[i] == 'Z') || (str[i] == 'z'))
						c = str[i] - 25;
				else
						c = str[i];
				write(1, &c, 1);
				i++;
			}
		}
		write(1, "\n", 1);
		return (0);
}
