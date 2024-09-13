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

static double	ft_set_angle(char c)
{
	if (c == 'S')
		return (M_PI_2);
	else if (c == 'N')
		return (3 * M_PI_2);
	else if (c == 'W')
		return (M_PI);
	else if (c == 'E')
		return (0);
	return (0);
}

t_player	*init_player(t_initData *data)
{
	t_player	*player;
	int			x;
	int			y;

	player = malloc(sizeof(t_player));
	if (!player)
	{
		printf("Player allocation failed\n");
		return (NULL);
	}
	x = data->player_x;
	y = data->player_y;
	player->x_pos = x;
	player->y_pos = y;
	player->angle = ft_set_angle(data->map2d_square[y][x]);
	player->speed = SPEED_PLAYER;
	return (player);
}
