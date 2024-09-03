/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 21:51:08 by regea-go          #+#    #+#             */
/*   Updated: 2024/08/31 21:51:08 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv) {
    t_initData *data;
    t_game *game = NULL;

    data = malloc(sizeof(t_initData));
    if(!data)
        return (0);
    game = NULL;
    if(!parsing(argc, argv, data))
        return (0);
	    printf("map2d: %p\n", (void *)data->map2d);
    printf("map2d_square: %p\n", (void *)data->map2d_square);
    printf("m_rows: %d\n", data->m_rows);
    printf("m_cols: %d\n", data->m_cols);
    printf("width: %d\n", data->width);
    printf("height: %d\n", data->height);
    printf("player_x: %d\n", data->player_x);
    printf("player_y: %d\n", data->player_y);
    printf("fd: %d\n", data->fd);
    printf("counter: %d\n", data->counter);
    printf("line: %s\n", data->line);
    printf("map: %s\n", data->map);
    printf("tx2re: %s\n", data->tx2re);
    printf("texture: %p\n", (void *)data->texture);
    printf("floor: %p\n", (void *)data->floor);
    printf("ceiling: %p\n", (void *)data->ceiling);
    printf("rgb: %p\n", (void *)data->rgb);
    // Print the linked list of textures
    t_txtr *current = data->t;
    while (current != NULL) {
        printf("Texture key: %s, value: %s\n", current->key, current->value);
        current = current->next;
    }
    return (init_game(game, data));
}
