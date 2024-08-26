#include "cub3d.h"

// Minimap purposes 
void fill_background(mlx_image_t* img, int height, int width, uint32_t color) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            mlx_put_pixel(img, x, y, color);
        }
    }
}

void draw_player(t_game *game)          //<------ Change this. Either we put it into the minimap or we just dont
{
    mlx_put_pixel(game->img, (int)game->player->x, (int)game->player->y, GOLD);
    mlx_put_pixel(game->img, (int)game->player->x + 1, (int)game->player->y, GOLD);
    mlx_put_pixel(game->img, (int)game->player->x, (int)game->player->y + 1, GOLD);
    mlx_put_pixel(game->img, (int)game->player->x + 1, (int)game->player->y + 1, GOLD);
    mlx_put_pixel(game->img, (int)game->player->x + 1, (int)game->player->y - 1, GOLD);
    mlx_put_pixel(game->img, (int)game->player->x - 1, (int)game->player->y, GOLD);
    mlx_put_pixel(game->img, (int)game->player->x, (int)game->player->y - 1, GOLD);
    mlx_put_pixel(game->img, (int)game->player->x - 1, (int)game->player->y - 1, GOLD);
    mlx_put_pixel(game->img, (int)game->player->x - 1, (int)game->player->y + 1, GOLD);
}

//Minimap purposes, just to draw the pov from the player in a straight line
//It marks the direction the player is looking at based on the angle
void draw_pov(mlx_image_t *img, t_player *player, int length) {
    double x1 = player->x + length * cos(player->angle);
    double y1 = player->y + length * sin(player->angle);

    // Loop through the line length and put each pixel
    for (int i = 0; i <= length; i++) {
        int x = (int)(player->x + i * (x1 - player->x) / length);
        int y = (int)(player->y + i * (y1 - player->y) / length);
        mlx_put_pixel(img, x, y, PLUM);
    }
}

// Angle of view of the player, set at 60 degrees (from -30 to 30 (M_PI/6) in radians) 
void draw_cone(mlx_image_t *img, t_player *player, int length) {
    uint32_t color = DARK_MAGENTA;
    for (double angle1 = player->angle - M_PI / 6; angle1 <= player->angle + M_PI / 6; angle1 += 0.001) {
        double x1 = player->x + length * cos(angle1);
        double y1 = player->y + length * sin(angle1);

        // Loop through the line length and put each pixel
        for (int i = 0; i <= length; i++) {
            int x = (int)(player->x + i * (x1 - player->x) / length);
            int y = (int)(player->y + i * (y1 - player->y) / length);
            mlx_put_pixel(img, x, y, color);
        }
    }
}

void ft_draw(t_game *game, int length)
{
    fill_background(game->img, HEIGHT, WIDTH, DARK_ORANGE);
    draw_player(game);
    draw_cone(game->img, game->player, length);
    draw_pov(game->img, game->player, length);
    mlx_image_to_window(game->mlx, game->img, 0, 0); 
}

