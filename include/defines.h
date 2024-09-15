/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:41:39 by juguerre          #+#    #+#             */
/*   Updated: 2024/08/31 21:57:36 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

/* MINIMAP SIZE*/
# define MINIMAP_WIDTH 500
# define MINIMAP_HEIGHT 250

/* MAP SIZE */
# define WIDTH 2048
# define HEIGHT 1024

/* PLAYER */
/* Distance at each button pressed */
# define SPEED_PLAYER 0.05
# define ANGLE_MODIFIER 0.025

# define VISION_LENGTH 10
# define VISION_ANGLE 90
# define NUM_RAYS 350
# define RAY_CALCULATION_RATE 0.01

/* TEXTURE */
# define TEXTURE_WIDTH 512
# define TEXTURE_HEIGHT 512

/* ORIENTATION */
# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3

/* ELEMENTS */
# define EMPTY '0'
# define WALL '1'
# define OUT_OF_BOUNDS ' '

/* OPCODES FOR MOVEMENT */
# define LEFT 0
# define RIGHT 1

/* 3D MACROS */
# define MAX_WALL_HEIGHT 700

/* EXIT & ERROR MANAGE */
# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1
# define WRONG_ARG 2
# define MALLOC_ERROR 3
# define COMMAND_NULL 4
# define WRONG_FILE 5
# define EMPTY_FILE 6
# define EXEC_ERROR "Unable to execute"
# define MALLOC_ERR "Memory allocation failed"

/* FILE DESCRIPTORS */
# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define NO_FD -2

/* BOOLEAN */
# define TRUE 1
# define FALSE 0

/* COLORS */
// Blues
# define DARK_BLUE       0x00008BFF
# define LIGHT_BLUE      0xADD8E6FF
# define MIDNIGHT_BLUE   0x191970FF
# define SKY_BLUE        0x87CEEBFF

// Greens
# define DARK_GREEN      0x006400FF
# define LIME_GREEN      0x32CD32FF
# define PALE_GREEN      0x98FB98FF
# define SEA_GREEN       0x2E8B57FF

// Reds
# define DARK_RED        0x8B0000FF
# define INDIAN_RED      0xCD5C5CFF
# define CRIMSON         0xDC143CFF
# define LIGHT_CORAL     0xF08080FF

// Yellows/Oranges
# define GOLD            0xFFD700FF
# define DARK_ORANGE     0xFF8C00FF
# define LIGHT_YELLOW    0xFFFFE0FF

// Purples
# define DARK_MAGENTA    0x8B008BFF
# define MEDIUM_ORCHID   0xBA55D3FF
# define VIOLET          0xEE82EEFF
# define PLUM            0xDDA0DDFF

// Browns
# define SADDLE_BROWN    0x8B4513FF
# define SIENNA          0xA0522DFF
# define CHOCOLATE       0xD2691EFF
# define PERU            0xCD853FFF

// Neutrals
# define WHITE           0xFFFFFFFF
# define LIGHT_GRAY      0xD3D3D3FF
# define GRAY            0x808080FF
# define BLACK           0x000000FF

# define FLOOR_MINIMAP   MIDNIGHT_BLUE
# define WALL_MINIMAP    BLACK
# define VISION_MINIMAP  PLUM

/* STR COLORS */
# define GREEN           "\033[0;32m"
# define RED             "\033[0;31m"
# define YELLOW          "\033[0;33m"
# define BLUE            "\033[0;34m"
# define ORANGE          "\033[0;33m"
# define RESET           "\033[0m"

#endif