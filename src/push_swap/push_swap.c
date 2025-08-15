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

/*
static int	process_split_words(t_stack *a, char **split, char **argv, int i)
{
	int		j;
	t_node	*node;

	j = 0;
	while (split[j])
		j++;
	while (--j >= 0)
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
*/



int	fill_stack(t_stack *a, char **argv, int argc, int start)
{
	int		i;
	t_node	*node;

	i = argc - 1;
	while(i >= start)
	{
		if (!is_valid_integer(argv[i]) || has_duplicate_str(argv, argv[i], i, 0))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		node = create_node(ft_atoi(argv[i]));
		if (!node)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		push(a, node);
		i--;
	}
	return (a->size > 0);
}


int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**split = NULL;
	int		new_argc;
	int		start_index = 1;
	
	if (argc == 1)
		return (0);

	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		if (!split || !*split)
		{
			free_split(split);
			write(2, "Error\n", 6);
			return (0);
		}
		new_argc = 0;
		while (split[new_argc])
			new_argc++;
		if (new_argc <= 1)
		{
			free_split(split);
			return (0);
		}
		argv = split;
		argc = new_argc;
		start_index = 0;
	}

	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	if (!a || !b)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	init_stack(a, 'a');
	init_stack(b, 'b');

	if (fill_stack(a, argv, argc, start_index) == 0)
	{
		if (split)
			free_split(split);
		return (0);
	}

	normalize(a);
	solve_stack(a, b);
	free_stack(a);
	free_stack(b);

	if (split)
		free_split(split);
	return (0);
}

