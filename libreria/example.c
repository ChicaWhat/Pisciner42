/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:01:12 by carmegon          #+#    #+#             */
/*   Updated: 2025/05/12 12:35:22 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <bsd/string.h>
// Aqui llamo a la biblioteca que estoy creando
#include "libft.h"

//----ft_memmove----//

/* int	main(void)
{
        char d[] = "Hola buenos dias";
        const char f[] = "Que tal estamos mi gente";
        printf("%s\n", (char *)ft_memmove(d+3, f+2, 5));
        return (0);
} 
*\

/----ft_strlcpy----/
int	main(void)
{
	char d[] = "Hola buenos dias, hoy me siento bien";
	char src[]= "Que será, será";

	printf("%s --- %s\n", d, src);
	printf("%zu\n", ft_strlcpy(d, src, 7));
	printf("%s --- %s\n", d, src);
	return (0);
}*/
//-----ft_strlcat-----//
/* int	main(void)
{
	char d[] = "db++ç´RTHe__66";
	char f[] = "M0jSDKG";

	printf("%zu\n", 
	ft_strlcat(d, f, 5));
	return (0);
}*/

//-----ft_strchr-----//
/* int	main(void)
{
	char	s[] = "AJFgaizaòo035_teo7kk";
	printf("%s --- %s\n", strchr(s, 91), ft_strchr(s, 91));
	return (0);
} */
//-----(ft_strnstr)
/* int	main(void)
{
	char	*big = "Hola mundo cruel";
	char	*little = "";
	printf("%s\n", ft_strnstr(big, little, 17));
	return (0);
} */
//-----(ft_substr)----//
/* int	main(void)
{
	char	s[] = "Hola mundo cruel peperoni";
	char	*sub_s = ft_substr(s, 36, 3);
	printf("%s\n", sub_s);
	free(sub_s);
	return (0);
} */

/* 
//----- (ft_strjoin) -------//
int     main(void)
{
        char    s1[] = "Que pasara que misterios habra ";
        char    s2[] = "puede ser mi gran noche, tan tantan taaan";
        char    *new_s = ft_strjoin(s1, s2)
        printf("%s",new_s);
        free (new_s)
        return (0);
}*/

//----- (ft_split) -------//

/* int	main(void)
{
	char	s1[] = "Hola buenos dias";
	char	**list = ft_split(s1, 32);
	int	i = 0;
	
	while (*list[i])
	{
		printf("%s\n", &*list[i]);
		i++;
	}
	return (0);
} */
//------- (ft_itoa) ------//
/* 
	int main(void)
{
  int num = -4583;
  int result = ft_count_numbers(num);
  char *itoa = ft_itoa(-4583);
  printf("%d\n %s", result, itoa);
  return (0);
}
*/
//--------- (ft_strmapi) --------//
/* 
char  my_upper(unsigned int i, char c)
{
	if (i % 2 == 0)
	{
		return (toupper(c));
	}
	else
    	return (c);
}	
int main(void)
{
	char s[] = "Hola mi loca";
	int i = 0;
	char *new_s = ft_strmapi(s, my_upper);
  printf("%s - Original\n", s);
  printf("%s - Modificada", new_s);
  return (0);
}
*/

//------ (ft_atoi) -------//
/* 
int     main(void)
{
        char    nptr[] = "   -653 -79++-40hb224";
        int     result = ft_atoi(nptr);
        printf("Este es mi numer: %d", result);
        return (0);
}
/*

/* 
//------ (ft_strrchr) ------//
int	main(void)
{
	char	s[] = "Hola buenos dias hoy me siento bien";
	int	c = 117;
	char	*result = ft_strrchr(s, c);
	printf("%s", result);
	return (0);
}

*/
