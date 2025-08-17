/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddadi <mhaddadi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 20:53:00 by mhaddadi          #+#    #+#             */
/*   Updated: 2025/08/07 20:53:00 by mhaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static int	is_empty_or_whitespace(const char *str)
{
	int	i;

	if (!str)
		return (1);
	i = 0;
	while (str[i])
	{
		if (!ft_isspace(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	check_duplicate_in_split(char **split, char *val, int word_j)
{
	int	j;
	int	val_num;
	int	split_num;

	if (!is_valid_integer(val))
		return (0);
	val_num = ft_atoi(val);
	j = 0;
	while (split[j])
	{
		if (j != word_j && is_valid_integer(split[j]))
		{
			split_num = ft_atoi(split[j]);
			if (val_num == split_num)
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

	if (!val || is_empty_or_whitespace(val))
		return (1);
	i = 1;
	while (argv[i])
	{
		if (!is_empty_or_whitespace(argv[i]))
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
		}
		i++;
	}
	return (0);
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

void	cleanup_all(t_stack *a, t_stack *b, char **split)
{
	free_stack(a);
	free_stack(b);
	free(a);
	free(b);
	if (split)
		free_split(split);
}
