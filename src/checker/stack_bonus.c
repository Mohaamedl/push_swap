#include "../../inc/push_swap.h"
#include <stdio.h>
#include <time.h>


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



t_node	*pa(t_stack *a, t_stack *b)
{
	t_node	*push_node;
	if (!a || !b || b -> size == 0)
		return (0);
	push_node =  pop(b);
	if (!push_node)
		return (NULL);
	if (push(a,push_node) != 1)
		return (NULL);
	return (push_node);
}

t_node	*pb(t_stack *a, t_stack *b)
{
	t_node	*push_node;
	if (!a || !b || a -> size == 0)
		return (0);
	push_node =  pop(a);
	if (!push_node)
		return (NULL);
	if (push(b,push_node) != 1)
		return (NULL);
	return (push_node);
	
}

int		sa(t_stack *a)
{
	if(a -> size < 2)
		return (0);
	swap_top_two(a);
	return (1);
}

int		sb(t_stack *b)
{
	if(b -> size < 2)
		return (0);
	swap_top_two(b);
	return (1);

}

int		ss(t_stack *a, t_stack *b)
{
	if(a -> size < 2 || b -> size < 2)
		return (0);
	swap_top_two(a);
	swap_top_two(a);
	return (1);
}

int		ra(t_stack *a)
{
	rotate_stack(a);
	return (1);
}

int		rb(t_stack *b)
{
	rotate_stack(b);
	return (1);
}

int		rr(t_stack *a, t_stack *b)
{
	rotate_stack(a);
	rotate_stack(b);
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
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
	return (1);
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
		//printf("current value: %d, next value %d\n", current -> value, current -> next -> value);
		if (current -> value > current -> next -> value)
			return(0);
		current = current -> next;
		bool++;
	}
	return (bool);
}
