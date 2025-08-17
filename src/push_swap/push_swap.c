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

static int	fill_stack(t_stack *a, char **argv, int argc, int start)
{
	int		i;
	t_node	*node;

	i = argc - 1;
	while (i >= start)
	{
		if (!is_valid_integer(argv[i])
			|| has_duplicate_str(argv, argv[i], i, 0))
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

static char	**handle_single_arg(char *arg, int *new_argc)
{
	char	**split;

	split = ft_split(arg, ' ');
	if (!split || !*split)
	{
		free_split(split);
		write(2, "Error\n", 6);
		return (NULL);
	}
	*new_argc = 0;
	while (split[*new_argc])
		(*new_argc)++;
	if (*new_argc == 0)
	{
		free_split(split);
		write(2, "Error\n", 6);
		return (NULL);
	}
	return (split);
}

static int	parse_and_fill_stack(t_stack *a, int argc, char **argv,
	char ***split_ptr)
{
	char	**split;
	int		new_argc;
	int		start_index;

	split = NULL;
	start_index = 1;
	if (argc == 2)
	{
		split = handle_single_arg(argv[1], &new_argc);
		if (!split)
			return (0);
		argv = split;
		argc = new_argc;
		start_index = 0;
	}
	*split_ptr = split;
	return (fill_stack(a, argv, argc, start_index));
}

static int	init_stacks(t_stack **a, t_stack **b)
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

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**split;

	if (argc == 1)
		return (0);
	if (!init_stacks(&a, &b))
		exit(EXIT_FAILURE);
	if (!parse_and_fill_stack(a, argc, argv, &split))
	{
		cleanup_all(a, b, split);
		return (0);
	}
	normalize(a);
	solve_stack(a, b);
	cleanup_all(a, b, split);
	return (0);
}
