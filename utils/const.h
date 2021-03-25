/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakouer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 17:17:48 by etakouer          #+#    #+#             */
/*   Updated: 2021/03/25 08:05:22 by etakouer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_H
# define CONST_H

# define ERR_ARGS "Usage <file name> [--save]"
# define ERR_FILE "Not a .cub file"
# define ERR_MAP ".cub : Map mistake"
# define ERR_CONF ".cub : Configuration mistake"
# define DEBUG 0
# define DRAWMAP 1
# define RATMAP 0.35

# define WALL 1
# define SPIRIT 2
# define EMPTY 0
# define GAMER 3
# define NB_PARAM 8
# define NBSP 100
# define NBPX 1920
# define NBLINE 200
# define MAX_W 1920
# define MAX_H 1080
# define TRSP 1

# define WHITE 0xFFFFFF
# define YELLOW 0xFFFF00
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define ORANGE 0xE07120
# define NONE 0xFF000000
# define GRAY 0xCCCCCC

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_ESC 53
# define KEY_LEFT 123
# define KEY_RIGHT 124

# define STEP_DIR 0.17453292519943295 // M_PI / 18.0
# define STEP_MOVE 0.2
# define STEP 1.5

# define FOV 1.0471975511965976 // M_PI / 3.0
# define MFOV 0.5235987755982988 //M_PI / 6.0

# define BETA 10e-10
# define BIGN 10e10
# define BSIZE 64

#endif
