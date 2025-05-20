/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:15:13 by carmegon          #+#    #+#             */
/*   Updated: 2025/05/19 17:20:05 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Add the new node at the beginning of the 'list'
#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
		new->next = lst[0];
	lst[0] = new;
}
