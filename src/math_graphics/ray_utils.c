/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 03:06:25 by regea-go          #+#    #+#             */
/*   Updated: 2024/09/17 12:43:20 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static double	corrected_dist(double ray_angle,
double player_angle, double dist)
{
	return (dist * cos(ray_angle - player_angle));
}

void	ft_set_ray_values(t_game *game, t_ray *ray)
{
	double		c_a;
	double		p_a;
	double		distance;

	distance = ft_distance(game, ray->x_wall, ray->y_wall);
	c_a = ray->current_angle;
	p_a = game->player->angle;
	ray->dist = corrected_dist(c_a, p_a, distance);
	ray->wall_height = MAX_WALL_HEIGHT / (ray->dist * 1.5);
	ray->texture_pos_y = ray->y_wall - floor(ray->y_wall);
	ray->texture_pos_x = ray->x_wall - floor(ray->x_wall);
}
