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

#include "../inc/push_swap.h"
//#include "../libft/libft.h"
#include "../libft/inc/libft.h"
#include "../libft/inc/ft_printf.h"
#include <stdio.h>

//static int print_stack(t_stack *stack);

static int	is_valid_integer(char *s);

//static int	has_duplicate(char **argv, int current_index, int argc);

int	fill_stack(t_stack *a, char **argv, int argc);

void free_split(char **arr)
{
    int i = 0;
    if (!arr) return;
    while (arr[i])
        free(arr[i++]);
    free(arr);
}

int has_duplicate_str(char **argv, char *val, int arg_i, int word_j)
{
    int i = 1; // começar no primeiro argumento real
    while (argv[i])
    {
        char **split = ft_split(argv[i], ' ');
        if (!split)
            return 1; 

        int j = 0;
        while (split[j])
        {
            // Ignorar o valor atual (arg_i, word_j)
            if (i == arg_i && j == word_j)
            {
                j++;
                continue;
            }
            if (ft_strncmp(split[j], val, ft_strlen(val)) == 0)
            {
                free_split(split);
                return 1;
            }
            j++;
        }
        free_split(split);
        i++;
    }
    return 0;
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
	if (is_sorted(a) == 0)
		chunk_sort(a, b, 15);
	free_stack(a);
	free_stack(b);
	return (0);
}
/*
int	fill_stack(t_stack *a, t_stack *b, char **argv, int argc)
{
	int		i;
	t_node	*node;

	i = argc;
	while (--i > 0)
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

*/

int	fill_stack(t_stack *a, char **argv, int argc)
{
	char	**split;
	t_node	*node;
	int		i, j;

	i = argc;
	while (--i > 0)
	{
		split = ft_split(argv[i], ' ');
		if (!split || !*split)
			return (write(2, "Error\n", 6), free_split(split), 0);
		j = -1;
		while (split[++j])
		{
			if (!is_valid_integer(split[j]) || has_duplicate_str(argv, split[j], i, j))
				return (write(2, "Error\n", 6), free_split(split), 0);
			node = create_node(ft_atoi(split[j]));
			if (!node)
				return (write(2, "Error\n", 6), free_split(split), 0);
			push(a, node);  // Ordem invertida: último no topo
		}
		free_split(split);
	}
	return (a->size > 0);
}

static int	is_valid_integer(char *s)
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
/*
static int	has_duplicate(char **argv, int current_index, int argc)
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
