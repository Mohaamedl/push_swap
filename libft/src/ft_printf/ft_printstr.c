/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddadi <mhaddadi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:23:22 by mhaddadi          #+#    #+#             */
/*   Updated: 2025/05/05 14:29:47 by mhaddadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static int	ft_print_pad(int padding, t_format *f, char *s, int len)
{
	int	count;

	count = 0;
	if (!f->flag_minus && padding > 0)
		count += ft_putnchar(' ', padding);
	if (len > 0)
		count += write(1, s, len);
	if (f->flag_minus && padding > 0)
		count += ft_putnchar(' ', padding);
	return (count);
}

int	ft_printstr(t_format *f, char *s)
{
	int	len;
	int	padding;
	int	count;
	int	is_null;

	count = 0;
	is_null = (s == NULL);
	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	if (f->precision_specified && f->precision < len)
	{
		len = f->precision;
		if (is_null && len < 6)
			len = 0;
	}
	if (f->width > len)
		padding = f->width - len;
	else
		padding = 0;
	count += ft_print_pad(padding, f, s, len);
	return (count);
}
