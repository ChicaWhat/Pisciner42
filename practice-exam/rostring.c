#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int ft_isspace(char c)
{
	return(c == 32 || c == '\t');
}

int ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return (i);
}

int word_count(char *str)
{
	int i = 0;
	int count = 0;
	while (str[i])
	{
		while (ft_isspace(str[i]))
			i++;
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
	int w_count = ft_strlen(str);
	int k; 
	char **list;
	int count = 0;
	list = malloc((w_count + 1) * sizeof (char *));
	while (str[i])
	{
		while (str[i] && ft_isspace(str[i]))
			i++;
		j = i;
		while (str[i] && !ft_isspace(str[i]))
			i++;
		list[count] = malloc((i - j + 1) * sizeof (char));
		k = 0;
		while (j < i)
		{
			list[count][k] = str[j];
			j++;
			k++;
		}
		list[count][k] = '\0';
		count++;
	}
	list[count] = '\0';
	return (list);
}
#include <stdio.h>
int main(int ac, char **av)
{
	int i = 1;
	int w_count = word_count(av[1]);
	char **split = ft_split(av[1]);
	if (ac == 1)
	{
		write(1, "\n", 1);
		return (1);
	}
	while (i < w_count && split[i] && split)
	{
		write(1, split[i], ft_strlen(split[i]));
		write(1, " ", 1);
		free(split[i]);
		i++;
	}
	if (split[0])
	{
		write(1, split[0], ft_strlen(split[0]));
		free(split[0]);
	}
	write(1, "\n", 1);
	free(split);
	return (0);
}
