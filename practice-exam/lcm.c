#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

unsigned int lcm(unsigned int a, unsigned int b)
{
		unsigned int i = 1;
		//unsigned int j = 0;
		unsigned int max;
		unsigned int mult = 1;
		unsigned int min;

		if (a == 0 || b == 0)
				return (0);

		if (a > b)
		{
				max = a;
				min = b;
		}
		else
		{
				max = b;
				min = a;
		}

		while (mult % min != 0)
		{
			mult = max * i;
			if (mult % min == 0)
					break;
			i++;
		}
		return (mult);
}

int main(void)
{
		unsigned int a = 15;
		unsigned int b = 12;
		printf("%d", lcm(a, b));
		return (0);
}
