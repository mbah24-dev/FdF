/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:21:20 by mbah              #+#    #+#             */
/*   Updated: 2024/11/21 22:27:50 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(va_list params, t_flags flag)
{
	char	c;

	(void) flag;
	c = (char) va_arg(params, int);
	ft_putchar_fd(c, 1);
	return (1);
}
