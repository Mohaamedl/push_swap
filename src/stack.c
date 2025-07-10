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
	node -> index = -1;
	node -> next = NULL;
	node -> prev = NULL;
	node -> value = node_value;
	return (node);
}

void	*init_stack(t_stack *stack, char *stack_name)
{
	if (!stack)
		return (NULL);
	stack -> name = stack_name;
	stack -> size = 0;
	stack -> head = NULL;
	stack -> tail = NULL;
}

int		*push(t_stack *stack, t_node *new_node)
{
	t_node	*old_node;
	t_node	*last_node;

	if (!new_node)
		return (0);
	if (stack -> size == 0)
	{
		stack -> head = new_node;
		new_node -> next = new_node;
		new_node -> prev = new_node;
	}
	else
	{
		old_node =  stack -> head;
		last_node = old_node -> prev;
		new_node -> next = old_node;
		new_node -> prev = last_node;
		old_node -> prev = new_node;
		last_node -> next = new_node;
		stack -> head = new_node;
	}
	stack -> size++;
	return(1);
}

t_node	*pop(t_stack *stack)
{
	t_node	*node_pop;

	if (stack->size == 0)
		return (NULL);
	node_pop = stack -> head;
	if (stack -> size == 1)
		stack -> head == NULL;
	else
	{
		stack -> head = node_pop -> next;
		node_pop -> prev -> next = stack -> head;
		stack -> head -> prev = node_pop -> prev;
	}
	stack -> size--;
	node_pop -> next = node_pop;
	node_pop -> prev = node_pop;
	return (node_pop);
}

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

	stack -> heaed = second;
	return (1);
}

int	rotate_stack(t_stack stack)
{
	if (stack -> size < 2)
		return (0);
	stack -> head = stack -> head -> next;
	return (1);
}

int	reverse_rotate_stack(t_stack stack)
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


void	free_stack(t_stack stack)
{
	t_node	*current;
	t_node	*temp;

	if(!stack || !stack -> head)
		return ;
	current = stack -> head -> next;
	while (current != stack -> head)
	{
		temp = current;
		current = current -> next;
		free(temp);
	}
	free(current);
	stack -> head = NULL;
	stack -> size = 0;	
}

t_node	*pa(t_stack *a,t_stack *b)
{
	t_node	*push_node;
	if (!a || !b || b -> size == 0)
		return (0);
	push_node

}




















int		init_radix(int *max_bit,t_stack *a,int *i, int *j)
{
	i = 0;
}



int		radix_sort(t_stack *a, t_stack *b)
{
	int				max_bits
	size_t		size;
	size_t		i;
	size_t		j;

	if (!a || !b || a -> size == 0)
		return (0);
	//max_bits = 0;
	size = init_radix(&max_bits, &a, );
	while ((size - 1) >> max_bits)
				max_bits++;
	//i = 0;
	while(i++ < max_bits)
	{
		j = 0;
		while(j++ < size )
		{
			if ((a -> head -> index >> 1) == 0)
				pb(&a, &b);
			else
				ra(&a);

		}
		while (b -> size > 0)
			pa(&a, &b);
	}
	return (1);
}



