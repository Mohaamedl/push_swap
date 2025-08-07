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
# include "../libft/inc/get_next_line.h"

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

int					swap_top_two(t_stack *stack);
int					rotate_stack(t_stack *stack);
int					reverse_rotate_stack(t_stack *stack);
void				init_stack(t_stack *stack, char name);
t_node				*create_node(int value);
t_node				*pop(t_stack *stack);
int					push(t_stack *stack, t_node *new_node);
int					empty(t_stack *stack);
void				*clear(t_stack *stack);
t_node				*peek(t_stack *stack);
void				normalize(t_stack *stack);
int					chunk_sort(t_stack *a, t_stack *b, int chunk_count);
int					is_sorted(t_stack *stack);
void				free_stack(t_stack *stack);
int					radix_sort(t_stack *a, t_stack *b);
int					chunk_sort_inv(t_stack *a, t_stack *b, int chunk_count);
int					fill_stack(t_stack *a, char **argv, int argc);
int					has_duplicate_str(char **argv, char *val, int arg_i,
						int word_j);
int					is_valid_integer(const char *s);
void				free_split(char **arr);
int					get_chunk_count(int size);
void				move_min_to_top(t_stack *a, int min_index);
int					find_min(t_stack *stack);

t_node				*pa(t_stack *a, t_stack *b);
t_node				*pb(t_stack *a, t_stack *b);
int					sa(t_stack *a);
int					sb(t_stack *b);
int					ss(t_stack *a, t_stack *b);
int					ra(t_stack *a);
int					rb(t_stack *b);
int					rr(t_stack *a, t_stack *b);
int					rra(t_stack *a);
int					rrb(t_stack *b);
int					rrr(t_stack *a, t_stack *b);

int					sort_three(t_stack *stack);
int					sort_four(t_stack *a, t_stack *b);
int					sort_five(t_stack *a, t_stack *b);
int					solve_stack(t_stack *a, t_stack *b);

#endif
