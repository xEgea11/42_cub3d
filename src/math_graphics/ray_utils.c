/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 03:06:25 by regea-go          #+#    #+#             */
/*   Updated: 2024/09/15 17:30:17 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_set_ray_values(t_game *game, t_ray *ray)
{
	ray->dist = ft_distance(game, ray->x_wall, ray->y_wall);
	ray->wall_height = MAX_WALL_HEIGHT / (ray->dist);
	ray->texture_pos_y = ray->y_wall - floor(ray->y_wall);
	ray->texture_pos_x = ray->x_wall - floor(ray->x_wall);
}
