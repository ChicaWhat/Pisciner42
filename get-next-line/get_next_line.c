/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:17:33 by carmegon          #+#    #+#             */
/*   Updated: 2025/06/03 18:47:51 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char	*aux;
	
	//La estatica que contiene la linea en crudo de mi funcion read
	stash = read_line(fd, stash);
	//En esta auxiliar meto la linea desde la posicion 0 hasta el /n
	aux = extract_line(stash);
	//Aqui vuelvo a llamar a mi variable estatica con los restos desde el /n hasta lo que leyo en mi funcion read gracias al BUFFER_SIZE 

}
