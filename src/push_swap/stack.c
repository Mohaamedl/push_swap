/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddadi <mhaddadi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 19:31:54 by mhaddadi          #+#    #+#             */
/*   Updated: 2025/08/06 19:32:27 by mhaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

t_node	*create_node(int node_value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->index = -1;
	node->next = NULL;
	node->prev = NULL;
	node->value = node_value;
	return (node);
}

void	init_stack(t_stack *stack, char stack_name)
{
	stack->name = stack_name;
	stack->size = 0;
	stack->head = NULL;
}

int	push(t_stack *stack, t_node *new_node)
{
	t_node	*old_node;
	t_node	*last_node;

	if (!new_node)
		return (0);
	if (stack->size == 0)
	{
		stack->head = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
	}
	else
	{
		old_node = stack->head;
		last_node = old_node->prev;
		new_node->next = old_node;
		new_node->prev = last_node;
		old_node->prev = new_node;
		last_node->next = new_node;
		stack->head = new_node;
	}
	stack->size++;
	return (1);
}

t_node	*pop(t_stack *stack)
{
	t_node	*node_pop;

	if (stack->size == 0)
		return (NULL);
	node_pop = stack->head;
	if (stack->size == 1)
		stack->head = NULL;
	else
	{
		stack->head = node_pop->next;
		node_pop->prev->next = stack->head;
		stack->head->prev = node_pop->prev;
	}
	stack->size--;
	node_pop->next = node_pop;
	node_pop->prev = node_pop;
	return (node_pop);
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*temp;

	if (!stack || !stack->head)
		return ;
	current = stack->head->next;
	while (current != stack->head)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	free(current);
	stack->head = NULL;
	stack->size = 0;
}
/*
size_t		init_radix(int *max_bits,t_stack *a,size_t *i )
{
	*i = 0;
	*max_bits = 0;
	return (a -> size);
}

int	find_rotation_dir(t_stack *stack, int max_index)
{
	t_node	*tmp = stack->head;
	size_t		forward = 0;
	size_t		backward = 0;

	// Frente
	while (forward < stack->size && tmp->index >= max_index)
	{
		tmp = tmp->next;
		forward++;
	}

	// Trás
	tmp = stack->head->prev;
	while (backward < stack->size && tmp->index >= max_index)
	{
		tmp = tmp->prev;
		backward++;
	}

	return (forward <= backward) ? 1 : -1; // 1 = ra/rb, -1 = rra/rrb
}

void	rotate_to_top(t_stack *stack, t_node *target, char id)
{
	size_t	pos = 0;
	t_node *tmp = stack->head;

	while (tmp != target)
	{
		tmp = tmp->next;
		pos++;
	}
	if (pos <= stack->size / 2)
	{
		while (stack->head != target)
		{
			if (id == 'a') ra(stack);
			else rb(stack);
		}
	}
	else
	{
		while (stack->head != target)
		{
			if (id == 'a') rra(stack);
			else rrb(stack);
		}
	}
}

int		radix_sort(t_stack *a, t_stack *b)
{
	int			max_bits;
	size_t		size;
	size_t		i;
	size_t		j;

	if (!a || !b || a -> size == 0)
		return (0);
	size = init_radix(&max_bits, a, &i);
	while ((size - 1) >> max_bits)
				max_bits++;
	//printf("maxbits : %d\n", max_bits);
	while(i < (size_t) max_bits)
	{
		j = 0;
		while(j++ < size)
		{
			if ((((a -> head -> index) >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
		}
		while (b -> size > 0)
			pa(a, b);
		i++;
	}
	return (1);
}
*/
