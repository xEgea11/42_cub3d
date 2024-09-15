/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 21:51:08 by regea-go          #+#    #+#             */
/*   Updated: 2024/08/31 21:51:08 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_init_data	*data;
	t_game		*game;

	game = NULL;
	data = malloc(sizeof(t_init_data));
	if (!data)
		return (0);
	game = NULL;
	if (!parsing(argc, argv, data))
		return (0);
	return (init_game(game, data));
}
