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

static void scale_and_draw_ray(t_game *game, double x, double y)
{
    double x_window;
    double y_window;

    x_window = x * game->x_scale;
    y_window = y * game->y_scale;
    if (x_window < WIDTH && x_window > 0 && y_window < HEIGHT && y_window > 0)
        mlx_put_pixel(game->img, x_window, y_window, PLUM);
}

//Minimap purposes, just to draw the pov from the player in a straight line
//It marks the direction the player is looking at based on the angle
void draw_pov(t_game *game, double angle) 
{
    double i;
    double x1;
    double y1;

    i = 0;
    x1 = game->player->x_pos + VISION_LENGTH * cos(angle); //cos(game->player->angle);
    y1 = game->player->y_pos + VISION_LENGTH * sin(angle);//sin(game->player->angle);

    // Loop through the line length and put each pixel
    while (i < VISION_LENGTH)                           //<----Refactor this one
    {
        double x;
        double y;
        /** CHANGE THIS **/
        /** THIS IS THE ALGORITHM, IT BRUTE FORCES THE CALCULATION OF THE WALL */
        x = (double)(game->player->x_pos + i * (x1 - game->player->x_pos) / VISION_LENGTH);
        y = (double)(game->player->y_pos + i * (y1 - game->player->y_pos) / VISION_LENGTH);
         
        /** PUT THIS ON TO SEE THE MADNESS OF ALL CALCULATIONS */
        //printf(BLUE"RAY OG: x: %f, y: %f\n"RESET, x, y);
        
        if (game->map[(int)y][(int)x] == 1) 
        //** Here we would need to know the distance from the player to the wall **//
        //** And call the function to draw the pillar in function of the distance **/
            break;

        scale_and_draw_ray(game, x, y);     //<-- This is still for the map

        /** RATE AT WHICH WE CHANGE THE CALCULATIONS **/
        i += 0.01;
    }
}

//Draw cone function with draw_pov but in a cone of 60 
void draw_cone(t_game *game) {
    
    double angle_step;
    double start_angle;
    double current_angle;
    int i;
    // Calculate the step angle between each ray
    angle_step = FOV_ANGLE / NUM_RAYS;
    // Start angle (player's angle minus half the FOV)
    start_angle = game->player->angle - FOV_ANGLE / 2.0;
    i = 0;
    while (i < NUM_RAYS)
    {
        current_angle = start_angle + i * angle_step;
        draw_pov(game, current_angle);
        i++;
    }

}

void ft_draw(t_game *game)
{
    fill_background(game);
    draw_player(game);
    draw_cone(game);
    //draw_pov(game, game->player->angle);                   //<------ For testing purposes, it tests a straight line
    mlx_image_to_window(game->mlx, game->img, 0, 0); 
}

