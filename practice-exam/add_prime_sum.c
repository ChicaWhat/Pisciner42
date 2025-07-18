#include <unistd.h>

int main(int argc, char **argv)
{
	int i = 0;
	int n = 2;
	char *num = argv[1];
	int digit = 0;
	if (argc == 2)
	{
		while (num[i] >= '0' && num[i] <= '9')
		{
			digit = (digit * 10) + (num[i] - '0');
			i++;
		}
		if (digit <= 1)
			return (0);
		
	}
}
