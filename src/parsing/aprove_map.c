/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aprove_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 23:50:39 by juguerre          #+#    #+#             */
/*   Updated: 2024/09/03 02:53:38 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_pos_ofv(char *line)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	jorgito(&line, &flag);
	if (flag != 1)
		return (0);
	if (!ft_isdigit(line[i]) && !ft_isdigit(line[(ft_strlen(line) - 1)]))
		return (0);
	while (line[i])
	{
		if (line[i] >= 9 && line[i] <= 13)
		{
			i++;
			continue ;
		}
		if ((!ft_isdigit(line[i]) && line[i] != ',') || ((line[i] == ',')
				&& line[i + 1] && line[i + 1] == ','))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	count_vergules(char *rgb)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (rgb[i])
	{
		if (rgb[i++] == ',')
			count++;
	}
	return (count);
}

int	parse_rgb(char **texture)
{
	int		i;
	char	*tmp;

	i = 0;
	while (texture[i])
	{
		tmp = texture[i];
		while (*tmp == ' ' || (*tmp >= 9 && *tmp <= 13))
			tmp++;
		if (tmp[0] == 'F' || tmp[0] == 'C')
		{
			if (count_vergules(tmp) != 2 || !check_pos_ofv(tmp))
			{	
				printf("a\n");
				return (0);
			}	
		}
		i++;
	}
	return (1);
}

int	check_texture_if_valid(char *line)
{
	while (*line == ' ' || (*line >= 9 && *line <= 13))
		line++;
	if ((!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2)
			|| !ft_strncmp(line, "WE", 2) || !ft_strncmp(line, "EA", 2))
		&& (line[2] == 32 || (line[2] >= 9 && line[2] <= 13)))
		return (1);
	else if ((!ft_strncmp(line, "F", 1)
			|| !ft_strncmp(line, "C", 1))
		&& (line[1] == 32 || (line[1] >= 9 && line[1] <= 13)))
		return (1);
	return (0);
}

int	check_texture_space(t_initData *data)
{
	int	i;

	i = -1;
	if (data->counter != 6)
		return (0);
	while (++i < data->counter)
	{
		if (!check_texture_if_valid(data->texture[i]))
			return (0);
	}
	return (1);
}
