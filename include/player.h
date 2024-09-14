/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:31:04 by regea-go          #+#    #+#             */
/*   Updated: 2024/09/13 16:31:04 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H
# include "cub3d.h"

typedef struct s_game		t_game;
typedef struct s_init_data	t_init_data;

typedef struct s_data
{
	double	x_pos;
	double	y_pos;
	double	angle;
	float	speed;

}	t_player;

/* PLAYER INIT */
t_player	*init_player(t_init_data *data);

/* MAIN MOVEMENTS */
void		move_player(mlx_key_data_t keydata, void *param);

void		move_forward(t_game *game);
void		move_backwards(t_game *game);
void		move_left(t_game *game);
void		move_right(t_game *game);
void		rotate_player(t_game *game, double rotation, int op_code);

/* MOVEMENT UTILS */
void		check_position(t_game *game, double delta_x, double delta_y);
int			ft_no_obstacle(t_game *game, double x, double y);
int			ft_inrange(t_game *game, double x, double y);
void		ft_check_initial_position(t_game *game, int x, int y);

#endif 