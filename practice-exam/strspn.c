#include <unistd.h>
#include <stdio.h>

size_t ft_strspn(char *str, char *accept)
{
	int res = 0;
	int i = 0;
	int j = 0;
	
	while (str[i])
	{
		j = 0;
		res = 0;
		while  (accept[j])
		{
			if (str[i] == accept[j])
				res = 1;
			j++;
		}
		if (res == 0)
			return (i);
		i++;
	}
	return (i);
}

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		printf("Me devuelve: %d\n", ft_strspn(argv[1], argv[2]));
	}
	write(1, "\n", 1);
	return (0);
}
