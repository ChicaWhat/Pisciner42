#include <unistd.h>

// This program take a string as an argument and prints the first word of that string
// The program first checks if there is 2 arguments. If there is, it then iterates over the characters of the string until it encounters a tab (ASCII 9) or space (32 ASCII). When this part finish, it prints characters until it encounters another tab, space or the end of the string.
int main(int argc, char *argv[])
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while ((argv[1][i] == 9) || (argv[1][i] == 32))
			i++;
		while ((argv[1][i]) && (argv[1][i] != 9) && (argv[1][i] != 32))
		{
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
