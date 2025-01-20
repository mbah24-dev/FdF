/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexadec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:49:37 by mbah              #+#    #+#             */
/*   Updated: 2024/11/23 16:13:00 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexadec(va_list params, t_flags flag)
{
	unsigned int	value;
	int				size;

	value = (unsigned int) va_arg(params, unsigned int);
	if (flag.type == 'x')
		ft_putunbr_base_fd(value, "0123456789abcdef", 1);
	if (flag.type == 'X')
		ft_putunbr_base_fd(value, "0123456789ABCDEF", 1);
	size = 0;
	if (value == 0)
		return (1);
	while (value != 0)
	{
		value /= 16;
		size += 1;
	}
	return (size);
}
