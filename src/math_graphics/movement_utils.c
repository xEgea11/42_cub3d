/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 21:51:01 by regea-go          #+#    #+#             */
/*   Updated: 2024/08/31 21:51:02 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_player(t_game *game, double rotation, int op_code)
{
	double	new_angle;

	new_angle = 0;
	if (op_code == LEFT)
		new_angle = game->player->angle - rotation;
	else if (op_code == RIGHT)
		new_angle = game->player->angle + rotation;
	if (new_angle < 0)
		game->player->angle = new_angle + (2 * M_PI);
	else if (new_angle > 2 * M_PI)
		game->player->angle = new_angle - (2 * M_PI);
	else
		game->player->angle = new_angle;
}

int	ft_inrange(t_game *game, double x, double y)
{
	if (x >= 0 && x < game->data->m_cols && y >= 0 && y < game->data->m_rows)
		return (TRUE);
	return (FALSE);
}

int	ft_no_obstacle(t_game *game, double x, double y)
{
	if (game->data->map2d_square[(int)y][(int)x] != '1'
		&& game->data->map2d_square[(int)y][(int)x] != ' ')
		return (TRUE);
	return (FALSE);
}

void	check_position(t_game *game, double delta_x, double delta_y)
{
	double	new_x;
	double	new_y;

	new_x = delta_x + game->player->x_pos;
	new_y = delta_y + game->player->y_pos;
	if (ft_inrange(game, new_x, new_y) == TRUE
		&& ft_no_obstacle(game, new_x, new_y) == TRUE)
	{
		game->player->x_pos += delta_x;
		game->player->y_pos += delta_y;
	}
}
