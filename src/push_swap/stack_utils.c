/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddadi <mhaddadi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:52:26 by mhaddadi          #+#    #+#             */
/*   Updated: 2025/07/21 18:54:58 by mhaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int		swap_top_two(t_stack *stack)
{
	t_node		*first;
	t_node		*second;

	if(stack -> size < 2)
		return (0);
	first = stack -> head;
	second = first -> next;
	first -> next = second -> next;
	second -> next -> prev = first;
	second -> prev = first -> prev;
	first -> prev -> next = second;
	second -> next = first;
	first -> prev = second;

	stack -> head = second;
	return (1);
}

int	rotate_stack(t_stack *stack)
{
	if (stack -> size < 2)
		return (0);
	stack -> head = stack -> head -> next;
	return (1);
}

int	reverse_rotate_stack(t_stack *stack)
{
	if(stack -> size < 2)
		return (0);
	stack -> head = stack -> head -> prev;
	return (1);
}

void	normalize(t_stack *stack)
{
	t_node	*current;
	t_node	*runner;
	int			index;
	size_t	i;
	size_t	j;

	current = stack -> head;
	if(!current)
		return ;
	i = 0;
	while(i++ < stack -> size)
	{
		index = 0;
		runner = stack -> head;
		j = 0;
		while (j++ < stack -> size)
		{
			if (runner -> value < current -> value)
				index++;
			runner = runner -> next;
		}
		current ->index = index;
		current = current -> next;
	}
}

int		is_sorted(t_stack *stack)
{
	size_t		i;
	size_t		bool;
	t_node *current;

	bool = 0;
	current = stack -> head;
	i = 0;
	while(i++ < stack -> size - 1)
	{
		if (current -> value > current -> next -> value)
			return(0);
		current = current -> next;
		bool++;
	}
	return (bool);
}
/*
void fill_stack_random(t_stack *stack, int count)
{
	int		range = count * 5; // value window
	int		*values = malloc(count * sizeof(int));
	int		*pool = malloc((2 * range + 1) * sizeof(int));
	t_node	*node;

	if (!values || !pool)
	{
		free(values);
		free(pool);
		return;
	}

	// pool values from -range to range
	for (int i = 0; i < 2 * range + 1; i++)
		pool[i] = -range + i;

	// shuffle pool
	for (int i = 2 * range; i > 0; i--)
	{
		int j = rand() % (i + 1);
		int tmp = pool[i];
		pool[i] = pool[j];
		pool[j] = tmp;
	}

	// use first unique values from pool
	for (int i = 0; i < count; i++)
		values[i] = pool[i];

	for (int i = 0; i < count; i++)
	{
		node = create_node(values[i]);
		push(stack, node);
	}
	free(values);
	free(pool);
}

*/
