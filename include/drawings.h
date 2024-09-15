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
	double		x_dir;
	double		y_dir;
	double		x_wall;
	double		y_wall;
	double		current_angle;
	double		dist;
	double		delta_dist_x;
	double		delta_dist_y;
	double		side_dist_x;
	double		side_dist_y;
	int			step_x;
	int			step_y;
	// 3D
	int			offset;
	double		rays;
	double		total_offset;
	double		wall_height;
	int			col_start;
	int			col_end;
	// Texture
	double		texture_pos_y;
	double		texture_pos_x;
	int			orientation;
	double		relative_y;
	uint32_t	tex_x;
	uint32_t	tex_y;
}				t_ray;

/* DRAWING UTILS */
void		fill_background(t_game *game);
void		draw_square_minimap(t_game *game, int player_x, int player_y);
double		abs_min(double a, double b);
double		ft_distance(t_game *game, double x, double y);

/* MAIN DRAWINGS FUNCTIONS */
void		draw_minimap(t_game *game);
void		draw_player_minimap(t_game *game);
void		raycast(t_game *game, double angle, int iter);
void		point_of_view(t_game *game);
void		render_screen(t_game *game);

/* RAY UTILS */
void		ft_set_ray_values(t_game *game, t_ray *ray);
void		ft_set_orientation(t_ray *ray);
void		put_pixel_ray_minimap(t_game *game, double x, double y);

/* 3D WORLD DRAWINGS */
void		draw_ceiling_3d(t_game *game);
void		draw_floor_3d(t_game *game);
void		fill_background_3d(t_game *game);
void		columns(t_game *game, t_ray *ray);
void		ray_3d(t_game *game, t_ray *ray);

/* DDA */
void		dda_ray_game(t_game *game, t_ray *ray);
int			dda_side_dist_x(t_ray *ray, int map_x);
int			dda_side_dist_y(t_ray *ray, int map_y);
void		init_dda(t_ray *ray);

#endif 