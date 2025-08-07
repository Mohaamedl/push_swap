/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddadi <mhaddadi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:01:07 by mhaddadi          #+#    #+#             */
/*   Updated: 2025/08/06 19:37:47 by mhaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	sort_three(t_stack *stack)
{
	int	n1;
	int	n2;
	int	n3;

	n3 = stack->head->index;
	n2 = stack->head->next->index;
	n1 = stack->head->next->next->index;
	if (n3 > n2 && n2 < n1 && n3 < n1)
		sa(stack);
	else if (n3 > n2 && n2 > n1 && n3 > n1)
	{
		sa(stack);
		rra(stack);
	}
	else if (n3 > n2 && n2 < n1 && n3 > n1)
		ra(stack);
	else if (n3 < n2 && n2 > n1 && n3 < n1)
	{
		sa(stack);
		ra(stack);
	}
	else if (n3 < n2 && n2 > n1 && n3 > n1)
		rra(stack);
	return (0);
}

int	sort_four(t_stack *a, t_stack *b)
{
	int	min_index;

	min_index = find_min(a);
	if (min_index == 0)
		pb(a, b);
	else if (min_index == 1)
	{
		ra(a);
		pb(a, b);
	}
	else if (min_index == 2)
	{
		ra(a);
		ra(a);
		pb(a, b);
	}
	else if (min_index == 3)
	{
		rra(a);
		pb(a, b);
	}
	sort_three(a);
	pa(a, b);
	return (1);
}

int	sort_five(t_stack *a, t_stack *b)
{
	int	min_index;

	min_index = find_min(a);
	if (min_index != 0)
		move_min_to_top(a, min_index);
	pb(a, b);
	normalize(a);
	sort_four(a, b);
	pa(a, b);
	return (1);
}

int	solve_stack(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return (1);
	if (a->size == 2)
	{
		if (a->head->index > a->head->next->index)
			sa(a);
	}
	else if (a->size == 3)
		sort_three(a);
	else if (a->size == 4)
		sort_four(a, b);
	else if (a->size == 5)
		sort_five(a, b);
	else
		chunk_sort(a, b, get_chunk_count(a->size));
	return (1);
}
