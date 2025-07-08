/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddadi <mhaddadi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:42:37 by mhaddadi          #+#    #+#             */
/*   Updated: 2025/07/08 19:49:05 by mhaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_node	*create_node(int node_value)
{
	t_node		*node;
	node =  (t_node*) malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node -> next = NULL;
	node -> prev = NULL;
	node -> value = node_value;
	return (node);
}

t_stack	*init_stack(char *stack_name)
{
	t_stack		*stack;
	stack = (t_stack*) malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack -> name = stack_name;
	stack -> size = 0;
	stack -> head = NULL;
	stack -> tail = NULL;
	return (stack);
}

t_node	*pop(t_stack *stack)
{
	
}






