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
void move_forward(t_player *player);
void move_backward(t_player *player);
void move_left(t_player *player);
void move_right(t_player *player);

void draw_square(t_game *game);
void ft_draw(t_game *game, int length);

//Vision
void draw_pov(mlx_image_t* img, t_player *player, int length);
void draw_cone(mlx_image_t *img, t_player *player, int length);


#endif 