/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:15:34 by juguerre          #+#    #+#             */
/*   Updated: 2024/09/08 18:15:34 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	mlx_load(t_txtr *tmp, char *path)
{
	tmp->img = mlx_load_png(path);
	if (!tmp->img)
		return (0);
	return (1);
}

int	init_texture(t_init_data *data)
{
	t_txtr	*tmp;

	tmp = data->t;
	while (tmp)
	{
		if (!ft_strncmp(tmp->key, "NO", 2))
			mlx_load(tmp, "textures/NO.png");
		else if (!ft_strncmp(tmp->key, "SO", 2))
			mlx_load(tmp, "textures/SO.png");
		else if (!ft_strncmp(tmp->key, "WE", 2))
			mlx_load(tmp, "textures/WE.png");
		else if (!ft_strncmp(tmp->key, "EA", 2))
			mlx_load(tmp, "textures/EA.png");
		tmp = tmp->next;
	}
	return (1);
}
