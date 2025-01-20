/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:26:44 by mbah              #+#    #+#             */
/*   Updated: 2024/11/18 19:44:37 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_integer(va_list params, t_flags flag)
{
	int	i;
	int	len;

	(void) flag;
	i = (int) va_arg(params, int);
	ft_putnbr_fd(i, 1);
	len = 0;
	if (i == 0)
		return (1);
	if (i < 0)
		len += 1;
	while (i != 0)
	{
		i /= 10;
		len += 1;
	}
	return (len);
}
