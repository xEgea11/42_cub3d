#include "cub3d.h"

void put_color(t_game *game, int x, int y)           //<---- It needs to be refactored, i'm still working on it
{
    int i;
    int j;
    uint32_t color;

    i = 0;
    j = 0;

    if (game->map[y][x] == 0)
        color = DARK_BLUE;
    else if (game->map[y][x] == 1)
        color = DARK_GREEN;
    while (i < (int)game->y_scale)
    {
        j = 0;
        while (j < (int)game->x_scale)
        {
            int draw_x = (int)(x * game->x_scale) + j;              //<----- We need to change that
            int draw_y = (int)(y * game->y_scale) + i;
            if (draw_x >= 0 && draw_x < WIDTH && draw_y >= 0 && draw_y < HEIGHT) {
                mlx_put_pixel(game->img, draw_x, draw_y, color);
            }
            j++;
        }
        i++;
    }
}

// Minimap purposes 
void fill_background(t_game *game)
{
    int y;
    int x;

    y = 0;
    x = 0;
    while (y < HEIGHT_MAP)
    {
        x = 0;
        while (x < WIDTH_MAP)
            put_color(game, x++, y);
        y++;
    }
}
void draw_square(t_game *game, int player_x, int player_y)   //Instead of drawing a point as a player, it draws a square
{
        int i;
        int j;

        i = -2;
        j = -2;
        while (i <= 2)
        {
            j = -2;
            while (j <= 2)
            {
                mlx_put_pixel(game->img, player_x + i, player_y + j, DARK_RED);
                j++;
            }
            i++;
        }
}
