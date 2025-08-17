/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddadi <mhaddadi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 22:50:53 by mhaddadi          #+#    #+#             */
/*   Updated: 2025/07/20 23:21:35 by mhaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	push_chunks(t_stack *a, t_stack *b, int chunk_count)
{
	int	chunk_size;
	int	next_index;

	chunk_size = a->size / chunk_count;
	next_index = 0;
	while (a->size > 0)
	{
		if (a->head->index <= next_index)
		{
			pb(a, b, 1);
			rb(b, 1);
			next_index++;
		}
		else if (a->head->index <= next_index + chunk_size)
		{
			pb(a, b, 1);
			next_index++;
		}
		else
			ra(a, 1);
	}
}

static t_node	*find_max_node(t_stack *b, int *max_pos)
{
	t_node	*tmp;
	t_node	*max_node;
	int		pos;

	tmp = b->head;
	max_node = tmp;
	pos = 0;
	*max_pos = 0;
	while (tmp)
	{
		if (tmp->index > max_node->index)
		{
			max_node = tmp;
			*max_pos = pos;
		}
		tmp = tmp->next;
		pos++;
		if (tmp == b->head)
			break ;
	}
	return (max_node);
}

static void	push_back_to_a(t_stack *a, t_stack *b)
{
	t_node	*max_node;
	int		max_pos;

	while (b->size > 0)
	{
		max_node = find_max_node(b, &max_pos);
		if (max_pos <= (int)(b->size / 2))
		{
			while (b->head != max_node)
				rb(b, 1);
		}
		else
		{
			while (b->head != max_node)
				rrb(b, 1);
		}
		pa(a, b, 1);
	}
}

int	chunk_sort(t_stack *a, t_stack *b, int chunk_count)
{
	push_chunks(a, b, chunk_count);
	push_back_to_a(a, b);
	return (1);
}
