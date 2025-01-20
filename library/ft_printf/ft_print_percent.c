/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:48:00 by mbah              #+#    #+#             */
/*   Updated: 2024/11/18 19:17:58 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_percent(va_list params, t_flags flag)
{
	(void) params;
	(void) flag;
	ft_putchar_fd('%', 1);
	return (1);
}
