/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:33:22 by carmegon          #+#    #+#             */
/*   Updated: 2025/02/06 11:46:06 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;
	i = 0;
	while(str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	main(void)
{
// Declaro una variable de tipo char que va a ser un puntero de str
	char	*str;
// la variable va a contener la cadena de caracteres "PACHURU"
	str = "PACHURU";
// le pido a la función write que me apunte al array del str y pongo en los corchetes un 0, porque esa es la primera posición del caracter "P" y eso es lo que me va a devolver el write: solo la "P".
	write(1, &str[0], 1);
// llamo a mi función principal con el parametro str para que me haga el bucle de la cadena de caracteres. Esto me imprimirá "PACHURU"
	ft_putstr(str);
	return (0);
}
