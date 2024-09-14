/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 21:50:06 by regea-go          #+#    #+#             */
/*   Updated: 2024/08/31 21:50:07 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	init_mlx(t_game *game)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "Cub3d", true);
	if (!game->mlx)
	{
		fprintf(stderr, "MLX42 initialization failed\n");
		return (EXIT_FAILURE);
	}
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->img)
	{
		fprintf(stderr, "Image creation failed\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static void	init_game_params(t_game *game)
{
	game->y_scale = (double)HEIGHT / game->data->m_rows;
	game->x_scale = (double)WIDTH / game->data->m_cols;
	game->y_scale_minimap = (double)MINIMAP_HEIGHT / game->data->m_rows;
	game->x_scale_minimap = (double)MINIMAP_WIDTH / game->data->m_cols;
	game->fov_angle = VISION_ANGLE * M_PI / 180;
	game->columns_per_ray = (double)WIDTH / NUM_RAYS;
}

int	end_game(t_game *game)
{
	if (game->img)
		mlx_delete_image(game->mlx, game->img);
	if (game->mlx)
		mlx_terminate(game->mlx);
	if (game->player)
		free(game->player);
	if (game)
		free(game);
	return (EXIT_SUCCESS);
}

int	init_game(t_game *game, t_init_data *data)
{
	game = malloc(sizeof(t_game));
	if (!game)
	{
		fprintf(stderr, "Memory allocation failed\n");
		return (EXIT_FAILURE);
	}
	game->data = data;
	game->player = init_player(game->data);
	if (!game->player)
		return (EXIT_FAILURE);
	init_game_params(game);
	if (init_mlx(game) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	render_screen(game);
	mlx_key_hook(game->mlx, move_player, game);
	mlx_loop(game->mlx);
	return (end_game(game));
}
