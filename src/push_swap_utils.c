/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddadi <mhaddadi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:54:29 by mhaddadi          #+#    #+#             */
/*   Updated: 2025/07/22 19:01:56 by mhaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>

int	fill_stack(t_stack *a, t_stack *b, char **argv, int argc)
{
	int		i;
	t_node	*node;

	i = argc;
	while (i-- > 0)
	{
		if (!is_valid_integer(argv[i]) || has_duplicate(argv, i, argc))
		{
			printf("%s\n", "Error");
			free_stack(a);
			free_stack(b);
			exit(EXIT_FAILURE);
		}
		node = create_node(ft_atoi(argv[i]));
		push(a, node);
	}
	if (a -> size == 0)
		return (0);
	return (1);
}

int	is_valid_integer(char *s)
{
	long	num;
	int		i;
	int		sign;

	if (!s || *s == '\0')
		return (0);
	i = 0;
	sign = 1;
	if (s[i] == '-' || s[i] == '+')
		if (s[i++] == '-')
			sign = -1;
	if (!s[i])
		return (0);
	num = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		num = num * 10 + (s[i] - '0');
		if ((sign == 1 && num > INT_MAX) || (sign == -1 && - num < INT_MIN))
			return (0);
		i++;
	}
	return (1);
}

int	has_duplicate(char **argv, int current_index, int argc)
{
	int	i;

	i = argc - 1;
	while (i > current_index)
	{
		if (ft_atoi(argv[i]) == ft_atoi(argv[current_index]))
			return (1);
		i--;
	}
	return (0);
}
