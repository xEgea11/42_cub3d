#include "cub3d.h"

//int check_position(t_player *player, int delta_x, int delta_y)
//{
//    if (delta_x + player->x >= 0 && delta_x + player->x < WIDTH_MAP && delta_y + player->y >= 0 && delta_y + player->y < HEIGHT_MAP)
//        return (TRUE);
//    else
//        return (FALSE);
//}
// Function to move the player forward
void move_forward(t_game *game) {
    double delta_x = cos(game->player->angle) * game->player->speed;
    double delta_y = sin(game->player->angle) * game->player->speed;
    double new_x = delta_x + game->player->x;
    double new_y = delta_y + game->player->y;
    if (new_x >= 0 && new_x < WIDTH_MAP && new_y >= 0 && new_y < HEIGHT_MAP && game->map[(int)new_y][(int)new_x] == 0)
    {
        game->player->x += delta_x;
        game->player->y += delta_y;
    }
}

// Function to move the player backward
void move_backwards(t_game *game) {
    double delta_x = -cos(game->player->angle) * game->player->speed;
    double delta_y = -sin(game->player->angle) * game->player->speed;
    double new_x = delta_x + game->player->x;
    double new_y = delta_y + game->player->y;
    if (new_x >= 0 && new_x < WIDTH_MAP && new_y >= 0 && new_y < HEIGHT_MAP && game->map[(int)new_y][(int)new_x] == 0)
    {
        game->player->x += delta_x;
        game->player->y += delta_y;
    }
}
// Function to move the player left
void move_left(t_game *game) {
    double delta_x = sin(game->player->angle) * game->player->speed;
    double delta_y = -cos(game->player->angle) * game->player->speed;
    double new_x = delta_x + game->player->x;
    double new_y = delta_y + game->player->y;
    if (new_x >= 0 && new_x < WIDTH_MAP && new_y >= 0 && new_y < HEIGHT_MAP && game->map[(int)new_y][(int)new_x] == 0)
    {
        game->player->x += delta_x;
        game->player->y += delta_y;
    }
}

// Function to move the player right
void move_right(t_game *game) {
    double delta_x = -sin(game->player->angle) * game->player->speed;
    double delta_y = cos(game->player->angle) * game->player->speed;
    double new_x = delta_x + game->player->x;
    double new_y = delta_y + game->player->y;
    if (new_x >= 0 && new_x < WIDTH_MAP && new_y >= 0 && new_y < HEIGHT_MAP && game->map[(int)new_y][(int)new_x] == 0)
    {
        game->player->x += delta_x;
        game->player->y += delta_y;
    }
}

//Following Yolanthe's tutorial, change of position should be done by multiplying for a 2D matrix
//Be careful and watch for the signs of the trigonometric functions
void move_player(mlx_key_data_t keydata, void *param) {
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
            else if (keydata.key == MLX_KEY_LEFT) // Rotate Left            //<----Maybe do a wrapper to handle overflow in both of rotationss
                game->player->angle -= 0.2;                                 
            else if (keydata.key == MLX_KEY_RIGHT) // Rotate Right
                game->player->angle += 0.2;
            else
                printf ("Invalid key\n");           //<--- Handle error
        }
        printf("Player OG: (%f, %f)\n", game->player->x, game->player->y);    //Testing purposes
        printf("Player angle: %f\n", game->player->angle);
        ft_draw(game);
    }
}

t_player *init_player()
{
    t_player *player = malloc(sizeof(t_player));
    if (!player) {
        fprintf(stderr, "Player allocation failed\n");          //<---- Change this later
        return NULL;
    }
    player->x = 6;                                   //<---- Change this later, needs to be a param
    player->y = 6;
    player->angle = ((double)random() / RAND_MAX);
    player->speed = SPEED_PLAYER;
    printf("Initial player OG: (%f, %f)\n", player->x, player->y);
    printf("Initial player angle: %f\n", player->angle);

    return (player);
}