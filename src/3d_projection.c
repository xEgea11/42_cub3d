/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_projection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 21:49:52 by regea-go          #+#    #+#             */
/*   Updated: 2024/08/31 21:49:58 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void fill_background_3d(t_game *game)
{
    draw_ceiling_3d(game);
    draw_floor_3d(game);
}


static uint32_t get_pixel_color(t_game *game, char *key, uint32_t x, uint32_t y)
{
    t_txtr *tmp;
    uint32_t i;
    mlx_texture_t *texture;

    i = 0;
    tmp = game->data->t;
    while (i < 4)
    {
        if (ft_strncmp(tmp->key, key, 2) == 0)
        {
            texture = tmp->img;
            if (x >= texture->width || y >= texture->height)
                return (0);  // Fuera de los límites

            uint8_t *pixel = &texture->pixels[(y * texture->width + x) * 4];
            uint32_t color = (pixel[0] << 24) | (pixel[1] << 16) | (pixel[2] << 8) | pixel[3];
            return (color);
        }
        tmp = tmp->next;
        i++;
    }
    return (0);
}

static void draw_orientation_3d(t_game *game, int x_comp, double y_comp, int wall, double wall_height)
{
    double tex_x, tex_y;
    int color;
    // Calcula la posición relativa del píxel en el muro
    double relative_y = y_comp / wall_height;

    // Calcula las coordenadas de la textura
    tex_x = (int)(x_comp % TEXTURE_WIDTH);
    tex_y = (int)(relative_y * TEXTURE_HEIGHT) % TEXTURE_HEIGHT;

    // Obtiene el color de la textura
    if (wall == WEST)
        color = get_pixel_color(game, "WE", tex_x, tex_y);
    else if (wall == EAST)
        color = get_pixel_color(game, "EA", tex_x, tex_y);
    else if (wall == NORTH)
        color = get_pixel_color(game, "NO", tex_x, tex_y);
    else if (wall == SOUTH)
        color = get_pixel_color(game, "SO", tex_x, tex_y);

    // Dibuja el pixel
    //printf("x_comp: %d, y_comp: %f, color: %d\n", x_comp, y_comp, color);   
    mlx_put_pixel(game->img, x_comp, y_comp, color);
}

static void draw_columns_per_coordinate_3d(t_game *game, double wall_height, double offset_x, int wall)
{
    double y_start;
    double y_end;
    double rays;

    rays = 0.0;
    while (rays < COLUMNS_PER_RAY)
    {
        y_start = (int)(HEIGHT / 2.0 - wall_height / 2.0);
        y_end = (int)(HEIGHT / 2.0 + wall_height / 2.0);

        if(y_start < 0)                                           
            y_start = 0;
        if(y_end > HEIGHT)
            y_end = HEIGHT;                                                            
        while (y_start < y_end)
            draw_orientation_3d(game, round(rays + offset_x), y_start++, wall, wall_height);
        rays += 1.0;
    }
}

void render_obstacle_3d(t_game *game, int iteration, double distance, int wall)
{
    int offset_x;
    double wall_height;

    offset_x = (iteration * COLUMNS_PER_RAY);
    wall_height = MAX_WALL_HEIGHT / (distance * 2);
    draw_columns_per_coordinate_3d(game, wall_height, offset_x, wall);
}

void single_raycast_to_3d(t_game *game, double x, double y, int iteration)
{
    double distance;
    double decimal_x;
    double decimal_y;

    distance = sqrt(pow(x - game->player->x_pos, 2) + pow(y - game->player->y_pos, 2));
    decimal_x = x - round(x);
    decimal_y = y - round(y);

    if (abs_min(decimal_x, decimal_y) == fabs(decimal_x)                        // Touching X axis and facing West
        && decimal_x > 0)                    
        render_obstacle_3d(game, iteration, distance, WEST);
    else if (abs_min(decimal_x, decimal_y) == fabs(decimal_x)                   // Touching X axis and facing East (negative X)
        && decimal_x < 0)               
        render_obstacle_3d(game, iteration, distance, EAST);        
    else if (abs_min(decimal_x, decimal_y) == fabs(decimal_y)                   // Touching Y axis and facing North
        && decimal_y > 0)                                                       
        render_obstacle_3d(game, iteration, distance, NORTH);
    else if (abs_min(decimal_x, decimal_y) == fabs(decimal_y)                   // Touching Y axis and facing South
        && decimal_y < 0)                                                       
        render_obstacle_3d(game, iteration, distance, SOUTH);
}