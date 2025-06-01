/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:37:08 by carmegon          #+#    #+#             */
/*   Updated: 2025/05/31 19:37:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    /* 
        - Hacerme un char *ptr
        - Crear una variable ssize_t (para poder manejar los negativos en caso de error. El size_t normal no maneja los negaitvos)
        - En esta variable ssize_t hago el llamado a mi funcion read- Read recibe 3 parametros: 1. fd 2. mi puntero *ptr 3. Cantidad de bytes que leeré (buufer_size)
        - Reserva el espacio de memoria (malloc)
    */
}
