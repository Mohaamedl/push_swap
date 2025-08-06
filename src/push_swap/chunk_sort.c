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

static void push_chunks(t_stack *a, t_stack *b, int chunk_count)
{
	int chunk_size = a->size / chunk_count;
	int next_index = 0;
	while (a->size > 0)
	{
		if (a->head->index <= next_index)
		{
			pb(a, b);
			rb(b);
			next_index++;
		}
		else if (a->head->index <= next_index + chunk_size)
		{
			pb(a, b);
			next_index++;
		}
		else
			ra(a);
	}
}

static void push_back_to_a(t_stack *a, t_stack *b)
{
	while (b->size > 0)
	{
		t_node *tmp = b->head;
		t_node *max_node = tmp;
		int pos = 0, max_pos = 0;

		while (tmp)
		{
			if (tmp->index > max_node->index)
			{
				max_node = tmp;
				max_pos = pos;
			}
			tmp = tmp->next;
			pos++;
			if (tmp == b->head) break;
		}

		if (max_pos <= b->size / 2)
			while (b->head != max_node) rb(b);
		else
			while (b->head != max_node) rrb(b);
		pa(a, b);
	}
}

int chunk_sort(t_stack *a, t_stack *b, int chunk_count)
{
	push_chunks(a, b, chunk_count);
	push_back_to_a(a, b);
	return (1);
}
