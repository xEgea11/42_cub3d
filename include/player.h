#ifndef PLAYER_H
# define PLAYER_H
# include "cub3d.h"

typedef struct s_game t_game; 

typedef struct s_data
{
    double  x_pos;
    double  y_pos;
    double  angle;
    float   speed;

}   t_player;

t_player *init_player();

void move_player(mlx_key_data_t keydata, void* param);

void move_forward(t_game *game);
void move_backwards(t_game *game);
void move_left(t_game *game);
void move_right(t_game *game);

#endif 