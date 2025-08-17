/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddadi <mhaddadi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 20:55:00 by mhaddadi          #+#    #+#             */
/*   Updated: 2025/08/07 20:55:00 by mhaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	move_min_to_top(t_stack *a, int min_index)
{
	if (min_index == 1)
		ra(a, 1);
	else if (min_index == 2)
	{
		ra(a, 1);
		ra(a, 1);
	}
	else if (min_index == 3)
	{
		rra(a, 1);
		rra(a, 1);
	}
	else if (min_index == 4)
		rra(a, 1);
}

int	find_min(t_stack *stack)
{
	int		index;
	t_node	*node;

	index = 0;
	node = stack->head;
	if (node->index == 0)
		return (0);
	node = node->next;
	index = 1;
	while (node != stack->head)
	{
		if (node->index == 0)
			return (index);
		index++;
		node = node->next;
	}
	return (-1);
}
