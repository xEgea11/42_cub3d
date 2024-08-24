#include "cub3d.h"

void fill_background_3d(t_game *game)           // <---- Refactor later
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
            mlx_put_pixel(game->img, x, y, LIGHT_BLUE);
            x++;
        }
        y++;
    }

    y = HEIGHT_SCREEN / 2;
    x = WIDTH_SCREEN / 2;
    while (y < HEIGHT_SCREEN)
    {
        x = WIDTH_SCREEN / 2;
        while (x < WIDTH_SCREEN)
        {
            mlx_put_pixel(game->img, x, y, SEA_GREEN);
            x++;
        }
        y++;
    }
}


void draw_obstacle(t_game *game, int iteration, double delta_x, double delta_y, double min_decimal, int wall)             //<----- Declaration of variables meh
{

    double max_wall_height = 500.0;   // Maximum wall height
    double distance = sqrt(delta_x * delta_x + delta_y * delta_y);

    double size = WIDTH_SCREEN / 2.0; // Calculate as double for precision
    double columns_per_ray = (double)(round(size) / NUM_RAYS);
    int x = (int)(round(size) + (iteration * columns_per_ray));
    double rays = 0.0;
    // Scale wall height based on distance, with a minimum threshold to avoid excessively small walls
    double wall_height = max_wall_height / distance;

    // Loop to draw each ray's column
    while (rays < columns_per_ray)
    {
        // Calculate the starting y position for drawing the wall column
        double y_start = (int)(HEIGHT_SCREEN / 2.0 - wall_height / 2.0);
        // Calculate the ending y position
        double y_end = (int)(HEIGHT_SCREEN / 2.0 + wall_height / 2.0);

        if(y_start < 0)
            y_start = 0;
        if(y_end > HEIGHT_SCREEN)
            y_end = HEIGHT_SCREEN;
        // Draw the vertical column for the wall
        while (y_start < y_end)
        {
            if (wall == X_WALL)
            {
                if (min_decimal > 0)          // Facing East
                    mlx_put_pixel(game->img, round(x) + (int)rays, y_start, DARK_RED);
                else                            // Facing West
                    mlx_put_pixel(game->img, round(x) + (int)rays, y_start, DARK_GREEN);
            }
            else if (wall == Y_WALL)
            {
                if (min_decimal > 0)          // Facing South
                    mlx_put_pixel(game->img, round(x) + (int)rays, y_start, DARK_BLUE);
                else                            // Facing North
                    mlx_put_pixel(game->img, round(x) + (int)rays, y_start, DARK_MAGENTA);
            }
            y_start++;
        }
        rays += 1.0;
    }
}
