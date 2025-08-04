#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
		int i;
		//char *str[i] = argv[1][i];
		
		if (argc == 4)
		{
				i = 0;
				while (argv[1][i] && argv[2][1] == '\0' && argv[3][1] == '\0')
				{
						if (argv[1][i] == argv[2][0])
								argv[1][i] = argv[3][0];
						write(1, &argv[1][i], 1);
						i++;
				}
		}
		//printf("%d", argc);
		write(1, "\n", 1);
		return (0);
}
