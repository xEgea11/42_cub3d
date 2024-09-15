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
	double		x_wall;
	double		y_wall;
	double		current_angle;
	double		x_end;
	double		y_end;
	double		dist;
	double		decimal_x;
	double		decimal_y;
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

/* 3D WORLD DRAWINGS */
void		draw_ceiling_3d(t_game *game);
void		draw_floor_3d(t_game *game);
void		fill_background_3d(t_game *game);
void		draw_cols_3d(t_game *game, t_ray *ray, double y_iter);
void		columns(t_game *game, t_ray *ray);
void		ray_3d(t_game *game, t_ray *ray);

#endif 