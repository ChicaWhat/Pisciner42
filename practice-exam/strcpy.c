#include <unistd.h>
#include <stdio.h>
#include <string.h>

char *ft_strcpy(char *s1, char *s2)
{
		int i = 0;
		while (s2[i] != '\0')
		{
				s1[i] = s2[i];
				i++;
		}
		s1[i] = '\0';
		return (s1);
}

int main(void)
{
	//int i = 0;
	char s2[5] = "hola";
	char s1[5] = "";
	printf("Mi funcion: %s\n", ft_strcpy(s1, s2));
	printf("Original: %s\n", strcpy(s1, s2));
	return (0);
}
