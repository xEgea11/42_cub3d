/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_ext.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 00:27:13 by juguerre          #+#    #+#             */
/*   Updated: 2024/09/03 00:38:08 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	read_map_ext(t_init_data *data)
{
	if (data->fd == -1)
	{
		ft_printf("\033[31mError\nWrong file name\n\033[0m\n");
		exit(WRONG_FILE);
	}
	data->line = get_next_line(data->fd);
	if (data->line == NULL)
	{
		ft_printf("\033[31mError\nEmpty file\n\033[0m\n");
		exit(EMPTY_FILE);
	}
	data->tx2re = strdup("");
}

int	read_map_return_n_free(t_init_data *data)
{
	free_data(NULL, data->tx2re, data->fd);
	free_array2d(data->texture);
	return (0);
}
