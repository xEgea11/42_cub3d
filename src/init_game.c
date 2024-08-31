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

void print_map(t_game *game)           // For testing purposes, remove later
{
    int i;
    int j;

    i = 0;
    while (i < game->data->m_rows)
    {
        j = 0;
        while (j < game->data->m_cols)
        {
            printf("%d  ", game->data->map2d_square[i][j]);
            j++;
        }
        i++;
        printf("\n");
    }
}

int init_game(t_game *game, t_initData *data)
{
    game = malloc(sizeof(t_game));
    if (!game) {
        fprintf(stderr, "Memory allocation failed\n");
        return (EXIT_FAILURE);
    }
    game->data = data;
    print_map(game);
    game->player = init_player(game->data);
    if (!game->player) {
        return (EXIT_FAILURE);
    }
    game->y_scale = (double)HEIGHT / game->data->m_rows;                            //For 3d view
    game->x_scale = (double)WIDTH / game->data->m_cols;
    game->y_scale_minimap = (double)MINIMAP_HEIGHT / game->data->m_rows;            //For minimap
    game->x_scale_minimap = (double)MINIMAP_WIDTH / game->data->m_cols;
    game->mlx = mlx_init(WIDTH, HEIGHT, "Cub3d", true);
    if (!game->mlx) {
        fprintf(stderr, "MLX42 initialization failed\n");
        return (EXIT_FAILURE);
    }
    // Create an image
    game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);              //Change this later
    if (!game->img) {
        fprintf(stderr, "Image creation failed\n");
        return (EXIT_FAILURE);
    }
    
    render_screen(game);
    
    mlx_key_hook(game->mlx, move_player, game);
    // Hook the loop to keep the window open
    mlx_loop(game->mlx);

    return (end_game(game));
}

int end_game(t_game *game)
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