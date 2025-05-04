/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:01:12 by carmegon          #+#    #+#             */
/*   Updated: 2025/04/30 18:48:49 by carmegon         ###   ########.fr       */
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
	//char d[12] = "NULL";
	//const char f[] = "NULL";
	printf("%s -", (char *)memmove(d, f+2, 4), (char *)ft_memmove(d, f, 4));
	return (0);
} *\

//----ft_strlcpy----//
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
int	main(void)
{
	char	s[] = "AJFgaizaòo035_teo7kk";
	printf("%s --- %s\n", strchr(s, 91), ft_strchr(s, 91));
	return (0);
}
