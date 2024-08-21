#include "cub3d.h"

// Minimap purposes 
void fill_background(t_game *game)
{
    int y;
    int x;
    int i;
    int j;

    y = 0;
    x = 0;
    i = 0;
    j = 0;
   // Iterate over the map
   while (y < HEIGHT_MAP)
   {
        x = 0;
        while (x < WIDTH_MAP)
        {
            i = 0;
            // Check if the map cell is 1
            uint32_t color = (game->map[y][x] == 1) ? DARK_GREEN : DARK_ORANGE;
            // Draw a filled rectangle for this cell
            while (i < (int)game->y_scale)
            {
                j = 0;
                while (j < (int)game->x_scale)
                {
                    int draw_x = (int)(x * game->x_scale) + j;
                    int draw_y = (int)(y * game->y_scale) + i;
                    if (draw_x >= 0 && draw_x < WIDTH && draw_y >= 0 && draw_y < HEIGHT) {
                        mlx_put_pixel(game->img, draw_x, draw_y, color);
                    }
                    j++;
                }
                i++;
            }
            x++;
        }
    y++;
    }
}

void draw_player(t_game *game) 
{
    int player_x;
    int player_y;
    // Scaling factors to fit the player within the minimap based on the window size
    player_x = (int)(game->player->x_pos * game->x_scale);
    player_y = (int)(game->player->y_pos * game->y_scale);
    printf("MAP_SCALE: Player x: %d, Player y: %d\n", player_x, player_y);
    //Draw point
    if (player_x >= 0 && player_x < WIDTH && player_y >= 0 && player_y < HEIGHT)
    {
        int i = -1;
        int j = -1;
        while (i < 2)
        {
            j = -1;
            while (j < 2)
            {
                mlx_put_pixel(game->img, player_x + i, player_y + j, DARK_RED);
                j++;
            }
            i++;
        }
    }
}


//Minimap purposes, just to draw the pov from the player in a straight line
//It marks the direction the player is looking at based on the angle
void draw_pov(t_game *game) 
{
    double i;

    i = 0;
    //int x_scaled = game->player->x * game->x_scale;
    //int y_scaled = game->player->y * game->y_scale;
    double x1 = game->player->x_pos + VISION_LENGTH * cos(game->player->angle);
    double y1 = game->player->y_pos + VISION_LENGTH * sin(game->player->angle);

    // Loop through the line length and put each pixel
    while (i < VISION_LENGTH)
    {
        // Calculate the current x and y positions along the line
        double x = (double)(game->player->x_pos + i * (x1 - game->player->x_pos) / VISION_LENGTH);
        double y = (double)(game->player->y_pos + i * (y1 - game->player->y_pos) / VISION_LENGTH);
        
        // Scale the coordinates to the window's pixel size
        double x_window = x * game->x_scale;
        double y_window = y * game->y_scale;
        
        //printf("RAY OG: x: %f, y: %f\n", x, y);
        
        if (game->map[(int)y][(int)x] == 1)
            break;

        if (x_window < WIDTH && x_window > 0 && y_window < HEIGHT && y_window > 0)
            mlx_put_pixel(game->img, x_window, y_window, PLUM);
        //printf("RAY SCALED: x_window: %f, y_window: %f\n", x_window, y_window);

        i += 0.01;
    }
}


//Draw cone function with draw_pov but in a cone of 60 
void draw_cone(t_game *game) {
    // Calculate the step angle between each ray
    double angle_step = FOV_ANGLE / NUM_RAYS;

    // Start angle (player's angle minus half the FOV)
    double start_angle = game->player->angle - FOV_ANGLE / 2.0;

    // Loop through each ray within the 60º field of view
    for (int i = 0; i < NUM_RAYS; i++) {
        // Calculate the angle for this specific ray
        double current_angle = start_angle + i * angle_step;

        // Update player's temporary angle
        double saved_angle = game->player->angle;
        game->player->angle = current_angle;

        // Cast the ray at this angle
        draw_pov(game);

        // Restore the player's original angle
        game->player->angle = saved_angle;
    }
}

void ft_draw(t_game *game)
{
    fill_background(game);
    draw_player(game);
    draw_cone(game);
    //draw_pov(game);
    mlx_image_to_window(game->mlx, game->img, 0, 0); 
}

