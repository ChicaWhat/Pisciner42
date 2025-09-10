#include <stdio.h>

void sort_int_tab(int *tab, unsigned int size)
{
		unsigned int i = 0;
		//int j = 0;
		int aux;
		//int temp;
		if (!tab)
				return;
		while (i < size - 1)
		{
			//temp = tab[i + 1];
			if (tab[i] > tab[i + 1])
			{
					aux = tab[i];
					tab[i] = tab[i + 1];
					tab[i + 1] = aux;
					i = 0;
			}
			else
				i++;
			//j++;
		}
}

int main(void)
{
	int	tab[] = {12, 2, 16, 14};
	int	len = 4;
	int	i = 0;
	
	sort_int_tab(tab, len);
	
	while (i < len)
	{
		printf("%i ", tab[i]);
		i++;
	}
}
