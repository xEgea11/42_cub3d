/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 21:50:35 by regea-go          #+#    #+#             */
/*   Updated: 2024/08/31 21:50:36 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "MLX42.h"
# include "defines.h"
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "player.h"
# include "drawings.h"
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <time.h>  //Just for random start generation
# include <parsing.h>

typedef struct s_data	t_player;

typedef struct s_game
{
	t_init_data	*data;
	mlx_image_t	*img;
	mlx_t		*mlx;
	t_player	*player;
	double		y_scale;
	double		x_scale;
	double		y_scale_minimap;
	double		x_scale_minimap;
	double		fov_angle;
	double		columns_per_ray;

}	t_game;

int		init_game(t_game *game, t_init_data *data);
int		end_game(t_game *game);
void	print_map(t_game *game);

#endif  