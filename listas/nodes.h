#ifndef	NODES_H
# define NODES_H

# include <unistd.h>
# include <stdio.h>

typedef struc s_node
{
		struct s_node	*next;
		void			*data;
}						t_node;

t_node	*ft_find(t_node *nodes);

#endif


