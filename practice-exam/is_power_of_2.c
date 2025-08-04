#include <unistd.h>
#include <stdio.h>

int	is_power_of_2(unsigned int n)
{
		return((n & (n-1)) == 0);

}
/*{
		unsigned int i = 1;
		
		while (2*i <= n)
				i *= 2;
		if (i == n)
				return (1);
		return (0);
}*/

int main(void)
{
		unsigned int n = 0;
		printf("%i\n", is_power_of_2(n));
		return (0);

}
