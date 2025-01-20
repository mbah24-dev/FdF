/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:48:23 by mbah              #+#    #+#             */
/*   Updated: 2025/01/09 18:29:21 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunbr_fd(unsigned int nbr, int fd)
{
	if (nbr > 9)
	{
		ft_putunbr_fd(nbr / 10, fd);
		ft_putunbr_fd(nbr % 10, fd);
	}
	else
		ft_putchar_fd(nbr + 48, fd);
}
