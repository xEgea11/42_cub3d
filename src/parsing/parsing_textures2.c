/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:59:40 by juguerre          #+#    #+#             */
/*   Updated: 2024/09/03 00:45:05 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_index(char *line, int i)
{
	while (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13)
		|| line[i] == '.' || line[i] == '/')
		i++;
	return (i);
}

void	ft_process_rgb_color(t_txtr *tmp, t_init_data *data)
{
	if (!ft_strncmp(tmp->key, "F", 2))
	{
		data->floor = ft_split(tmp->value, ',');
		return ;
	}
	else if (!ft_strncmp(tmp->key, "C", 2))
	{
		data->ceiling = ft_split(tmp->value, ',');
		return ;
	}
}

int	check_color_value(char **rgb)
{
	int	i;

	i = 0;
	while (rgb[i])
	{
		if (ft_atoi(rgb[i]) > 255 || ft_atoi(rgb[i]) < 0)
			return (free_array2d(rgb), 0);
		i++;
	}
	return (free_array2d(rgb), 1);
}

int	colors_texture(t_init_data *data)
{
	t_txtr	*tmp;

	data->floor = NULL;
	data->ceiling = NULL;
	tmp = data->t;
	while (tmp)
	{
		if (!ft_strncmp(tmp->key, "F", 1) || !ft_strncmp(tmp->key, "C", 1))
		{
			if (!check_color_value(ft_split(tmp->value, ',')))
				return (0);
			ft_process_rgb_color(tmp, data);
		}
		tmp = tmp->next;
	}
	return (1);
}
