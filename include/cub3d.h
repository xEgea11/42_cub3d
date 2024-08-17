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

//Window size
# define WIDTH 800
# define HEIGHT 600

//Still not in use
# define MINIMAP_WIDTH WIDTH / 10
# define MINIMAP_HEIGHT HEIGHT / 10

# define VISION_LENGTH 100

typedef struct s_data t_player;

typedef struct s_game
{
    mlx_image_t *img;
    mlx_t       *mlx;
    t_player    *player;

}   t_game;


#endif  