/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddadi <mhaddadi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 06:45:36 by mhaddadi          #+#    #+#             */
/*   Updated: 2025/07/22 19:11:23 by mhaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../libft/libft.h"
#include <stdio.h>

//static int print_stack(t_stack *stack);
static char		**str_argv(char *argv, int *argc);

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	if (!a || !b)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	init_stack(a, 'a');
	init_stack(b, 'b');
	if (argc == 1)
		return (0);
	else if (argc == 2)
	{
		//argv = str_argv(argv[1], &argc);
		fill_stack(a, b, str_argv(argv[1], &argc), argc);
	}
	else
		fill_stack(a, b, argv + 1, argc - 1);
	normalize(a);
	if (is_sorted(a) == 0)
		chunk_sort(a, b, 15);
	free_stack(a);
	free_stack(b);
	free(a);
	free(b);
	return (0);
}

static char **str_argv(char *argv, int *argc)
{
	char	**result;
	int		i;

	i = 0;
	result = ft_split(argv, ' ');
	free(argv);
	if (!result)
		return (NULL);
	while (result[i] != 0)
		i++;
	*argc = i;
	return (result);
}
/*
int	main(int argc, char **argv)
{
	int i = 0;
	while (argc > ++i)
	{
		printf("%d\n", ft_atoi(argv[i]));
	}
}


t_stack		*fill_stack(char	*values)
{
	t_stack		*stack;
	t_node		*node;
	t_node		*temp;

	while (*values)
	{
		if (ft_isdigit(*values) || *values == ' ')
		{
			if(ft_isdigit(*values))
			{
				node = create_node(*values - '0');
				push(stack, node);
				temp = node;
				free(temp);
			}
		}
		else
			return (NULL);
	}
	return (stack);
}

int	print_stack(t_stack *stack)
{
	t_node	*node;
	node = stack -> head;
	while (node -> next != stack -> head)
	{
		printf("%d ", node -> value);
		node = node -> next;
	}
	printf("%d ", node -> value);
	printf("%s\n", "");
	return (0);

}
*/
