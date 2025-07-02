#include <unistd.h>

void rot_13(char *str)
{
		int i = 0;
		char c;
		while (str[i])
		{
				if ((str[i] >= 'A' && str[i] <= 'M') 
						|| (str[i] >= 'a' && str[i] <= 'M'))
				{
					c = str[i] + 13;
					write(1, &c, 1);
				}
				else if ((str[i] >= 'N' && str[i] <= 'Z') 
						|| (str[i] >= 'n' && str[i] <= 'z'))
				{
						c = str[i] - 13;
						write(1, &c, 1);
				}
				i++;
		}
}

int	main(int argc, char **argv)
{
	//int i = 0;
	if (argc == 2)
		rot_13(argv[1]);
	write(1, "\n", 1);
	return (0);
}
