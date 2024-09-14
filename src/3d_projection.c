/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_projection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 21:49:52 by regea-go          #+#    #+#             */
/*   Updated: 2024/08/31 21:49:58 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static uint32_t	get_pixel_color(t_game *game, char *key, uint32_t x, uint32_t y)
{
	t_txtr			*tmp;
	uint32_t		i;
	mlx_texture_t	*texture;
	uint8_t			*pixel;
	uint32_t		color;

	i = 0;
	tmp = game->data->t;
	while (i < 4)
	{
		if (ft_strncmp(tmp->key, key, 2) == 0)
		{
			texture = tmp->img;
			if (x >= texture->width || y >= texture->height)
				return (0);
			pixel = &texture->pixels[(y * texture->width + x) * 4];
			color = (pixel[0] << 24) | (pixel[1] << 16)
				| (pixel[2] << 8) | pixel[3];
			return (color);
		}
		tmp = tmp->next;
		i++;
	}
	return (0);
}

void	draw_cols_3d(t_game *game, t_ray *ray, int x_offset, double y_iter, int wall, double texture_pos)
{
	int		color;

	ray->relative_y = ((y_iter - ray->col_start)) / ray->wall_height;
	ray->tex_x = texture_pos * TEXTURE_WIDTH;
	ray->tex_y = (int)(ray->relative_y * TEXTURE_HEIGHT);
	if (wall == WEST)
		color = get_pixel_color(game, "WE", ray->tex_x, ray->tex_y);
	else if (wall == EAST)
		color = get_pixel_color(game, "EA", ray->tex_x, ray->tex_y);
	else if (wall == NORTH)
		color = get_pixel_color(game, "NO", ray->tex_x, ray->tex_y);
	else if (wall == SOUTH)
		color = get_pixel_color(game, "SO", ray->tex_x, ray->tex_y);
	mlx_put_pixel(game->img, x_offset, y_iter, color);
}

void	columns(t_game *game, t_ray *ray, int wall, double texture_pos)
{
	double	rays;
	double	y_iter;

	rays = 0.0;
	while (rays < game->columns_per_ray)
	{
		ray->col_start = (int)(HEIGHT / 2.0 - ray->wall_height / 2.0);
		ray->col_end = (int)(HEIGHT / 2.0 + ray->wall_height / 2.0);
		if (ray->col_start < 0)
			ray->col_start = 0;
		y_iter = ray->col_start;
		if (ray->col_end > HEIGHT)
			ray->col_end = HEIGHT;
		while (y_iter < ray->col_end)
		{
			draw_cols_3d(game, ray, round(rays + ray->offset), y_iter, wall, texture_pos);
			y_iter++;
		}
		rays += 1.0;
	}
}

void	ray_3d(t_game *game, t_ray *ray)
{

	ray->dist = ft_distance(game, ray->x_wall, ray->y_wall);
	ray->wall_height = MAX_WALL_HEIGHT / (ray->dist);
	ray->decimal_x = ray->x_wall - round(ray->x_wall);
	ray->decimal_y = ray->y_wall - round(ray->y_wall);

	if (abs_min(ray->decimal_x, ray->decimal_y) == fabs(ray->decimal_x)
		&& ray->decimal_x > 0)
		columns(game, ray, WEST, ray->y_wall - floor(ray->y_wall));
	else if (abs_min(ray->decimal_x, ray->decimal_y) == fabs(ray->decimal_x)
		&& ray->decimal_x < 0)
		columns(game, ray, EAST, ray->y_wall - floor(ray->y_wall));
	else if (abs_min(ray->decimal_x, ray->decimal_y) == fabs(ray->decimal_y)
		&& ray->decimal_y > 0)
		columns(game, ray, NORTH, ray->x_wall - floor(ray->x_wall));
	else if (abs_min(ray->decimal_x, ray->decimal_y) == fabs(ray->decimal_y)
		&& ray->decimal_y < 0)
		columns(game, ray, SOUTH, ray->x_wall - floor(ray->x_wall));
}

