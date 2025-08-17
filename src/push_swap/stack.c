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
