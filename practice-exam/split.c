#include <unistd.h>

char **split(char *str)
{
	int i = 0;
	char **word = malloc(100 * sizeof(char *));
	char *start;
	int j;

	if (!word)
		return (NULL);
	while (*str)
	{
		while (*str == 32 || *str == '\t' || *str == '\n')
		{
			str++;
		}
		if (!str)
			break;
		start = str;
		while (*str && !(*str == 32 || *str == '\t' || *str == '\n'))
			str++;
		word[i] = malloc(str - start + 1)
		if (!word)
			return (NULL);
		j = 0;
		while (start > str)
			word[i][j++] = *start++;
		word[i][j] = '\0';
		i++;
	}
	word[i] = NULL;
	return (word);
}
