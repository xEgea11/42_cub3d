#ifndef CUB3D_H
# define CUB3D_H
# include "MLX42.h"
# include "player.h"
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>

# define WIDTH 800
# define HEIGHT 600

#define TRUE 1

typedef struct s_data t_player;

typedef struct s_game
{
    mlx_image_t *img;
    mlx_t       *mlx;
    t_player    *player;

}   t_game;

         //<----- move to player.h somehow; it gives an error
#endif  