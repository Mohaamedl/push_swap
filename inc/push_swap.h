/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddadi <mhaddadi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:06:21 by mhaddadi          #+#    #+#             */
/*   Updated: 2025/08/06 19:32:18 by mhaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	size_t			size;
	char			name;
	t_node			*head;
}	t_stack;

// Stack functions

void				init_stack(t_stack *stack, char name);
t_node				*create_node(int value);
t_node				*pop(t_stack *stack);
int					push(t_stack *stack, t_node *new_node);
void				free_stack(t_stack *stack);

// push_swap stack functions

int					swap_top_two(t_stack *stack);
int					rotate_stack(t_stack *stack);
int					reverse_rotate_stack(t_stack *stack);

// push_swap operations

t_node				*pa(t_stack *a, t_stack *b, int print);
t_node				*pb(t_stack *a, t_stack *b, int print);
int					sa(t_stack *a, int print);
int					sb(t_stack *b, int print);
int					ss(t_stack *a, t_stack *b, int print);
int					ra(t_stack *a, int print);
int					rb(t_stack *b, int print);
int					rr(t_stack *a, t_stack *b, int print);
int					rra(t_stack *a, int print);
int					rrb(t_stack *b, int print);
int					rrr(t_stack *a, t_stack *b, int print);

// push_swap utils

int					is_valid_integer(const char *s);
int					has_duplicate_str(char **argv, char *val, int arg_i,
						int word_j);

// Chunk sort functions

int					chunk_sort(t_stack *a, t_stack *b, int chunk_count);
void				normalize(t_stack *stack);
int					is_sorted(t_stack *stack);
int					solve_stack(t_stack *a, t_stack *b);

// chunk sort utils 

void				free_split(char **arr);
void				move_min_to_top(t_stack *a, int min_index);
int					find_min(t_stack *stack);
void				cleanup_all(t_stack *a, t_stack *b, char **split);

#endif
