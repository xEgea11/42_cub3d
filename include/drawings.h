#ifndef DRAWINGS_H
# define DRAWINGS_H
# include "cub3d.h"

#define FOV_ANGLE (60.0 * M_PI / 180.0)  // 60 degrees in radians
#define NUM_RAYS 500  // Number of rays to cast

void fill_background(t_game *game);
void draw_player(t_game *game); // For testing purposes, position of the player
//Vision
void draw_pov(t_game *game);
//void draw_cone(t_game *game, int length);
void draw_cone(t_game *game);

void ft_draw(t_game *game);


#endif 