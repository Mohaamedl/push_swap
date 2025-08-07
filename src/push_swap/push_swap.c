/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddadi <mhaddadi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 06:45:36 by mhaddadi          #+#    #+#             */
/*   Updated: 2025/08/07 20:53:00 by mhaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static int	process_split_words(t_stack *a, char **split, char **argv, int i)
{
	int		j;
	t_node	*node;

	j = -1;
	while (split[++j])
	{
		if (!is_valid_integer(split[j])
			|| has_duplicate_str(argv, split[j], i, j))
		{
			return (write(2, "Error\n", 6), 0);
		}
		node = create_node(ft_atoi(split[j]));
		if (!node)
			return (write(2, "Error\n", 6), 0);
		push(a, node);
	}
	return (1);
}

int	fill_stack(t_stack *a, char **argv, int argc)
{
	char	**split;
	int		i;
	int		result;

	i = argc;
	while (--i > 0)
	{
		split = ft_split(argv[i], ' ');
		if (!split || !*split)
		{
			free_split(split);
			return (write(2, "Error\n", 6), 0);
		}
		result = process_split_words(a, split, argv, i);
		free_split(split);
		if (!result)
			return (0);
	}
	return (a->size > 0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (0);
	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	if (!a || !b)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	init_stack(a, 'a');
	init_stack(b, 'b');
	if (fill_stack(a, argv, argc) == 0)
		return (0);
	normalize(a);
	solve_stack(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
