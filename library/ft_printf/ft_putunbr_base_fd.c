/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_base_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:50:34 by mbah              #+#    #+#             */
/*   Updated: 2024/11/23 17:11:48 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_isblank(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

static int	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (ft_isblank(base[i]))
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	return (i);
}

static void	ft_putunbr_recursive(unsigned long nbr, char *base, int fd)
{
	int	base_len;

	base_len = ft_strlen(base);
	if (nbr > 0)
	{
		ft_putunbr_recursive(nbr / base_len, base, fd);
		ft_putchar_fd(base[nbr % base_len], fd);
	}
}

void	ft_putunbr_base_fd(unsigned long nbr, char *base, int fd)
{
	int		base_len;

	base_len = ft_check_base(base);
	if (base_len)
	{
		if (nbr == 0)
			ft_putchar_fd(base[0], fd);
		else
			ft_putunbr_recursive(nbr, base, fd);
	}
}
