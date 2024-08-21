#include "cub3d.h"

//static void ft_check_initial_position(t_game *game, int x, int y)         //<----Gives segfault, dont use it
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

static void rotate_player(t_game *game, double rotation, int op_code)
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

static int ft_inrange(double x, double y)
{
    if (x >= 0 && x < WIDTH_MAP && y >= 0 && y < HEIGHT_MAP)
        return (TRUE);
    return (FALSE);
}

static int ft_no_obstacle(t_game *game, double x, double y)
{
    if (game->map[(int)y][(int)x] == 0)
        return (TRUE);
    return (FALSE);
}

static void check_position(t_game *game, double delta_x, double delta_y)
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

// Function to move the player forward
void move_forward(t_game *game) {
    double delta_x;
    double delta_y;

    delta_x = cos(game->player->angle) * game->player->speed;
    delta_y = sin(game->player->angle) * game->player->speed;
    check_position(game, delta_x, delta_y);
}

// Function to move the player backward
void move_backwards(t_game *game) {
    double delta_x;
    double delta_y;

    delta_x = -cos(game->player->angle) * game->player->speed;
    delta_y = -sin(game->player->angle) * game->player->speed;
    check_position(game, delta_x, delta_y);
}
// Function to move the player left
void move_left(t_game *game) {
    double delta_x;
    double delta_y;

    delta_x = sin(game->player->angle) * game->player->speed;
    delta_y = -cos(game->player->angle) * game->player->speed;
    check_position(game, delta_x, delta_y);
}

// Function to move the player right
void move_right(t_game *game) {
    double delta_x;
    double delta_y;

    delta_x = -sin(game->player->angle) * game->player->speed;
    delta_y = cos(game->player->angle) * game->player->speed;
    check_position(game, delta_x, delta_y);
}

void move_player(mlx_key_data_t keydata, void *param)
{
    t_game *game = (t_game *)param;

    if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT) {
        if (keydata.key) {
            if (keydata.key == MLX_KEY_W) // Move North
                move_forward(game);
            else if (keydata.key == MLX_KEY_S) // Move South
                move_backwards(game);
            else if (keydata.key ==  MLX_KEY_A) // Move West
                move_left(game);
            else if (keydata.key == MLX_KEY_D) // Move East
                move_right(game);
            else if (keydata.key == MLX_KEY_LEFT) // Rotate Left
                rotate_player(game, ANGLE_MODIFIER, LEFT);   //-=                          
            else if (keydata.key == MLX_KEY_RIGHT) // Rotate Right
                rotate_player(game, ANGLE_MODIFIER, RIGHT); //+=
            else
                printf ("Invalid key\n");           //<--- Handle error
        }
        printf("Player OG: (%f, %f)\n", game->player->x_pos, game->player->y_pos);    //Testing purposes
        printf("Player angle: %f\n", game->player->angle);
        ft_draw(game);
    }
}

t_player *init_player()
{
    t_player *player = malloc(sizeof(t_player));
    if (!player) {
        fprintf(stderr, "Player allocation failed\n");          //<---- Change this later
        return (NULL);
    }

    //ft_check_initial_position(game, X_PLAYER, Y_PLAYER);
    player->x_pos = X_PLAYER;
    player->y_pos = Y_PLAYER;
    player->angle = ((double)random() / RAND_MAX);
    player->speed = SPEED_PLAYER;
    printf("Initial player OG: (%f, %f)\n", player->x_pos, player->y_pos);
    printf("Initial player angle: %f\n", player->angle);

    return (player);
}