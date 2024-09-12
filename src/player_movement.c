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

// Function to move the player forward
void move_forward(t_game *game) {
    double delta_x;
    double delta_y;

    delta_x = cos(game->player->angle) * game->player->speed;
    delta_y = sin(game->player->angle) * game->player->speed;
    check_position(game, delta_x, delta_y);
}

// Function to move the player backward
void move_backwards(t_game *game) {
    double delta_x;
    double delta_y;

    delta_x = -cos(game->player->angle) * game->player->speed;
    delta_y = -sin(game->player->angle) * game->player->speed;
    check_position(game, delta_x, delta_y);
}
// Function to move the player left
void move_left(t_game *game) {
    double delta_x;
    double delta_y;

    delta_x = sin(game->player->angle) * game->player->speed;
    delta_y = -cos(game->player->angle) * game->player->speed;
    check_position(game, delta_x, delta_y);
}

// Function to move the player right
void move_right(t_game *game) {
    double delta_x;
    double delta_y;

    delta_x = -sin(game->player->angle) * game->player->speed;
    delta_y = cos(game->player->angle) * game->player->speed;
    check_position(game, delta_x, delta_y);
}

void move_player(mlx_key_data_t keydata, void *param)
{
    t_game *game = (t_game *)param;

    if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT) {
        if (keydata.key) {
            if (mlx_is_key_down(game->mlx, MLX_KEY_W))
            //if (keydata.key == MLX_KEY_W) // Move North
                move_forward(game);
            else if (mlx_is_key_down(game->mlx, MLX_KEY_S))
            //else if (keydata.key == MLX_KEY_S) // Move South
                move_backwards(game);
            else if (mlx_is_key_down(game->mlx, MLX_KEY_A))
            //else if (keydata.key ==  MLX_KEY_A) // Move West
                move_left(game);
            else if (mlx_is_key_down(game->mlx, MLX_KEY_D))
            //else if (keydata.key == MLX_KEY_D) // Move East
                move_right(game);
            else if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
            //else if (keydata.key == MLX_KEY_LEFT) // Rotate Left
                rotate_player(game, ANGLE_MODIFIER, LEFT);   //-=
            else if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))                          
            //else if (keydata.key == MLX_KEY_RIGHT) // Rotate Right
                rotate_player(game, ANGLE_MODIFIER, RIGHT); //+=
            else if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
                mlx_close_window(game->mlx);                        //Mbe return without rendering screen
        }
        render_screen(game);
    }
}