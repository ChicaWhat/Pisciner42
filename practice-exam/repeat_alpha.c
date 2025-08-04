#include <unistd.h>

char *repeat_alpha(char *str)
{
	int i = 0;
	int count = 0;
	int repeat;

	while (str[i])
	{
			if (str[i] > 'A' && str[i] <= 'Z')
			{
					count = str[i] - 'A' + 1;
					repeat = count;
					while (repeat > 0)
					{
						write(1, &str[i], 1);
						repeat--;
					}
			}
			else if (str[i] > 'a' && str[i] <= 'z')
			{
					count = str[i] - 'a' + 1;
					repeat = count;
					while (repeat > 0)
					{
						write(1, &str[i], 1);
						repeat--;
					}
			}
			else if (str[i] == 'a')
				write(1, "a", 1);
			else if (str[i] == 'A')
				write(1, "A", 1);
		i++;
	}
	return (str);
}

int main(int argc, char **argv)
{
		if (argc == 2)
			repeat_alpha(argv[1]);
		else
			write(1, "\n", 1);
			
		return (0);
}
