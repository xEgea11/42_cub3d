#include "cub3d.h"

double abs_min(double a, double b)
{
    if (fabs(a) < fabs(b))
        return (fabs(a));
    return (fabs(b));
}

void draw_ceiling_3d(t_game *game)
{
    int y;
    int x;

    y = 0;
    x = WIDTH_SCREEN / 2;
    while (y < HEIGHT_SCREEN / 2)
    {
        x = WIDTH_SCREEN / 2;
        while (x < WIDTH_SCREEN)
        {
            mlx_put_pixel(game->img, x, y, MIDNIGHT_BLUE);
            x++;
        }
        y++;
    }
}

void draw_floor_3d(t_game *game)
{
    int y;
    int x;

    y = HEIGHT_SCREEN / 2;
    x = WIDTH_SCREEN / 2;
    while (y < HEIGHT_SCREEN)
    {
        x = WIDTH_SCREEN / 2;
        while (x < WIDTH_SCREEN)
        {
            mlx_put_pixel(game->img, x, y, DARK_GREEN);
            x++;
        }
        y++;
    }
}