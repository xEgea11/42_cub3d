/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aprove_map2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 00:14:35 by juguerre          #+#    #+#             */
/*   Updated: 2024/09/03 00:17:17 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_last_line(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (map[i - 1]);
}

int	check_line_of_1(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if ((line[i] >= 9 && line[i] <= 13) || line[i] == ' ')
		{
			i++;
			continue ;
		}
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_first_last_line(char **map)
{
	if (!map[0])
		return (0);
	if (!check_line_of_1(map[0])
		|| !check_line_of_1(get_last_line(map)))
	{
		return (0);
	}
	return (1);
}

int	check_duplicate(t_initData *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->texture[i])
	{
		j = i + 1;
		while (data->texture[j])
		{
			if (!ft_strncmp(data->texture[i], data->texture[j], 2))
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
