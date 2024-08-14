#ifndef PLAYER_H
# define PLAYER_H
# include "cub3d.h"

typedef struct s_game t_game; 

typedef struct s_data
{
    double x;
    double y;
    double angle;

}   t_player;

t_player *init_player();
void move_player(mlx_key_data_t keydata, void* param);
void draw_square(t_game *game);

#endif 