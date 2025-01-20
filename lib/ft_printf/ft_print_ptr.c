/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:37:35 by mbah              #+#    #+#             */
/*   Updated: 2024/11/23 17:11:29 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(va_list params, t_flags flag)
{
	void			*ptr;
	int				size;
	unsigned long	addr;

	(void) flag;
	ptr = (void *) va_arg(params, void *);
	addr = (unsigned long) ptr;
	ft_putstr_fd("0x", 1);
	ft_putunbr_base_fd(addr, "0123456789abcdef", 1);
	size = 0;
	if (addr == 0)
		return (3);
	while (addr != 0)
	{
		addr /= 16;
		size += 1;
	}
	return (size + 2);
}
