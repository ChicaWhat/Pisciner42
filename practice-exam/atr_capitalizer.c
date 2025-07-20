#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int i = 1;
	int j = 0;
	int flag = 1;
	char *str = argv[i];
	char c;
	if (argc == 1)
			write(1, "\n", 1);
	else
			while (i < argc)
			{
					j = 0;
					//*str = *argv[i];
					while (str[j] != '\0')
					{
						//Condiciones del bucle que necesito para mis argv
					 
							if (!(str[j] >= 'A' && str[j] <= 'Z') 
									|| !(str[j] >= 'a' && str[j] <= 'z'))
							{
									c = str[j];
							}
							else if ((str[j] >= 'a' && str[j] <= 'z') && (flag))
							{
									c = str[j] - 32;
									flag = 0;
							}
							else if ((str[j] >= 'A' && str[j] <= 'Z') && (flag))
							{
									c = str[j] + 32;
									flag = 1;
							}
							write(1, &c, 1);
							j++;					 
					}
					i++;
			}
	return (0);
}
