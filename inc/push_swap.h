/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddadi <mhaddadi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:06:21 by mhaddadi          #+#    #+#             */
/*   Updated: 2025/07/22 18:35:21 by mhaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



// Struct for circular doubly linked list stack impementation //
////
//
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "../libft/inc/libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
} t_node;

typedef struct s_stack
{
	size_t			size;
	char				name;
	t_node			*head;
	//t_node			*tail;
} t_stack;



//
//Utility functions for the stack
//



void				init_stack(t_stack *stack, char name); // ok 
t_node				*create_node(int value); // ok
t_node				*pop(t_stack *stack); //	ok
int					push(t_stack *stack, t_node *new_node); // 
int					empty(t_stack *stack); //	
void				*clear(t_stack *stack); //	
t_node				*peek(t_stack *stack); //	
void				normalize(t_stack *stack); //
int					chunk_sort(t_stack *a, t_stack *b, int chunk_count); //
int					is_sorted(t_stack *stack);
void				free_stack(t_stack *stack);

// sorting algos

int					radix_sort(t_stack *a, t_stack *b);
int					chunk_sort_inv(t_stack *a, t_stack *b, int chunk_count);

// push swap utils

int					is_valid_integer(char *s);

int					has_duplicate(char **argv, int current_index, int argc);

int					fill_stack(t_stack *a, t_stack *b, char **argv, int argc);

// Utility funcions for push_swap
//


t_node				*pa(t_stack *a, t_stack  *b);
t_node				*pb(t_stack	*a, t_stack *b);
int					sa(t_stack *a);
int					sb(t_stack *b);
int					ss(t_stack *a, t_stack *b);
int					ra(t_stack *a);
int					rb(t_stack *b);
int					rr(t_stack *a, t_stack *b);
int					rra(t_stack *a);
int					rrb(t_stack *b);
int					rrr(t_stack *a, t_stack *b);





