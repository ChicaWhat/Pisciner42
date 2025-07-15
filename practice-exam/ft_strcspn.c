#include <unistd.h>
#include <string.h>
#include <stdio.h>

size_t ft_strcspn(const char *s, const char *reject)
{
	int i = 0;
	int j = 0;

	while (s[i] != '\0')
	{
			j = 0;
			while (reject[j] != '\0')
			{
					if (s[i] == reject[j])
							return (i);
					j++;
			}
			i++;
	}
	return (i);
}

int main(int argc, char **argv)
{
		//int i = 0;
		size_t bytes = ft_strcspn(argv[1], argv[2]);
		if (argc == 3)
			printf("%zu\n", bytes);
		return (0);
}
