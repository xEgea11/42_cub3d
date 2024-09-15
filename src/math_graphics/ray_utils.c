/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 03:06:25 by regea-go          #+#    #+#             */
/*   Updated: 2024/09/15 11:05:30 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_set_ray_values(t_game *game, t_ray *ray)
{
	ray->dist = ft_distance(game, ray->x_wall, ray->y_wall);
	ray->wall_height = MAX_WALL_HEIGHT / (ray->dist * 1.5);
	ray->decimal_x = ray->x_wall - round(ray->x_wall);
	ray->decimal_y = ray->y_wall - round(ray->y_wall);
	ray->texture_pos_y = ray->y_wall - floor(ray->y_wall);
	ray->texture_pos_x = ray->x_wall - floor(ray->x_wall);
}

void	ft_set_orientation(t_ray *ray)
{
	double	min;

	min = abs_min(ray->decimal_x, ray->decimal_y);
	if (min == fabs(ray->decimal_x) && ray->decimal_x > 0)
		ray->orientation = WEST;
	else if (min == fabs(ray->decimal_x) && ray->decimal_x < 0)
		ray->orientation = EAST;
	else if (min == fabs(ray->decimal_y) && ray->decimal_y > 0)
		ray->orientation = NORTH;
	else if (min == fabs(ray->decimal_y) && ray->decimal_y < 0)
		ray->orientation = SOUTH;
}
