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

int init_texture(t_initData *data)
{
    t_txtr *tmp;

    tmp = data->t;
    while (tmp)
    {
        if (!ft_strncmp(tmp->key, "NO", 2))
        {
            tmp->img = mlx_load_png("textures/NO.png");
            if (!tmp->img)
                return (0);
        }
        else if (!ft_strncmp(tmp->key, "SO", 2))
        {
            tmp->img = mlx_load_png("textures/SO.png");
            if (!tmp->img)
                return (0);
        }
        else if (!ft_strncmp(tmp->key, "WE", 2))
        {
            tmp->img = mlx_load_png("textures/WE.png");
            if (!tmp->img)
                return (0);
        }
        else if (!ft_strncmp(tmp->key, "EA", 2))
        {
            tmp->img = mlx_load_png("textures/EA.png");
            if (!tmp->img)
                return (0);
        }
        tmp = tmp->next;
    }
    return (1);
}
