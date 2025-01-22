/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.map.init_point.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:05:22 by mbah              #+#    #+#             */
/*   Updated: 2025/01/22 15:57:26 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

char	*ft_strcat(char *s1, char *s2)
{
	int		i;
	char	*res;
	size_t	len;

	i = -1;
	len = ft_strlen(s1) + ft_strlen(s2);
	res = (char *) malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (s1[++i])
		res[i] = s1[i];
	i = -1;
	len = ft_strlen(s1);
	while (s2[++i])
		res[i + len] = s2[i];
	res[i + len] = '\0';
	return (res);
}
