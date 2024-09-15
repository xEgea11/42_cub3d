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

static uint32_t	get_pixel_color(t_game *game, char *key, t_ray *ray)
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
			if (ray->tex_x >= texture->width || ray->tex_y >= texture->height)
				return (0);
			pixel = &texture->pixels[(ray->tex_y
					* texture->width + ray->tex_x) * 4];
			color = (pixel[0] << 24) | (pixel[1] << 16)
				| (pixel[2] << 8) | pixel[3];
			return (color);
		}
		tmp = tmp->next;
		i++;
	}
	return (0);
}

void	fill_background_3d(t_game *game)
{
	draw_ceiling_3d(game);
	draw_floor_3d(game);
}

static void	draw_cols_3d(t_game *game, t_ray *ray, double y_iter)
{
	int		color;
	double	texture_pos;

	if (y_iter < 0 || y_iter >= HEIGHT)
		return ;
	ray->relative_y = ((y_iter - ray->col_start)) / ray->wall_height;
	if (ray->orientation == WEST || ray->orientation == EAST)
		texture_pos = ray->texture_pos_y;
	else if (ray->orientation == NORTH || ray->orientation == SOUTH)
		texture_pos = ray->texture_pos_x;
	ray->tex_x = texture_pos * TEXTURE_WIDTH;
	ray->tex_y = (int)(ray->relative_y * TEXTURE_HEIGHT);
	if (ray->orientation == WEST)
		color = get_pixel_color(game, "WE", ray);
	else if (ray->orientation == EAST)
		color = get_pixel_color(game, "EA", ray);
	else if (ray->orientation == NORTH)
		color = get_pixel_color(game, "NO", ray);
	else if (ray->orientation == SOUTH)
		color = get_pixel_color(game, "SO", ray);
	mlx_put_pixel(game->img, ray->total_offset, y_iter, color);
}

void	columns(t_game *game, t_ray *ray)
{
	double	y_iter;

	ray->rays = 0.0;
	ray->col_start = (int)(HEIGHT / 2.0 - ray->wall_height / 2.0);
	ray->col_end = (int)(HEIGHT / 2.0 + ray->wall_height / 2.0);
	y_iter = ray->col_start;
	if (ray->col_end > HEIGHT)
		ray->col_end = HEIGHT;
	while (ray->rays < game->columns_per_ray)
	{
		ray->total_offset = ray->rays + ray->offset;
		y_iter = ray->col_start;
		while (y_iter < ray->col_end)
		{
			draw_cols_3d(game, ray, y_iter);
			y_iter++;
		}
		ray->rays += 1.0;
	}
}

void	ray_3d(t_game *game, t_ray *ray)
{
	ft_set_ray_values(game, ray);
	columns(game, ray);
}
