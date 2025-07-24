#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int i = 1;
	int j = 0;
	char c;
	if (argc == 1)
			write(1, "\n", 1);
	else
			while (i < argc)
			{
					j = 0;
					char *str = argv[i];
					while (str[j] != '\0')
					{
						//Condiciones del bucle que necesito para mis argv
					 
							if (!(str[j] >= 'A' && str[j] <= 'Z') 
									|| !(str[j] >= 'a' && str[j] <= 'z'))
									c = str[j];
							if ((str[j] >= 'a' && str[j] <= 'z') && (str[j - 1] < 33))
									c = str[j] - 32;
							if ((str[j] >= 'A' && str[j] <= 'Z') && (str[j - 1] > 33))
									c = str[j] + 32;
							write(1, &c, 1);
							j++;					 
					}
					write(1, "\n", 1);
					i++;
			}
	return (0);
}
