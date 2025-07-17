#include <unistd.h>

int main(int argc, char **argv)
{
	int i = 0;
	char *num = argv[1];
	int digit = 0;
	if (argc == 2)
	{
		while (num[i])
		{
			digit = num / 10;
			digit = digit * 10 + (num[i] - '0');
			i++;
		}
		//if (num <= 1)
			//return (0);
	}
}
