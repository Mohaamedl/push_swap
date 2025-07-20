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
	printf("pa%s\n","");
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
	printf("pb%s\n","");
	return (push_node);
	
}

int		sa(t_stack *a)
{
	if(a -> size < 2)
		return (0);
	swap_top_two(a);
	printf("sa%s\n","");
	return (1);
}

int		sb(t_stack *b)
{
	if(b -> size < 2)
		return (0);
	swap_top_two(b);
	printf("sb%s\n","");
	return (1);

}

int		ra(t_stack *a)
{
	rotate_stack(a);
	printf("ra%s\n", "");
	return (1);
}

int		rb(t_stack *b)
{
	rotate_stack(b);
	printf("rb%s\n", "");
	return (1);
}

int		rr(t_stack *a, t_stack *b)
{
	rotate_stack(a);
	rotate_stack(b);
	printf("rr%s\n", "");
	return (1);
}

int		rra(t_stack *a)
{
	reverse_rotate_stack(a);
	printf("rra%s\n","");
	return (1);
}

int		rrb(t_stack *b)
{
	reverse_rotate_stack(b);
	printf("rrb%s\n","");
	return (1);
}

int		rrr(t_stack *a, t_stack *b)
{
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
	printf("rrr%s\n","");
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
		//printf("current value: %d, next value %d\n", current -> value, current -> next -> value);
		if (current -> value > current -> next -> value)
			return(0);
		current = current -> next;
		bool++;
	}
	return (bool);
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

void push_chunks(t_stack *a, t_stack *b, int chunk_count)
{
	int chunk_size = a->size / chunk_count;
	int next_index = 0;
	while (a->size > 0)
	{
		if (a->head->index <= next_index)
		{
			pb(a, b);
			rb(b); // menor -> fundo
			next_index++;
		}
		else if (a->head->index <= next_index + chunk_size)
		{
			pb(a, b); // medio -> meio
			next_index++;
		}
		else
			ra(a); // nao pertence ao chunk -> avanca
	}
}
void push_back_to_a(t_stack *a, t_stack *b)
{
	while (b->size > 0)
	{
		t_node *tmp = b->head;
		t_node *max_node = tmp;
		size_t pos = 0, max_pos = 0;

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
/*
int main(void)
{
	t_stack *a = malloc(sizeof(t_stack));
	t_stack *b = malloc(sizeof(t_stack));
	int			num = 100;
	init_stack(a, 'a');
	init_stack(b, 'b');

	fill_stack_random(a, num);
	normalize(a);
	
	if (!chunk_sort(a, b, 5))
	{
		printf("Sorting failed.\n");
		return 1;
	}

	if (is_sorted(a))
		printf("✅ Sorted correctly!\n");
	else
		printf("❌ Not sorted.\n");
	
	t_node *n = a->head;
	for (int i = 0; i < num; i++)
	{
		printf("val: %d index: %d\n", n->value, n->index);
		n = n->next;
	}
	
	free_stack(a);
	free_stack(b);
	free(a);
	free(b);
}
*/
void push_chunks_inv(t_stack *a, t_stack *b, int chunk_count)
{
	int chunk_size = a->size / chunk_count;
	int next_index = a->size - 1; 
	while (a->size > 0)
	{
		if (a->head->index >= next_index)
		{
			pb(a, b);
			rrb(b);
			next_index--;
		}
		else if (a->head->index >= next_index - chunk_size)
		{
			pb(a, b);
			next_index--;
		}
		else
			ra(a);
	}
}

void push_back_to_a_inv(t_stack *a, t_stack *b)
{
	while (b->size > 0)
	{
		t_node *tmp = b->head;
		t_node *min_node = tmp;
		size_t pos = 0, min_pos = 0;

		while (tmp)
		{
			if (tmp->index < min_node->index)
			{
				min_node = tmp;
				min_pos = pos;
			}
			tmp = tmp->next;
			pos++;
			if (tmp == b->head) break;
		}

		if (min_pos <= b->size / 2)
			while (b->head != min_node) rb(b);
		else
			while (b->head != min_node) rrb(b);
		pa(a, b);
	}
}

int chunk_sort_inv(t_stack *a, t_stack *b, int chunk_count)
{
	push_chunks_inv(a, b, chunk_count);
	push_back_to_a_inv(a, b);
	return (1);
}

