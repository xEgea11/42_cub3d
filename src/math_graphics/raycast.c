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
	ray->decimal_x = 0;
	ray->decimal_y = 0;
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

/* static void	ray_2d(t_game *game, t_ray *ray)
{
	double	i;
	double	x;
	double	y;

	i = 0;
	while (i < VISION_LENGTH)
	{
		x = (double)(game->player->x_pos
				+ i * (ray->x_end - game->player->x_pos) / VISION_LENGTH);
		y = (double)(game->player->y_pos
				+ i * (ray->y_end - game->player->y_pos) / VISION_LENGTH);
		put_pixel_ray_minimap(game, x, y);
		if (game->data->map2d_square[(int)y][(int)x] == WALL)
		{
			ray->x_wall = x;
			ray->y_wall = y;
			ray_3d(game, ray);
			return ;
		}
		i += RAY_CALCULATION_RATE;
	}
	return ;
} */

static void ray_2d_DDA(t_game *game, t_ray *ray)
{
    ray->x_dir = cos(ray->current_angle);
    ray->y_dir = sin(ray->current_angle);
    double deltaDistX = fabs(1 / ray->x_dir);
    double deltaDistY = fabs(1 / ray->y_dir);
    double sideDistX, sideDistY;
    int stepX, stepY;
    int hit = 0;
    int mapX = (int)game->player->x_pos;
    int mapY = (int)game->player->y_pos;

    if (ray->x_dir < 0) {
        stepX = -1;
        sideDistX = (game->player->x_pos - mapX) * deltaDistX;
    } else {
        stepX = 1;
        sideDistX = (mapX + 1.0 - game->player->x_pos) * deltaDistX;
    }

    if (ray->y_dir < 0) {
        stepY = -1;
        sideDistY = (game->player->y_pos - mapY) * deltaDistY;
    } else {
        stepY = 1;
        sideDistY = (mapY + 1.0 - game->player->y_pos) * deltaDistY;
    }

    while (hit == 0) {
        if (sideDistX < sideDistY) {
            sideDistX += deltaDistX;
            mapX += stepX;
            ray->orientation = (stepX == -1) ? EAST : WEST;
        } else {
            sideDistY += deltaDistY;
            mapY += stepY;
            ray->orientation = (stepY == -1) ? SOUTH : NORTH;
        }
        if (game->data->map2d_square[mapY][mapX] == WALL)
        {
            if (ray->orientation == EAST || ray->orientation == WEST) 
			{
    			ray->x_wall = game->player->x_pos + (sideDistX - deltaDistX) * ray->x_dir;
    			ray->y_wall = game->player->y_pos + (sideDistX - deltaDistX) * ray->y_dir;
			} else {
    			ray->x_wall = game->player->x_pos + (sideDistY - deltaDistY) * ray->x_dir;
	    		ray->y_wall = game->player->y_pos + (sideDistY - deltaDistY) * ray->y_dir;
			}

            // Aplicar fabs a los resultados finales para obtener las distancias absolutas
            ray->x_wall = fabs(ray->x_wall);
            ray->y_wall = fabs(ray->y_wall);

            ray_3d(game, ray);
            return;
        }
    }
}

void	raycast(t_game *game, double angle, int offset)
{
	t_ray	*ray;

	ray = init_ray();
	ray->x_end = game->player->x_pos + VISION_LENGTH * cos(angle);
	ray->y_end = game->player->y_pos + VISION_LENGTH * sin(angle);
	ray->offset = offset;
	ray->current_angle = angle;
	ray_2d_DDA(game, ray);
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
