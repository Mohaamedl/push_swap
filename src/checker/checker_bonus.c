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

int	stack_is_empty(t_stack *stack)
{
	return (stack == NULL || stack->size == 0);
}

static int	is_valid_integer_checker(const char *str)
{
	int i = 0;

	if (!str || *str == '\0')
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	has_duplicate(t_stack *stack, int value)
{
	t_node *curr = stack->head;
	size_t i = 0;

	if (!curr)
		return (0);
	while (i < stack->size)
	{
		if (curr->value == value)
			return (1);
		curr = curr->next;
		i++;
	}
	return (0);
}
int	ft_isspace(int c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

long	ft_atol(const char *str)
{
	int		sign = 1;
	long	result = 0;

	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	while (ft_isdigit(*str))
		result = result * 10 + (*str++ - '0');
	return (result * sign);
}

int	ini_stack(t_stack *a, int argc, char **argv)
{
	int		i;
	long	value;
	t_node	*new;

	a->head = NULL;
	a->name = 'a';
	a->size = 0;

	i = argc - 1;
	while (i > 0)
	{
		if (!is_valid_integer_checker(argv[i]))
			return (0);
		value = ft_atol(argv[i]);
		if (value < INT_MIN || value > INT_MAX)
			return (0);
		if (has_duplicate(a, (int)value))
			return (0);
		new = create_node((int)value);
		if (!new)
			return (0);
		push(a, new);
		i--;
	}
	return (1);
}

static void	free_all(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
}

static void	print_error_and_exit(t_stack *a, t_stack*b)
{
	free_all(a, b);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

static void	execute_instruction(char *line, t_stack *a, t_stack *b)
{
	if (!line)
		print_error_and_exit(a, b);

	if (ft_strcmp(line, "sa\n") == 0)
		sa(a);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb(b);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss(a, b);
	else if (ft_strcmp(line, "pa\n") == 0)
		pa(a, b);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb(a, b);
	else if (ft_strcmp(line, "ra\n") == 0)
		ra(a);
	else if (ft_strcmp(line, "rb\n") == 0)
		rb(b);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr(a, b);
	else if (ft_strcmp(line, "rra\n") == 0)
		rra(a);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb(b);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr(a, b);
	else
		print_error_and_exit(a, b);
}
void	free_split(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
static int	check_duplicate_in_split(char **split, char *val, int word_j)
{
	int	j;

	j = 0;
	while (split[j])
	{
		if (j != word_j && ft_strncmp(split[j], val, ft_strlen(val)) == 0
			&& ft_strlen(split[j]) == ft_strlen(val))
		{
			return (1);
		}
		j++;
	}
	return (0);
}

int	has_duplicate_str(char **argv, char *val, int arg_i, int word_j)
{
	int		i;
	char	**split;
	int		found;

	i = 1;
	while (argv[i])
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			return (1);
		if (i == arg_i)
			found = check_duplicate_in_split(split, val, word_j);
		else
			found = check_duplicate_in_split(split, val, -1);
		free_split(split);
		if (found)
			return (1);
		i++;
	}
	return (0);
}


int	fill_stack(t_stack *a, char **argv, int argc, int start)
{
	int		i;
	t_node	*node;

	i = argc - 1;
	while(i >= start)
	{
		if (!is_valid_integer_checker(argv[i]) || has_duplicate_str(argv, argv[i], i, 0))
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
	char	*line;
	char	**split = NULL;
	int		new_argc;

	new_argc=1;
	if (argc < 2)
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
		new_argc = 0;
	}

	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	init_stack(a, 'a');
	init_stack(b, 'b');
	if (!fill_stack(a, argv, argc, new_argc))
	{
		if (split)
			free_split(split);
		print_error_and_exit(a, b);
	}

	while ((line = get_next_line(0)))
	{
		execute_instruction(line, a, b);
		free(line);
	}

	if (is_sorted(a) && stack_is_empty(b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);

	if (split)
		free_split(split);
	free_all(a, b);
	return (0);
}

