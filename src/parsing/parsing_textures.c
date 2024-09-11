/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 00:47:06 by juguerre          #+#    #+#             */
/*   Updated: 2024/09/03 00:54:49 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_txtr	*new_texture(char *line)
{
	t_txtr	*list;

	list = (t_txtr *)ft_calloc(sizeof(t_txtr), 1);
	if (!list)
		return (NULL);
	while (*line == ' ' || (*line >= 9 && *line <= 13))
		line++;
	if ((!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2)
			||!ft_strncmp(line, "WE", 2) || !ft_strncmp(line, "EA", 2)))
	{
		list->key = ft_substr(line, 0, 2);
		list->value = ft_substr(line, get_index(line, 2), ft_strlen(line));
	}
	else if ((!ft_strncmp(line, "F", 1) || !ft_strncmp(line, "C", 1)))
	{
		list->key = ft_substr(line, 0, 1);
		list->value = ft_substr(line, get_index(line, 1), ft_strlen(line));
	}
	list->next = NULL;
	return (list);
}

void	list_back_texture(t_txtr **texture, t_txtr *new)
{
    t_txtr	*tmp;

    if (!*texture)
    {
        *texture = new;
        return ;
    }
    tmp = *texture;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
}


int	list_texture(t_initData *data)
{
	int		i;
	t_txtr	*tmp;

	i = 0;
	while (data->texture[i])
	{
		tmp = new_texture(data->texture[i]);
		if (!tmp)
			return (0);
		list_back_texture(&data->t, tmp);
		i++;
	}
	return (1);
}

int	check_texture_mount(t_initData *data)
{
	if (data->counter != 6)
	{
		ft_printf("\033[31mError\nWrong number of textures\n\033[0m\n");
		free(data->line);
		free(data->tx2re);
		return (0);
	}
	return (1);
}

int	check_color_texture(char *line)
{
	while (*line == ' ' || (*line >= 9 && *line <= 13))
		line++;
	if (!ft_strncmp(line, "NO", 2)
		|| !ft_strncmp(line, "SO", 2)
		|| !ft_strncmp(line, "WE", 2) 
		|| !ft_strncmp(line, "EA", 2)
		|| !ft_strncmp(line, "F", 1)
		|| !ft_strncmp(line, "C", 1))
		return (1);
	return (0);
}
