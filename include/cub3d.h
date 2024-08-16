#ifndef CUB3D_H
# define CUB3D_H
# include "MLX42.h"
# include "defines.h"
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "player.h"
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>

# define WIDTH 800
# define HEIGHT 600

# define MINIMAP_WIDTH WIDTH / 10
# define MINIMAP_HEIGHT HEIGHT / 10

# define TRUE 1
# define FALSE 0

# define VISION_LENGTH 200

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


typedef struct s_data t_player;

typedef struct s_game
{
    mlx_image_t *img;
    mlx_t       *mlx;
    t_player    *player;

}   t_game;


#endif  