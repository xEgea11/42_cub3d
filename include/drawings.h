#ifndef DRAWINGS_H
# define DRAWINGS_H
# include "cub3d.h"

void fill_background(mlx_image_t* img, int height, int width, uint32_t color);
void draw_player(t_game *game); // For testing purposes, position of the player
//Vision
void draw_pov(mlx_image_t* img, t_player *player, int length);
void draw_cone(mlx_image_t *img, t_player *player, int length);

void ft_draw(t_game *game, int length);


#endif 