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

typedef struct s_ray
{
	double	x_wall;
	double	y_wall;
	double	current_angle;
	double	x_end;
	double	y_end;
	double	dist;
	double	decimal_x;
	double	decimal_y;
	// 3D
	int		offset;
	double	wall_height;
	int		col_start;
	int		col_end;
	// Texture
	double	texture_pos;
	double	relative_y;
	double	tex_x;
	double	tex_y;
}				t_ray;

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

void		raycast(t_game *game, double angle, int iter);
void		point_of_view(t_game *game);

void		render_screen(t_game *game);

/* 3D WORLD DRAWINGS */
void		draw_ceiling_3d(t_game *game);
void		draw_floor_3d(t_game *game);
void		fill_background_3d(t_game *game);
void		draw_cols_3d(t_game *game, t_ray *ray, int x_offset, double y_iter, int wall, double texture_pos);// int x, double y, int wall, double wall_h, double y_const, double texture_pos);
void		put_pixel_ray_minimap(t_game *game, double x, double y);
void		ray_3d(t_game *game, t_ray *ray);// double x, double y, int offset);
void		columns(t_game *game, t_ray *ray, int wall, double texture_pos);

#endif 