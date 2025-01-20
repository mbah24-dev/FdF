/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:14:54 by mbah              #+#    #+#             */
/*   Updated: 2024/12/15 15:07:16 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_iscflags(const char flag)
{
	return (ft_strchr("cspdiuxX%", flag) != 0);
}

static int	ft_printf_choose(va_list params, t_flags flag)
{
	int	(*print_arr[128])(va_list, t_flags);

	print_arr['c'] = &ft_print_char;
	print_arr['d'] = &ft_print_decimal;
	print_arr['x'] = &ft_print_hexadec;
	print_arr['X'] = &ft_print_hexadec;
	print_arr['i'] = &ft_print_integer;
	print_arr['%'] = &ft_print_percent;
	print_arr['p'] = &ft_print_ptr;
	print_arr['s'] = &ft_print_string;
	print_arr['u'] = &ft_print_udecimal;
	return (print_arr[(int) flag.type](params, flag));
}

int	ft_printf(const char *format, ...)
{
	va_list	params;
	int		size;
	int		i;
	t_flags	flag;

	i = -1;
	size = 0;
	if (format == NULL)
		return (-1);
	va_start(params, format);
	while (format[++i])
	{
		if (format[i] == '%' && ft_iscflags(format[i + 1]))
		{
			flag.type = format[i + 1];
			size += ft_printf_choose(params, flag);
			i += 1;
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			size += 1;
		}
	}
	return (va_end(params), size);
}
