#ifndef DRAWINGS_H
# define DRAWINGS_H
# include "cub3d.h"

void fill_background(t_game *game);
void draw_player(t_game *game); // For testing purposes, position of the player
//Vision
void draw_pov(t_game *game);
//void draw_cone(t_game *game, int length);
void draw_cone(t_game *game);

void ft_draw(t_game *game);


#endif 