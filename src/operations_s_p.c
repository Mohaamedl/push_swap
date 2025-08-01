/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_s_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddadi <mhaddadi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 21:52:16 by mhaddadi          #+#    #+#             */
/*   Updated: 2025/07/11 21:52:53 by mhaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/push_swap.h"
#inlude "../libft/libft.h"

t_node	*pa(t_stack *a, t_stack *b)
{
	t_node	*push_node;
	if (!a || !b || b -> size == 0)
		return (0);
	push_node =  pop(b);
	if (!push_node)
		return (NULL);
	if (push(a,push_node) != 1)
		return (NULL);
	printf("pa%s\n","");
	return (push_node);
}

t_node	*pb(t_stack *a, t_stack *b)
{
	t_node	*push_node;
	if (!a || !b || a -> size == 0)
		return (0);
	push_node =  pop(a);
	if (!push_node)
		return (NULL);
	if (push(b,push_node) != 1)
		return (NULL);
	printf("pb%s\n","");
	return (push_node);
	
}

int		sa(t_stack *a)
{
	if(a -> size < 2)
		return (0);
	swap_top_two(a);
	printf("sa%s\n","");
	return (1);
}

int		sb(t_stack *b)
{
	if(b -> size < 2)
		return (0);
	swap_top_two(b);
	printf("sb%s\n","");
	return (1);

}
