/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddadi <mhaddadi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 11:15:05 by mhaddadi          #+#    #+#             */
/*   Updated: 2025/08/03 11:15:12 by mhaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "push_swap.h"
# include "../libft/inc/get_next_line.h"

// Checker utils

int			is_checker_sorted(t_stack *stack);
int			init_stacks(t_stack **a, t_stack **b);
int			execute_operation(char *line, t_stack *a, t_stack *b);
void		read_and_execute(t_stack *a, t_stack *b);

#endif
