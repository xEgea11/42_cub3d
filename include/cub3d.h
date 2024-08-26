#ifndef CUB3D_H
# define CUB3D_H
# include "MLX42.h"
# include "defines.h"
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "player.h"
# include "drawings.h"
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <time.h>  //Just for random start generation

typedef struct s_data t_player;

typedef struct s_game
{
    mlx_image_t *img;
    mlx_t       *mlx;
    t_player    *player;
    int         map[HEIGHT_MAP][WIDTH_MAP];         // For testing purposes, remove later
    double      y_scale;                        //Scalation factor, from map to screen
    double      x_scale;

}   t_game;

int init_game(t_game *game);
int end_game(t_game *game);

void create_map(t_game *game);      // For testing purposes, remove later

#endif  