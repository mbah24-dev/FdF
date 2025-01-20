/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_udecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:51:18 by mbah              #+#    #+#             */
/*   Updated: 2024/11/23 16:16:05 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_udecimal(va_list params, t_flags flag)
{
	int				size;
	unsigned int	nbr;

	(void) flag;
	nbr = (unsigned int) va_arg(params, unsigned int);
	ft_putunbr_fd(nbr, 1);
	if (nbr == 0)
		return (1);
	size = 0;
	while (nbr != 0)
	{
		nbr /= 10;
		size += 1;
	}
	return (size);
}
