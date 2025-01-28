/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linux_keys.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 23:01:04 by mbah              #+#    #+#             */
/*   Updated: 2025/01/28 16:24:11 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINUX_KEYS_H
# define LINUX_KEYS_H

# define ARROW_RIGHT        65363
# define ARROW_DOWN         65364
# define ARROW_LEFT         65361
# define ARROW_UP           65362
# define PLUS               61
# define MINUS              45
# define ENTER              65293
# define RESET_KEY          114
# define MOUSE_CLICK_RIGHT  -1
# define MOUSE_CLICK_MIDDLE -1
# define MOUSE_CLICK_LEFT   -1
# define MOUSE_WHEEL_DOWN   5
# define MOUSE_WHEEL_UP     4
# define ESCAPE             65307

# define EVENT_KEY_PRESS       2
# define EVENT_KEY_RELEASE     3
# define EVENT_MOUSE_DOWN      4
# define EVENT_MOUSE_UP        5
# define EVENT_MOUSE_MOVE      6
# define EVENT_DESTROY         17

# define X_KEY					5
# define Y_KEY					6
# define Z_KEY					17

# define MASK_KEY_PRESS        (1L << 0)
# define MASK_KEY_RELEASE      (1L << 1)
# define MASK_BUTTON_PRESS     (1L << 2)
# define MASK_BUTTON_RELEASE   (1L << 3)
# define MASK_POINTER_MOTION   (1L << 6)
# define MASK_STRUCTURE_NOTIFY (1L << 17)

X : 53
Y : 29
Z : 52

#endif
