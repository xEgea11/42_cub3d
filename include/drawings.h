#ifndef DRAWINGS_H
# define DRAWINGS_H
# include "cub3d.h"

/* COLOR CONVERSION */
uint32_t rgb_to_hex(char *str);

/* DRAWING UTILS */
void put_pixel_minimap(t_game *game, int x, int y);
void fill_background(t_game *game);
void draw_square_minimap(t_game *game, int player_x, int player_y) ;
double abs_min(double a, double b);


/* MAIN DRAWINGS FUNCTIONS */
void fill_background_minimap(t_game *game);
void draw_player_minimap(t_game *game); // For testing purposes, position of the player

int raycast_algorithm(t_game *game, double angle, int iteration);
void point_of_view(t_game *game);

void render_screen(t_game *game);

/* 3D WORLD DRAWINGS */
void draw_ceiling_3d(t_game *game);
void draw_floor_3d(t_game *game);
void fill_background_3d(t_game *game);
void render_obstacle_3d(t_game *game, int iteration, double distance, int wall); // double delta_x, double delta_y, int wall);
void put_pixel_raycast(t_game *game, double x, double y);
void single_raycast_to_3d(t_game *game, double x, double y, int iteration);

#endif 