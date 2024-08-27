#include "cub3d.h"

//void ft_check_initial_position(t_game *game, int x, int y)         //<----Gives segfault, dont use it
//{
//    if (game->map[y][x] == 0)
//    {
//        game->player->x_pos = x;
//        game->player->y_pos = y;
//    }
//    else
//    {
//        printf("Invalid initial position, relocating...\n");        //Look for a good position to spaw
//        game->player->x_pos = 6;
//        game->player->y_pos = 6;
//    }
//}

void rotate_player(t_game *game, double rotation, int op_code)
{
    double new_angle;

    new_angle = 0;
    if (op_code == LEFT)                                //<----- Movements 
        new_angle = game->player->angle - rotation;
    else if(op_code == RIGHT)
        new_angle = game->player->angle + rotation;
    if (new_angle < 0)                                  //<----- Overflow
        game->player->angle += 2 * M_PI;
    else if (new_angle > 2 * M_PI)
        game->player->angle -= 2 * M_PI;
    else
        game->player->angle = new_angle;
}

int ft_inrange(double x, double y)
{
    if (x >= 0 && x < WIDTH_MAP && y >= 0 && y < HEIGHT_MAP)
        return (TRUE);
    return (FALSE);
}

int ft_no_obstacle(t_game *game, double x, double y)
{
    if (game->map[(int)y][(int)x] == 0)
        return (TRUE);
    return (FALSE);
}

void check_position(t_game *game, double delta_x, double delta_y)
{
    double new_x;
    double new_y;

    new_x = delta_x + game->player->x_pos;
    new_y = delta_y + game->player->y_pos;
    if (ft_inrange(new_x, new_y) == TRUE && ft_no_obstacle(game, new_x, new_y) == TRUE)
    {
        game->player->x_pos += delta_x;
        game->player->y_pos += delta_y;
    }
}