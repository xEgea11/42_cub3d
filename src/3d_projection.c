#include "cub3d.h"


static void draw_orientation_3d(t_game *game, double rays, double x_offset, double y_start, int wall)
{
    int x_offset_int;

    x_offset_int = round(x_offset);
    if (wall == WEST)
        mlx_put_pixel(game->img, x_offset_int + (int)rays, y_start, PERU);
    else if (wall == EAST)
        mlx_put_pixel(game->img, x_offset_int + (int)rays, y_start, SADDLE_BROWN);
    else if (wall == NORTH)
        mlx_put_pixel(game->img, x_offset_int + (int)rays, y_start, SIENNA);
    else if (wall == SOUTH)         
        mlx_put_pixel(game->img, x_offset_int + (int)rays, y_start, CHOCOLATE);
}

// <---- This needs to be refactored
static void draw_columns_per_coordinate_3d(t_game *game, double wall_height, double columns_per_ray, double offset_x, int wall)
{
    double y_start;
    double y_end;
    double rays;

    rays = 0.0;
    while (rays < columns_per_ray)
    {
        y_start = (int)(HEIGHT_SCREEN / 2.0 - wall_height / 2.0);   //Min and max size of the column
        y_end = (int)(HEIGHT_SCREEN / 2.0 + wall_height / 2.0);

        if(y_start < 0)                                             //Respect boundaries
            y_start = 0;
        if(y_end > HEIGHT_SCREEN)
            y_end = HEIGHT_SCREEN;
                                                                    // Draw the vertical column for the wall
        while (y_start < y_end)
        {
            draw_orientation_3d(game, rays, offset_x, y_start, wall);
            y_start++;
        }
        rays += 1.0;
    }
}

void fill_background_3d(t_game *game)
{
    draw_ceiling_3d(game);
    draw_stars_3d(game);
    draw_floor_3d(game);
}

//Refactor still needed 
void render_obstacle_3d(t_game *game, int iteration, double delta_x, double delta_y, int wall)
{
    double distance;  //Distance from the player to the wall
    double columns_per_ray; // How many columns correspond to each ray, depending on the screen size
    int offset_x;
    double wall_height;     // rendered wall height based on distance

    distance = sqrt(delta_x * delta_x + delta_y * delta_y);
    columns_per_ray = (double)WIDTH / NUM_RAYS;
    offset_x = WIDTH + (iteration * columns_per_ray);
    wall_height = MAX_WALL_HEIGHT / distance;
    // Starting at an offset x, it draws the necessary columns per x
    draw_columns_per_coordinate_3d(game, wall_height, columns_per_ray, offset_x, wall);
}
