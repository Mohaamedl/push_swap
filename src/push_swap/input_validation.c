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
