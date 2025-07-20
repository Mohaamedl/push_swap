/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddadi <mhaddadi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:01:07 by mhaddadi          #+#    #+#             */
/*   Updated: 2025/07/10 17:41:32 by mhaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	sort_three(t_stack *stack)
{
	int	n1;
	int	n2;
	int	n3;

	n3 = stack -> head -> value;
	n2 = stack -> head -> next -> value;
	n1 = stack -> head -> next -> next -> value;
	if (n3 < n2 && n3 > n1)
		sa(stack);
	else if (n1 > n2 && n2 >n3)
	{
		ra(stack);
		sa(stack);
	}
	else if (n1 < n3 && n1 > n2)
	{
		rra(stack);
		sa(stack);
	}
	else if (n1 > n3 && n3 > n2)
		rra(stack);
	else if (n2 > n1 && n1 > n3)
		ra(stack);
	return (0);
}

void	index_zero(t_stack *a, t_stack *b)
{
	rra(a, b);
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

int		sort_four(t_stack *a, t_stack *b)
{
	int		max_index;

	max_index = find_max(a);
	if (max_index == 0)
	{
		index_zero(a, b);
	}
	else if (max_index == 1)
	{
		rra(a);
		index_zero(a, b);
	}
	else if (max_index == 2)
	{
		ra(a, b);
		pb(a, b);
		sort_three(a);
	}
	else if (max_index == 3)
	{
		pb(a, b);
		sort_three(a, b);
		pa(a, b);
	}
	return (max_index);
}

int		sort_five(t_stack *a, t_stack *b)
{
	int		max_index;

	max_index = find_max(a);
	if (max_index == 0)
	{
		ra(a, b);
		pb(a, b);
		sprt_four(a, b);
		pa(a, b);
	}
	else if (index == 1)

}

static int		find_min(t_stack *stack)
{
	int		index;
	t_node	*node;

	index = 0;
	node = stack -> head -> next;
	while (node != stack -> head)
	{
		if (node -> index == 0)
			return (index);
		index++;
	}
	return (-1);

}

static int		find_max(t_stack *stack)
{
	int		index;
	t_node	*node;

	index = 0;
	node = stack -> head -> next;
	while (node != stack -> head)
	{
		if (node -> index == (stack -> size - 1))
			return (index);
		index++;
	}
	return (-1);
}




