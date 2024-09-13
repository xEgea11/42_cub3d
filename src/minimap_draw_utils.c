/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_draw_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 21:50:24 by regea-go          #+#    #+#             */
/*   Updated: 2024/08/31 21:50:26 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_is_empty(t_game *game, int x, int y)
{
	if (game->data->map2d_square[y][x] == EMPTY
		|| game->data->map2d_square[y][x] == 'N'
		|| game->data->map2d_square[y][x] == 'S'
		|| game->data->map2d_square[y][x] == 'W'
		|| game->data->map2d_square[y][x] == 'E')
		return (TRUE);
	return (FALSE);
}

void	put_pixel_minimap(t_game *game, int x, int y)
{
	int	i;
	int	j;
	int	draw_x;
	int	draw_y;

	i = 0;
	j = 0;
	while (i < (int)game->y_scale_minimap)
	{
		j = 0;
		while (j < (int)game->x_scale_minimap)
		{
			draw_x = (int)(x * game->x_scale_minimap) + j;
			draw_y = (int)(y * game->y_scale_minimap) + i;
			if (draw_x >= 0 && draw_x < MINIMAP_WIDTH
				&& draw_y >= 0 && draw_y < MINIMAP_HEIGHT)
			{
				if (ft_is_empty(game, x, y))
					mlx_put_pixel(game->img, draw_x, draw_y, FLOOR_COLOR);
				else if (game->data->map2d_square[y][x] == WALL
					|| game->data->map2d_square[y][x] == OUT_OF_BOUNDS)
					mlx_put_pixel(game->img, draw_x, draw_y, WALL_COLOR);
			}
			j++;
		}
		i++;
	}
}

void	fill_background_minimap(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < game->data->m_rows)
	{
		x = 0;
		while (x < game->data->m_cols)
			put_pixel_minimap(game, x++, y);
		y++;
	}
}

void	draw_square_minimap(t_game *game, int player_x, int player_y)
{
	int	i;
	int	j;

	i = -2;
	j = -2;
	while (i <= 2)
	{
		j = -2;
		while (j <= 2)
		{
			if (player_x + i >= 0 && player_x + i < MINIMAP_WIDTH
				&& player_y + j >= 0 && player_y + j < MINIMAP_HEIGHT)
				mlx_put_pixel(game->img, player_x + i, player_y + j, DARK_RED);
			j++;
		}
		i++;
	}
}
