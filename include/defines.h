/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:41:39 by juguerre          #+#    #+#             */
/*   Updated: 2024/03/12 17:41:39 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

/* EXIT & ERROR MANAGE */
# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1
# define WRONG_ARG 2
# define MALLOC_ERROR 3
# define COMMAND_NULL 4
# define EXEC_ERROR "Unable to execute"

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
#define DARK_BLUE       0x00008BFF  // Dark Blue
#define LIGHT_BLUE      0xADD8E6FF  // Light Blue
#define MIDNIGHT_BLUE   0x191970FF  // Midnight Blue
#define SKY_BLUE        0x87CEEBFF  // Sky Blue

// Greens
#define DARK_GREEN      0x006400FF  // Dark Green
#define LIME_GREEN      0x32CD32FF  // Lime Green
#define PALE_GREEN      0x98FB98FF  // Pale Green
#define SEA_GREEN       0x2E8B57FF  // Sea Green

// Reds
#define DARK_RED        0x8B0000FF  // Dark Red
#define INDIAN_RED      0xCD5C5CFF  // Indian Red
#define CRIMSON         0xDC143CFF  // Crimson
#define LIGHT_CORAL     0xF08080FF  // Light Coral

// Yellows/Oranges
#define GOLD            0xFFD700FF  // Gold
#define ORANGE          0xFFA500FF  // Orange
#define DARK_ORANGE     0xFF8C00FF  // Dark Orange
#define LIGHT_YELLOW    0xFFFFE0FF  // Light Yellow

// Purples
#define DARK_MAGENTA    0x8B008BFF  // Dark Magenta
#define MEDIUM_ORCHID   0xBA55D3FF  // Medium Orchid
#define VIOLET          0xEE82EEFF  // Violet
#define PLUM            0xDDA0DDFF  // Plum

// Browns
#define SADDLE_BROWN    0x8B4513FF  // Saddle Brown
#define SIENNA          0xA0522DFF  // Sienna
#define CHOCOLATE       0xD2691EFF  // Chocolate
#define PERU            0xCD853FFF  // Peru

// Neutrals
#define WHITE           0xFFFFFFFF  // White
#define LIGHT_GRAY      0xD3D3D3FF  // Light Gray
#define GRAY            0x808080FF  // Gray
#define BLACK           0x000000FF  // Black


#endif