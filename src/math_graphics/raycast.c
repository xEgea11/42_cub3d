/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 21:50:45 by regea-go          #+#    #+#             */
/*   Updated: 2024/08/31 21:50:47 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_ray	*init_ray(void)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	ray->x_wall = 0;
	ray->y_wall = 0;
	ray->current_angle = 0;
	ray->dist = 0;
	ray->offset = 0;
	ray->rays = 0;
	ray->wall_height = 0;
	ray->col_start = 0;
	ray->col_end = 0;
	ray->total_offset = 0;
	ray->texture_pos_y = 0;
	ray->texture_pos_x = 0;
	ray->orientation = 0;
	ray->relative_y = 0;
	ray->tex_x = 0;
	ray->tex_y = 0;
	return (ray);
}

static void	ray_direction(t_game *game, t_ray *ray, int map_x, int map_y)
{
	if (ray->x_dir < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (game->player->x_pos - map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (map_x + 1.0 - game->player->x_pos)
			* ray->delta_dist_x;
	}
	if (ray->y_dir < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (game->player->y_pos - map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (map_y + 1.0 - game->player->y_pos)
			* ray->delta_dist_y;
	}
}

static void	ray_2d_dda(t_game *game, t_ray *ray)
{
	int	hit;
	int	map_x;
	int	map_y;

	hit = 0;
	map_x = (int)game->player->x_pos;
	map_y = (int)game->player->y_pos;
	init_dda(ray);
	ray_direction(game, ray, map_x, map_y);
	while (hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
			map_x = dda_side_dist_x(ray, map_x);
		else
			map_y = dda_side_dist_y(ray, map_y);
		if (game->data->map2d_square[map_y][map_x] == WALL)
		{
			dda_ray_game(game, ray);
			ray->x_wall = fabs(ray->x_wall);
			ray->y_wall = fabs(ray->y_wall);
			ray_3d(game, ray);
			return ;
		}
	}
}

void	raycast(t_game *game, double angle, int offset)
{
	t_ray	*ray;

	ray = init_ray();
	ray->offset = offset;
	ray->current_angle = angle;
	ray_2d_dda(game, ray);
	free(ray);
}

void	point_of_view(t_game *game)
{
	double	angle_step;
	double	start_angle;
	double	current_angle;
	int		offset;

	angle_step = game->fov_angle / NUM_RAYS;
	start_angle = game->player->angle - game->fov_angle / 2.0;
	offset = 0;
	while (offset < NUM_RAYS)
	{
		current_angle = start_angle + offset * angle_step;
		raycast(game, current_angle, offset * game->columns_per_ray);
		offset++;
	}
}
