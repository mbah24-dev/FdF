/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF_key.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 19:08:43 by mbah              #+#    #+#             */
/*   Updated: 2025/01/17 14:27:32 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_KEY_H
# define FDF_KEY_H

/* Mouvement de la caméra */
# define KEY_UP         126  // Flèche Haut
# define KEY_DOWN       125  // Flèche Bas
# define KEY_LEFT       123  // Flèche Gauche
# define KEY_RIGHT      124  // Flèche Droite

/* Zoom */
# define KEY_ZOOM_IN    69   // '+' (Shift + '=' en AZERTY)
# define KEY_ZOOM_OUT   78   // '-' (AZERTY)

/* Rotation */
# define KEY_ROT_X_UP   13   // 'z' (AZERTY)
# define KEY_ROT_X_DOWN 1    // 's'
# define KEY_ROT_Y_UP   0    // 'q'
# define KEY_ROT_Y_DOWN 2    // 'd'
# define KEY_ROT_Z_UP   6    // 'a'
# define KEY_ROT_Z_DOWN 14   // 'e'

/* Projections (Bonus) */
# define KEY_ISO        34   // 'i'
# define KEY_PARALLEL   35   // 'p'

/* Couleurs (Bonus) */
# define KEY_COLOR      8    // 'c'

/* Reset */
# define KEY_RESET      15   // 'r'

/* Quitter */
# define KEY_ESC        53   // 'Echap'

#endif