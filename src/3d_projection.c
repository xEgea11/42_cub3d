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

void	orient_3d(t_game *game, int x, double y, int wall, double wall_h, double y_const)
{
	double	tex_x;
	double	tex_y;
	int		color;
	double	relative_y;

	relative_y = ((y - y_const)) / wall_h;
	tex_x = x % TEXTURE_WIDTH;
	tex_y = (int)(relative_y * TEXTURE_HEIGHT);
	if (wall == WEST)
		color = get_pixel_color(game, "WE", tex_x, tex_y);
	else if (wall == EAST)
		color = get_pixel_color(game, "EA", tex_x, tex_y);
	else if (wall == NORTH)
		color = get_pixel_color(game, "NO", tex_x, tex_y);
	else if (wall == SOUTH)
		color = get_pixel_color(game, "SO", tex_x, tex_y);
	mlx_put_pixel(game->img, x, y, color);
}

void	columns(t_game *game, double wall_h, double offset_x, int wall)
{
	double	y_start;
	double	y_end;
	double	rays;
	double	y_const;

	rays = 0.0;
	while (rays < game->columns_per_ray)
	{
		y_start = (int)(HEIGHT / 2.0 - wall_h / 2.0);
		y_const = y_start;
		y_end = (int)(HEIGHT / 2.0 + wall_h / 2.0);
		if (y_start < 0)
			y_start = 0;
		if (y_end > HEIGHT)
			y_end = HEIGHT;
		while (y_start < y_end)
			orient_3d(game, round(rays + offset_x), y_start++, wall, wall_h, y_const);
		rays += 1.0;
	}
}

void	render_obstacle_3d(t_game *game, int iter, double dist, int wall)
{
	int		offset_x;
	double	wall_height;

	offset_x = (iter * game->columns_per_ray);
	wall_height = MAX_WALL_HEIGHT / (dist / 2);
	columns(game, wall_height, offset_x, wall);
}

void	one_ray_3d(t_game *game, double x, double y, int iter)
{
	double	dist;
	double	decimal_x;
	double	decimal_y;

	dist = ft_distance(game, x, y);
	decimal_x = x - round(x);
	decimal_y = y - round(y);
	if (abs_min(decimal_x, decimal_y) == fabs(decimal_x)
		&& decimal_x > 0)
		render_obstacle_3d(game, iter, dist, WEST);
	else if (abs_min(decimal_x, decimal_y) == fabs(decimal_x)
		&& decimal_x < 0)
		render_obstacle_3d(game, iter, dist, EAST);
	else if (abs_min(decimal_x, decimal_y) == fabs(decimal_y)
		&& decimal_y > 0)
		render_obstacle_3d(game, iter, dist, NORTH);
	else if (abs_min(decimal_x, decimal_y) == fabs(decimal_y)
		&& decimal_y < 0)
		render_obstacle_3d(game, iter, dist, SOUTH);
}
