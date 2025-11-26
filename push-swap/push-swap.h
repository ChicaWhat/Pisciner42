/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push-swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:43:56 by carmegon          #+#    #+#             */
/*   Updated: 2025/11/26 14:03:24 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"
# include <limits.h>

/************************************************/
/*              Estructura de los nodos         */
/************************************************/

typedef struct s_node
{
	long			num;
	int				index;
	int				pos;
	int				size;
	int				cost_a;
	int				cost_b;
	int				total_cost;
	int				cheapest;
	long			target;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;


int		ft_digit_space(char c);
int		ft_sign(char *str);
int		ft_no_repeat(char **list);
int		is_order(char **list);
long	ft_atol(char *str);
char	*ft_one_argv(char **av);
char	**ft_split_argv(char *one_av);
int		ft_is_valid(int ac, char **av);
void	ft_parsing(int ac, char **av);
void	ft_error(void);
void	*ft_free_all(char **list, char *str, t_node **node);
long	*ft_convert_to_long_array(char **list, int size);
t_node	*create_stack(long *list_num, int size);
t_node	*init_stack(char **av);
int		list_size(char **list_num);
void	ft_swap(t_node **stack);
void	ft_sa(t_node **a);
void	ft_sb(t_node **b);
void	ft_ss(t_node **a, t_node **b);
void	ft_push(t_node **stack_dest, t_node **stack_src);
void	ft_pa(t_node **b, t_node **a);
void	ft_pb(t_node **a, t_node **b);
void	ft_ra(t_node **a);
void	ft_rb(t_node **b);
void	ft_rr(t_node **a, t_node **b);
void	ft_rra(t_node **a);
void	ft_rrb(t_node **b);
void	ft_rrr(t_node **a, t_node **b);
long	*ft_order_long(long *list_num, int size);
void	ft_index_nodes(long *list_num, int size, t_node **stack);
int		stack_size(t_node **stack);
void	set_positions(t_node **stack_a);
t_node  *push_swap(char **av);
void	order_two_nodes(t_node **stack);
void	order_three_nodes(t_node **stack_a);
void	order_nodes(t_node **stack_a, int size);
void	move_stacks(t_node **stack_a, t_node **stack_b, int size);
void	cost_a(t_node **stack_a);
void	cost_b(t_node **stack_b);
void	set_target(t_node **a, t_node *node_b);
void	set_all_targets(t_node **stack_a, t_node **stack_b);
void	total_cost(t_node **stack_a, t_node **stack_b);
void	set_total_cost(t_node **stack_a ,t_node **stack_b);
t_node	*cheapest_node(t_node **stack_b);
void	path1(t_node **stack_a, t_node **stack_b, t_node *cheapest);
void	path2(t_node **stack_a, t_node **stack_b, t_node *cheapest);
void	path3(t_node **stack_a, t_node **stack_b, t_node *cheapest);
void	path4(t_node **stack_a, t_node **stack_b, t_node *cheapest);
void	four_possibilities(t_node **stack_a, t_node **stack_b, t_node **cheapest);
void	make_sort(t_node **stack_a, t_node **stack_b, int size);
void	last_moves(t_node **stack_a, int size);
t_node	*find_min_node(t_node **stack_a);

t_node	*print_nodes(t_node *node);

#endif