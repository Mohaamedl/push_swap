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

static int	has_only_digits_and_sign(const char *str)
{
	int	i;
	int	has_digit;

	i = 0;
	has_digit = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		has_digit = 1;
		i++;
	}
	return (has_digit);
}

static int	is_in_int_range(const char *str)
{
	long	num;

	num = ft_atol(str);
	return (num >= INT_MIN && num <= INT_MAX);
}

int	is_valid_integer(const char *s)
{
	if (!s || *s == '\0')
		return (0);
	if (!has_only_digits_and_sign(s))
		return (0);
	return (is_in_int_range(s));
}
