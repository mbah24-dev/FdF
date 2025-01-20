/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:44:43 by mbah              #+#    #+#             */
/*   Updated: 2024/11/22 14:56:41 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_decimal(va_list params, t_flags flag)
{
	int	dec;
	int	len;

	(void) flag;
	dec = (int) va_arg(params, int);
	ft_putnbr_fd(dec, 1);
	len = 0;
	if (dec == 0)
		return (1);
	if (dec < 0)
		len += 1;
	while (dec != 0)
	{
		dec /= 10;
		len += 1;
	}
	return (len);
}
