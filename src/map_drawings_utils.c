#include "cub3d.h"

void put_pixel_minimap(t_game *game, int x, int y)           //<---- It needs to be refactored, i'm still working on it
{
    int i;
    int j;
    int draw_x;
    int draw_y;

    i = 0;
    j = 0;
    while (i < (int)game->y_scale)
    {
        j = 0;
        while (j < (int)game->x_scale)
        {
            draw_x = (int)(x * game->x_scale) + j;
            draw_y = (int)(y * game->y_scale) + i;
            if (draw_x >= 0 && draw_x < WIDTH && draw_y >= 0 && draw_y < HEIGHT) 
            {
                if (game->map[y][x] == 0)
                    mlx_put_pixel(game->img, draw_x, draw_y, DARK_BLUE);
                else if (game->map[y][x] == 1)
                    mlx_put_pixel(game->img, draw_x, draw_y, DARK_GREEN);
            }
            j++;
        }
        i++;
    }
}

// Minimap purposes 
void fill_background_minimap(t_game *game)
{
    int y;
    int x;

    y = 0;
    x = 0;
    while (y < HEIGHT_MAP)
    {
        x = 0;
        while (x < WIDTH_MAP)
            put_pixel_minimap(game, x++, y);
        y++;
    }
}
void draw_square_player(t_game *game, int player_x, int player_y)   //Instead of drawing a point as a player, it draws a square
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
