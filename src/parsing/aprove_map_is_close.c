/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aprove_map_is_close.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 23:50:27 by juguerre          #+#    #+#             */
/*   Updated: 2024/09/02 23:50:33 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	if_valid_map(char *line, int *flag)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if ((line[i] != '1' && line[i] != '0'
				&& !(line[i] == 32 || (line[i] >= 9 && line[i] <= 13)))
			&& !(line[i] == 'W' || line[i] == 'E'
				|| line[i] == 'N' || line[i] == 'S'))
		{
			return (0);
		}
		else if (line[i] == 'W' || line[i] == 'E'
			|| line[i] == 'N' || line[i] == 'S')
			(*flag)++;
		i++;
	}
	return (1);
}

int	if_surrounded(char *line)
{
	int	i;

	i = 0;
	while (line[i]== 32 || (line[i]>= 9 && line[i]<= 13))
		i++;
	if (line[i] != '1' && (line[ft_strlen(line) - 1] != '1'
			&& line[ft_strlen(line) - 1] != '\n'))
	{
		return (0);
	}
	return (1);
}

int	surrounded_by_one(char **map)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (map[i])
	{
		if (!if_surrounded(map[i])
			|| !if_valid_map(map[i], &flag) || flag > 1)
		{
			printf("Error\n");
			return (0);
		}
		i++;
	}
	if (flag == 0)
	{
		return (0);
	}
	return (1);
}
