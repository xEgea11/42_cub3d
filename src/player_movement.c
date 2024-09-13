/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 21:50:57 by regea-go          #+#    #+#             */
/*   Updated: 2024/08/31 21:50:57 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_game *game)
{
	double	delta_x;
	double	delta_y;

	delta_x = cos(game->player->angle) * game->player->speed;
	delta_y = sin(game->player->angle) * game->player->speed;
	check_position(game, delta_x, delta_y);
}

void	move_backwards(t_game *game)
{
	double	delta_x;
	double	delta_y;

	delta_x = -cos(game->player->angle) * game->player->speed;
	delta_y = -sin(game->player->angle) * game->player->speed;
	check_position(game, delta_x, delta_y);
}

void	move_left(t_game *game)
{
	double	delta_x;
	double	delta_y;

	delta_x = sin(game->player->angle) * game->player->speed;
	delta_y = -cos(game->player->angle) * game->player->speed;
	check_position(game, delta_x, delta_y);
}

void	move_right(t_game *game)
{
	double	delta_x;
	double	delta_y;

	delta_x = -sin(game->player->angle) * game->player->speed;
	delta_y = cos(game->player->angle) * game->player->speed;
	check_position(game, delta_x, delta_y);
}

void	move_player(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.action == MLX_PRESS
		|| keydata.action == MLX_REPEAT)
	{
		if (keydata.key)
		{
			if (mlx_is_key_down(game->mlx, MLX_KEY_W))
				move_forward(game);
			else if (mlx_is_key_down(game->mlx, MLX_KEY_S))
				move_backwards(game);
			else if (mlx_is_key_down(game->mlx, MLX_KEY_A))
				move_left(game);
			else if (mlx_is_key_down(game->mlx, MLX_KEY_D))
				move_right(game);
			else if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
				rotate_player(game, ANGLE_MODIFIER, LEFT);
			else if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
				rotate_player(game, ANGLE_MODIFIER, RIGHT);
			else if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
				mlx_close_window(game->mlx);
		}
		render_screen(game);
	}
}
