#include "cub3d.h"


void draw_player(t_game *game) 
{
    int player_x;
    int player_y;
    
    player_x = (int)(game->player->x_pos * game->x_scale);      // Scaling factors to fit the player within the minimap based on the window size
    player_y = (int)(game->player->y_pos * game->y_scale);
    printf(YELLOW"SCALED position: Player x: %d, Player y: %d\n"RESET, player_x, player_y);
    //Draw 3x3 square player
    if (player_x >= 0 && player_x < WIDTH && player_y >= 0 && player_y < HEIGHT)
        draw_square(game, player_x, player_y);
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
    //draw_pov(game);                   //<------ For testing purposes, it tests a straight line
    mlx_image_to_window(game->mlx, game->img, 0, 0); 
}

