#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
		int i = 0;
		//int j = 0;
		//int len;
		//char c = argv[1][i];
		
		//while (argv[1][i] != '\0')
		//		i++;
		//len = i;
		//argv[1] = malloc(len + 1 * sizeof(char *));
		//argv[1][len + 1] = '\0';
		if (argc == 2)
		{
				while (argv[1][i] != '\0')
				{
					if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
					{
							argv[1][i] += 32;
							write(1, "_", 1);
							//i++;
							//argv[1][i] += 32;
							write(1, &argv[1][i], 1);
					}
					else
							write(1, &argv[1][i], 1);
					i++;
				}
		}
		write(1, "\n", 1);
		return (0);
}
