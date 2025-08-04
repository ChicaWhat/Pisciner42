#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int is_space(char c)
{
		//int i = 0;
		if (c == '\t' || c == '\n' || c == ' ')
			return (1);
		return (0);
}

char **ft_split(char *str)
{
		int i = 0;
		int j = 0;
		char *start;
		//char *word = 0;
		char **list = malloc(1000 * sizeof(char *));

		if (!list)
				return (NULL);
		while (*str)
		{
				while (is_space(*str))
					str++;
				start = str;
				while (*str && !(is_space(*str)))
					str++;
				j = 0;
				list[i] = malloc((str - start) + 1 * sizeof(char));
				if (!list)
						return (NULL);
				//j = 0;
				while (start < str)
				{
						list[i][j] = *start++;
						//start++;
						j++;
				}
				list[i][j] = '\0';
				i++;
		}
		list[i] = NULL;
		return (list);
}

int main (int ac, char **av)
{
		//int i = 0;
		char **list = ft_split(av[1]);
		if (ac == 2)
		{
			//char **list = ft_split(av[1]);
			int i = 0;
			while (list[i])
			{
				//ft_split(av[i]);
				printf("Mi array: %s\n", list[i]);
				free (list[i]);
				i++;
			}
		}
		free (list);
		return (0);
}
