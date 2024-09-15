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

static int	ft_in_range(t_game *game, int x, int y)
{
	if ((x < game->data->m_cols && y < game->data->m_rows)
		&& (x >= 0 && x < MINIMAP_WIDTH && y >= 0 && y < MINIMAP_HEIGHT))
		return (TRUE);
	return (FALSE);
}

void	draw_minimap(t_game *game)
{
	int	draw_x;
	int	draw_y;
	int	map_x;
	int	map_y;

	draw_y = 0;
	while (draw_y < MINIMAP_HEIGHT)
	{
		draw_x = 0;
		while (draw_x < MINIMAP_WIDTH)
		{
			map_x = draw_x / game->x_scale_minimap;
			map_y = draw_y / game->y_scale_minimap;
			if (ft_in_range(game, map_x, map_y) == TRUE)
			{
				if (ft_is_empty(game, map_x, map_y))
					mlx_put_pixel(game->img, draw_x, draw_y, FLOOR_MINIMAP);
				else
					mlx_put_pixel(game->img, draw_x, draw_y, WALL_MINIMAP);
			}
			draw_x++;
		}
		draw_y++;
	}
}

void	draw_player_minimap(t_game *game)
{
	int	player_x;
	int	player_y;

	player_x = (int)(game->player->x_pos * game->x_scale_minimap);
	player_y = (int)(game->player->y_pos * game->y_scale_minimap);
	if (player_x >= 0 && player_x < MINIMAP_WIDTH
		&& player_y >= 0 && player_y < MINIMAP_HEIGHT)
		draw_square_minimap(game, player_x, player_y);
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
