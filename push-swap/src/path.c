/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:14:53 by carmegon          #+#    #+#             */
/*   Updated: 2025/11/20 17:14:53 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push-swap.h"
// Stack A and stack B make rotate //
void    path1(t_node **stack_a, t_node **stack_b)
{
    t_node  *a;
    t_node  *b;

    a = (*stack_a);
    b = (*stack_b);
    while (1)
    {
        if (a->cost_a > 0 && b->cost_b > 0)
        {
            ft_rr(a, b);
            a->cost_a--;
            b->cost_b--;
        }
        else if (a->cost_a > 0 && b->cost_b == 0)
        {
            ft_ra(a);
            a->cost_a--;
        }
        else if (a->cost_a == 0 && b->cost_b > 0)
        {
            ft_rb(b);
            b->cost_b--;
        }
        else
            ft_pa(b, a);
    }
}
// Stack A and stack b make reverse rotate //
void    path2(t_node **stack_a, t_node **stack_b)
{
    t_node  *a;
    t_node  *b;

    a = (*stack_a);
    b = (*stack_b);
    while (1)
    {
        if (a->cost_a < 0 && b->cost_b < 0)
        {
            ft_rrr(a, b);
            a->cost_a++;
            b->cost_b++;
        }
        else if (a->cost_a == 0 && b->cost_b < 0)
        {
            ft_rrb(b);
            b->cost_b++;
        }
        else if (a->cost_a < 0 && b->cost_b == 0)
        {
            ft_rra(a);
            a->cost_a++;
        }
        else
            ft_pa(b, a);
    }
}
void    path3(t_node **stack_a, t_node **stack_b)
{
    t_node  *a;
    t_node  *b;

    a = (*stack_a);
    b = (*stack_b);
    while (1)
    {
        if (a->cost_a > 0 && b->cost_b < 0)
        {
            ft_ra(a);
            ft_rrb(b);
            a->cost_a--;
            b->cost_b++;
        }
        else if (a->cost_a == 0 && b->cost_b < 0)
        {
            ft_rrb(b);
            b->cost_b++;
        }
        else if (a->cost_a > 0 && b->cost_b == 0)
        {
            ft_ra(a);
            a->cost_a--;
        }
        else
            ft_pa(b, a);
    }
}
void    path4(t_node **stack_a, t_node **stack_b)
{
    t_node  *a;
    t_node  *b;

    a = (*stack_a);
    b = (*stack_b);
    while (1)
    {
        if (a->cost_a < 0 && b->cost_b > 0)
        {
            ft_rra(a);
            ft_rb(b);
            a->cost_a++;
            b->cost_b--;
        }
        else if (a->cost_a == 0 && b->cost_b > 0)
        {
            ft_rb(b);
            b->cost_b--;
        }
        else if (a->cost_a < 0 && b->cost_b == 0)
        {
            ft_rra(a);
            a->cost_a++;
        }
        else
            ft_pa(b, a);
    }
}
