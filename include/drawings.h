/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:04:23 by regea-go          #+#    #+#             */
/*   Updated: 2024/09/13 16:04:23 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAWINGS_H
# define DRAWINGS_H
# include "cub3d.h"

/* COLOR CONVERSION */
uint32_t	rgb_to_hex(char *str);

/* DRAWING UTILS */
void		put_pixel_minimap(t_game *game, int x, int y);
void		fill_background(t_game *game);
void		draw_square_minimap(t_game *game, int player_x, int player_y);
double		abs_min(double a, double b);
double		ft_distance(t_game *game, double x, double y);

/* MAIN DRAWINGS FUNCTIONS */
void		fill_background_minimap(t_game *game);
void		draw_player_minimap(t_game *game);

int			raycast_algorithm(t_game *game, double angle, int iter);
void		point_of_view(t_game *game);

void		render_screen(t_game *game);

/* 3D WORLD DRAWINGS */
void		draw_ceiling_3d(t_game *game);
void		draw_floor_3d(t_game *game);
void		fill_background_3d(t_game *game);
void		render_obstacle_3d(t_game *game, int iter, double dist, int wall);
void		orient_3d(t_game *game, int x, double y, int wall, double wall_h, double y_const);
void		put_pixel_raycast(t_game *game, double x, double y);
void		one_ray_3d(t_game *game, double x, double y, int iter);
void		columns(t_game *game, double wall_h, double offset_x, int wall);

#endif 