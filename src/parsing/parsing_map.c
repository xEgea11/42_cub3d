/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 00:23:53 by juguerre          #+#    #+#             */
/*   Updated: 2024/09/03 00:23:53 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_map(t_initData *data)
{
	data->map = ft_strdup("");
	while (data->line)
	{
		if (data->line[0] == '\n')
		{
			return (free_data(data->map, data->line, -1), NULL);
		}
		data->map = ft_strjoin(data->map, data->line);
		free(data->line);
		data->line = get_next_line(data->fd);
	}
	return (data->map);
}

int	aprove_map(t_initData *data)
{
	data->map = get_map(data);
	if (!data->map)
		return (0);
	data->map2d = ft_split(data->map, '\n');
	if (!data->map2d)
	{
		free(data->map);
		return (0);
	}
	free(data->map);
		if (!check_texture_space(data)
		|| !parse_rgb(data->texture) || !check_duplicate(data)
		|| !check_first_last_line(data->map2d) || !surrounded_by_one(data->map2d))
	{
		free_array2d(data->map2d);
		printf("jajajaj\n");
		return (0);
	}
	return (1);
}

int	map_validation(t_initData *data)
{
	int	i;
	int	maxlen;

	maxlen = largest_line(data);
	i = 0;
	data->map2d_square = ft_calloc(sizeof(char *), map_size(data->map2d) + 1);
	if (!data->map2d_square)
	{
		return (0);
	}
	while (data->map2d[i])
	{
		if ((int)ft_strlen(data->map2d[i]) == maxlen)
			data->map2d_square[i] = ft_strdup(data->map2d[i]);
		else
			data->map2d_square[i] = fix_line(data->map2d[i], maxlen);
		i++;
	}
	data->map2d_square[i] = NULL;
	data->m_rows = map_size(data->map2d_square);
	data->m_cols = maxlen;
	if (!h_map(data->map2d_square) || !w_map(data->map2d_square))
		return (free_array2d(data->map2d_square),
			free_array2d(data->map2d), free_array2d(data->texture), 0);
	return (1);
}

int	read_map(char *file, t_initData *data)
{
	data->fd = open(file, O_RDONLY);
	read_map_ext(data);
	data->counter = 0;
	while (data->line && data->line[0] != '1' && data->line[0] != ' ')
	{
		if (check_color_texture(data->line))
		{
			data->tx2re = ft_strjoin(data->tx2re, data->line);
			data->counter++;
		}
		free(data->line);
		data->line = get_next_line(data->fd);
	}
	if (!check_texture_mount(data))
		return (free_data(NULL, NULL, data->fd), 0);
	data->texture = ft_split(data->tx2re, '\n');
	if (!data->texture)
		return (free_data(NULL, data->tx2re, data->fd), 0);
	if (!aprove_map(data))
		return (read_map_return_n_free(data));
	return (free_data(data->line, data->tx2re, data->fd), 1);
}
