/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 00:55:27 by juguerre          #+#    #+#             */
/*   Updated: 2024/09/03 00:55:27 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_rows_cols(t_initData *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map2d[i])
	{
		j = 0;
		while (data->map2d[i][j])
			j++;
		if (j > data->m_cols)
			data->m_cols = j;
		i++;
	}
	data->m_rows = i;
}

int	extension_checker(char *file)
{
	char	*extension;

	extension = ft_strrchr(file, '.');
	if (extension && !ft_strncmp(extension, ".cub", 4))
		return (1);
	return (0);
}

int	parsing(int argc, char **argv, t_initData *data)
{
	if (argc != 2)
	{
		ft_printf("\033[31mError\nWrong number of arguments\n\033[0m\n");
		exit(WRONG_ARG);
	}
	else if (extension_checker(argv[1]) != 1)
	{
		ft_printf("\033[31mError\nWrong file extension\n\033[0m\n");
		exit(WRONG_FILE);
	}
	if (!read_map(argv[1], data))
		return (0);
	printf("holan\n");
	if (!map_validation(data))
		return (0);
	if (!list_texture(data))
		return (free_map(data), free_list(data->t), 0);
	if (!colors_texture(data))
		return (free_map(data), free_list(data->t), 0);
	get_player_position(data);
	get_rows_cols(data);
	return (1);
}
