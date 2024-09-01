/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 21:50:51 by regea-go          #+#    #+#             */
/*   Updated: 2024/08/31 21:50:51 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_player *init_player(t_initData *data)
{
    t_player *player = malloc(sizeof(t_player));
    if (!player) {
        fprintf(stderr, "Player allocation failed\n");          //<---- Change this later
        return (NULL);
    }

    //ft_check_initial_position(game, X_PLAYER, Y_PLAYER);
    player->x_pos = data->player_x;
    player->y_pos = data->player_y;
    player->angle = ((double)random() / RAND_MAX);
    player->speed = SPEED_PLAYER;

    return (player);
}