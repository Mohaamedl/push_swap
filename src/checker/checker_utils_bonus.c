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
#include "../../inc/checker_bonus.h"

int	init_stacks(t_stack **a, t_stack **b)
{
	*a = malloc(sizeof(t_stack));
	*b = malloc(sizeof(t_stack));
	if (!*a || !*b)
	{
		if (*a)
			free(*a);
		if (*b)
			free(*b);
		write(2, "Error\n", 6);
		return (0);
	}
	init_stack(*a, 'a');
	init_stack(*b, 'b');
	return (1);
}

int	execute_operation(char *line, t_stack *a, t_stack *b)
{
	if (ft_strcmp(line, "sa") == 0)
		sa(a, 0);
	else if (ft_strcmp(line, "sb") == 0)
		sb(b, 0);
	else if (ft_strcmp(line, "ss") == 0)
		ss(a, b, 0);
	else if (ft_strcmp(line, "pa") == 0)
		pa(a, b, 0);
	else if (ft_strcmp(line, "pb") == 0)
		pb(a, b, 0);
	else if (ft_strcmp(line, "ra") == 0)
		ra(a, 0);
	else if (ft_strcmp(line, "rb") == 0)
		rb(b, 0);
	else if (ft_strcmp(line, "rr") == 0)
		rr(a, b, 0);
	else if (ft_strcmp(line, "rra") == 0)
		rra(a, 0);
	else if (ft_strcmp(line, "rrb") == 0)
		rrb(b, 0);
	else if (ft_strcmp(line, "rrr") == 0)
		rrr(a, b, 0);
	else
		return (0);
	return (1);
}

void	read_and_execute(t_stack *a, t_stack *b)
{
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		if (ft_strlen(line) > 0 && !execute_operation(line, a, b))
		{
			write(2, "Error\n", 6);
			free(line);
			exit(EXIT_FAILURE);
		}
		free(line);
		line = get_next_line(0);
	}
}

int	is_checker_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || stack->size <= 1)
		return (1);
	current = stack->head;
	while (current->next != stack->head)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}
