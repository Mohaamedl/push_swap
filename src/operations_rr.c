/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddadi <mhaddadi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 23:21:14 by mhaddadi          #+#    #+#             */
/*   Updated: 2025/07/20 23:21:22 by mhaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		ra(t_stack *a)
{
	rotate_stack(a);
	printf("ra%s\n", "");
	return (1);
}

int		rb(t_stack *b)
{
	rotate_stack(b);
	printf("rb%s\n", "");
	return (1);
}

int		rr(t_stack *a, t_stack *b)
{
	rotate_stack(a);
	rotate_stack(b);
	printf("rr%s\n", "");
	return (1);
}

