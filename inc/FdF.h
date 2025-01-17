/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:25:47 by mbah              #+#    #+#             */
/*   Updated: 2025/01/17 17:56:00 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "ft_printf.h"
# include "libft.h"
# include "FdF_utils.h"
# include "FdF_key.h"
# include <stdio.h>
# include <time.h>

typedef struct s_vars
{
	void		*mlx;
	void		*mlx_win;
	t_data		image;
	t_point		circle_pos;
	int			keycode;
	t_sprite	moquette;
}				t_vars;

typedef enum e_flag
{
	OK = 1,
	ERROR = 0
}	t_flag;

int	close_win(t_vars *vars);

#endif
