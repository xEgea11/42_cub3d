/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 17:34:43 by regea-go          #+#    #+#             */
/*   Updated: 2024/09/15 17:58:41 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	dda_ray_game(t_game *game, t_ray *ray)
{
	if (ray->orientation == EAST || ray->orientation == WEST)
	{
		ray->x_wall = game->player->x_pos
			+ (ray->side_dist_x - ray->delta_dist_x) * ray->x_dir;
		ray->y_wall = game->player->y_pos
			+ (ray->side_dist_x - ray->delta_dist_x) * ray->y_dir;
	}
	else
	{
		ray->x_wall = game->player->x_pos
			+ (ray->side_dist_y - ray->delta_dist_y)
			* ray->x_dir;
		ray->y_wall = game->player->y_pos
			+ (ray->side_dist_y - ray->delta_dist_y)
			* ray->y_dir;
	}
}

int	dda_side_dist_x(t_ray *ray, int map_x)
{
	ray->side_dist_x += ray->delta_dist_x;
	map_x += ray->step_x;
	if (ray->step_x == -1)
		ray->orientation = EAST;
	else
		ray->orientation = WEST;
	return (map_x);
}

int	dda_side_dist_y(t_ray *ray, int map_y)
{
	ray->side_dist_y += ray->delta_dist_y;
	map_y += ray->step_y;
	if (ray->step_y == -1)
		ray->orientation = SOUTH;
	else
		ray->orientation = NORTH;
	return (map_y);
}

void	init_dda(t_ray *ray)
{
	ray->x_dir = cos(ray->current_angle);
	ray->y_dir = sin(ray->current_angle);
	ray->delta_dist_x = fabs(1 / ray->x_dir);
	ray->delta_dist_y = fabs(1 / ray->y_dir);
}
