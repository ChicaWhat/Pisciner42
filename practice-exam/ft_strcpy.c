#include <stdio.h>
#include <unistd.h>

char	*ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i] != '\0')
	{
			s1[i] = s2[i];
			i++;
	}
	s1[i] = '\0';
	return (s1);
}

/* int	main(void)
{
		char	s1[5] = "Mun";
		char	s2[15] = "Hola me muero";
		char	*result;

		result = ft_strcpy(s1, s2);
		printf("%s\n", result);
		return (0);
} */
