#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_isspace(char c)
{
		return (c == 32 || c == '\t');
}

int word_count(char *str)
{
		int i = 0;
		int count = 0;
		while (str[i])
		{
				if (ft_isspace(str[i]))
				{
						i++;
						continue;
				}
				if (str[i] && !ft_isspace(str[i]))
				{
						while (str[i] && !ft_isspace(str[i]))
							i++;
						count += 1;
				}
		}
		return (count);
}

char **ft_split(char *str)
{
		int i = 0;
		int j = 0;
		int a = 0;
		int w_count = word_count(str);
		char **list;
		list = malloc((w_count + 1) * sizeof (char *));
		if (!list)
				return (NULL);
		int count = 0;

		while (str[i])
		{
				if (ft_isspace(str[i]))
				{
						i++;
						continue;
				}
				j = i;
				while (str[i] && !ft_isspace(str[i]))
				{
						i++;
				}
				list[count] = malloc((i - j + 1) * sizeof (char));
				if (!list[count])
						return (NULL);
				a = 0;
				while(j < i)
				{
						list[count][a] = str[j];
						j++;
						a++;
				}
				list[count][j] = '\0';
				count++;
		}
		list[count] = NULL;
		return(list);
}

int main(int ac, char **av)
{
		char **list;
		if (ac != 2)
		{
				write(1, "\n", 1);
				return (1);
		}
		list = ft_split(av[1]);
		for(int i = 0; list[i]; i++)
			printf("%s\n", list[i]);
		return (0);
}
