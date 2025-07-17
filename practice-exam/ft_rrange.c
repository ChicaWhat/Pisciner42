#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int *ft_rrange(int start, int end)
{
	int i = 0;
	int len;

	if (start > end)
		len = start - end + 1;
	else
		len = end - start + 1;

	int *range = malloc(len * sizeof(int));
	while(i < len)
	{
		range[i] = end;
		if (end < start)
			end++;
		else
			end--;
		i++;
	}
	return ((int *)range);
}

int main(void)
{
	int i = 0;
	int *array = ft_rrange(18, 10);
	while (i < 9)
	{
		printf("%i\n", array[i]);
		i++;
	}
	free(array);
	//return (0);
}
