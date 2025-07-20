/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddadi <mhaddadi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 06:45:36 by mhaddadi          #+#    #+#             */
/*   Updated: 2025/07/14 07:01:21 by mhaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"
#include <stdio.h>
int print_stack(t_stack *stack);

int	main(int argc, char ** argv)
{
	int				i;
	t_stack		*a;
	t_stack		*b;
	t_node		*node;

	if (argc == 1)
		return (0);
	else if (argc >= 2)
	{
		i = 0;
		a = (t_stack *) malloc(sizeof(t_stack));
		b = (t_stack *) malloc(sizeof(t_stack));

		init_stack(a, 'a');
		init_stack(b, 'b');
		while (argc > ++i)
		{
			node = create_node(ft_atoi(argv[i]));
			push(a,node);
			printf("%d\n", ft_atoi(argv[i]));
		}
		normalize(a);
		printf("is sorted before: %d\n", is_sorted(a));
		chunk_sort(a,b, 5);
		printf("is sorted after: %d\n", is_sorted(a));
		print_stack(a);
		return (1);
	}
	else
		return (0);
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
*/
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
