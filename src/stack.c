/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   Created: 2025/07/08 18:42:37 by mhaddadi          #+#    #+#             */
/*   Updated: 2025/07/10 15:32:43 by mhaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

#include <stdio.h>
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

void	init_stack(t_stack *stack, char stack_name)
{
	stack -> name = stack_name;
	stack -> size = 0;
	stack -> head = NULL;
	//stack -> tail = NULL;
}

int		push(t_stack *stack, t_node *new_node)
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
		stack -> head = NULL;
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


void	free_stack(t_stack *stack)
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
	stack -> size  = 0 ;
}


t_node	*pa(t_stack *a, t_stack *b)
{
	t_node	*push_node;
	if (!a || !b || b -> size == 0)
		return (0);
	push_node =  pop(b);
	if (!push_node)
		return (NULL);
	if (push(a,push_node) != 0)
		return (NULL);
	printf("pa%s\n","");
	return (push_node);
}

t_node	*pb(t_stack *a, t_stack *b)
{
	t_node	*push_node;
	if (!a || !b || b -> size == 0)
		return (0);
	push_node =  pop(a);
	if (!push_node)
		return (NULL);
	if (push(b,push_node) != 0)
		return (NULL);
	printf("pb%s\n","");
	return (push_node);
	
}

int		sa(t_stack *a)
{
	if(a -> size < 2)
		return (0);
	swap_top_two(a);
	printf("sa%s","");
	return (1);
}

int		sb(t_stack *b)
{
	if(b -> size < 2)
		return (0);
	swap_top_two(b);
	printf("sb%s","");
	return (1);

}

int		ra(t_stack *a)
{
	rotate_stack(a);
	printf("ra%s", "");
	return (1);
}

int		rb(t_stack *b)
{
	rotate_stack(b);
	printf("rb%s", "");
	return (1);
}

int		rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
	printf("rr%s", "");
	return (1);
}

int		rra(t_stack *a)
{
	reverse_rotate_stack(a);
	return (1);
}

int		rrb(t_stack *b)
{
	reverse_rotate_stack(b);
	return (1);
}

int		rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
	return (1);
}


size_t		init_radix(int *max_bits,t_stack *a,size_t *i )
{
	*i = 0;
	*max_bits = 0;
	return (a -> size);
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
		printf("current value: %d, next value %d\n", current -> value, current -> next -> value);
		if (current -> value < current -> next -> value)
			return(0);
		current = current -> next;
		bool++;
	}
	return (bool);
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
	printf("maxbits : %d\n", max_bits);
	while(i++ < (size_t) max_bits)
	{
		j = 0;
		while(j++ < size)
		{
			if ((((a -> head -> value) >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
		}
		while (b -> size > 0)
			pa(a, b);
	}
	return (1);
}

int main(void)
{
	t_stack		*a;
	t_stack		*b;

	a = (t_stack*) malloc(sizeof(t_stack));
	b = (t_stack*) malloc(sizeof(t_stack));
	init_stack(a, 'a');
	init_stack(b, 'b');
	
	t_node *n1 = create_node(1);
	t_node *n2 = create_node(2);
	t_node *n3 = create_node(3);
	t_node *n4 = create_node(43);
	t_node *n5 = create_node(5);
	t_node *n6 = create_node(36);
	t_node *n7 = create_node(7);
	t_node *n8 = create_node(8);
	t_node *n9 = create_node(9);
	push(a, n1);
	push(a, n2);
	push(a, n3);
	push(a, n4);
	push(a, n5);
	push(a, n6);
	push(a, n7);
	push(a, n8);
	push(a, n9);
	normalize(a);	
	radix_sort(a, b);
	printf(" result %d\n", is_sorted(a));
	t_node	*node;
	node = a -> head -> next;

	node = a -> head;

	while(node -> next != a -> head)
	{
		printf("value: %d  index:  %d\n", node -> value, node -> index);
		node = node -> next;
	}
	printf("value: %d  index:  %d\n", node -> value, node -> index);


}
