/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddadi <mhaddadi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 20:56:00 by mhaddadi          #+#    #+#             */
/*   Updated: 2025/08/07 20:56:00 by mhaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static int	validate_number_range(long num, int sign)
{
	if ((sign == 1 && num > INT_MAX) || (sign == -1 && - num < INT_MIN))
		return (0);
	return (1);
}

static int	parse_sign(const char *s, int *i)
{
	int	sign;

	sign = 1;
	if (s[*i] == '-' || s[*i] == '+')
	{
		if (s[(*i)++] == '-')
			sign = -1;
	}
	return (sign);
}

static int	validate_digits(const char *s, int start)
{
	long	num;
	int		i;
	int		sign;

	sign = parse_sign(s, &start);
	if (!s[start])
		return (0);
	num = 0;
	i = start;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		num = num * 10 + (s[i] - '0');
		if (!validate_number_range(num, sign))
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_integer(const char *s)
{
	int	i;

	if (!s || *s == '\0')
		return (0);
	i = 0;
	return (validate_digits(s, i));
}
