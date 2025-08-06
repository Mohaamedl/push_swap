/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rrr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddadi <mhaddadi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 23:20:47 by mhaddadi          #+#    #+#             */
/*   Updated: 2025/07/20 23:20:57 by mhaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int		rra(t_stack *a)
{
	reverse_rotate_stack(a);
	ft_printf("rra%s\n","");
	return (1);
}

int		rrb(t_stack *b)
{
	reverse_rotate_stack(b);
	ft_printf("rrb%s\n","");
	return (1);
}

int		rrr(t_stack *a, t_stack *b)
{
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
	ft_printf("rrr%s\n","");
	return (1);
}
