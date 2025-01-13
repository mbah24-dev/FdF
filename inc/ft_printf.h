/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 22:06:52 by mbah              #+#    #+#             */
/*   Updated: 2025/01/09 22:33:24 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

struct	s_flags
{
	char	type;
};

typedef struct s_flags	t_flags;

void	ft_putunbr_fd(unsigned int nbr, int fd);
void	ft_putunbr_base_fd(unsigned long nbr, char *base, int fd);

int		ft_printf(const char *format, ...);
int		ft_print_char(va_list params, t_flags flag);
int		ft_print_string(va_list params, t_flags flag);
int		ft_print_ptr(va_list params, t_flags flag);
int		ft_print_decimal(va_list params, t_flags flag);
int		ft_print_integer(va_list params, t_flags flag);
int		ft_print_udecimal(va_list params, t_flags flag);
int		ft_print_hexadec(va_list params, t_flags flag);
int		ft_print_percent(va_list params, t_flags flag);

#endif