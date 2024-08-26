#include "cub3d.h"

// Functions to try and draw the minimap (not working yet)
double scale_minimap_x_axis(double x)                   //<------------- DIS NO GUD
{
    return (x * (MINIMAP_WIDTH / WIDTH));
}

double scale_minimap_y_axis(double y)                   //<------------- DIS NO GUD
{
    return (y * (MINIMAP_HEIGHT / HEIGHT));
}

// Function to move the player forward
void move_forward(t_player *player) {
    double delta_x = cos(player->angle) * 5;
    double delta_y = sin(player->angle) * 5;
    player->x += delta_x;
    player->y += delta_y;
}

// Function to move the player backward
void move_backwards(t_player *player) {
    double delta_x = -cos(player->angle) * 5;
    double delta_y = -sin(player->angle) * 5;
    player->x += delta_x;
    player->y += delta_y;
}

// Function to move the player left
void move_left(t_player *player) {
    double delta_x = sin(player->angle) * 5;
    double delta_y = -cos(player->angle) * 5;
    player->x += delta_x;
    player->y += delta_y;
}

// Function to move the player right
void move_right(t_player *player) {
    double delta_x = -sin(player->angle) * 5;
    double delta_y = cos(player->angle) * 5;
    player->x += delta_x;
    player->y += delta_y;
}

void move_player(mlx_key_data_t keydata, void* param) {
    t_game *game = (t_game *)param;

    if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT) {
        if (keydata.key) {
            if (keydata.key == MLX_KEY_W) // Move North
                move_forward(game->player);
            else if (keydata.key == MLX_KEY_S) // Move South
                move_backwards(game->player);
            else if (keydata.key ==  MLX_KEY_A) // Move West
                move_left(game->player);
            else if (keydata.key == MLX_KEY_D) // Move East
                move_right(game->player);
            else if (keydata.key == MLX_KEY_LEFT) // Rotate Left            //<----Maybe do a wrapper to handle overflow in both of rotationss
                game->player->angle -= 0.1;                                 
            else if (keydata.key == MLX_KEY_RIGHT) // Rotate Right
                game->player->angle += 0.1;
            else
                printf ("Invalid key\n");           //<--- Handle error
        }
        printf("Player position: (%f, %f)\n", game->player->x, game->player->y);    //Testing purposes
        printf("Player angle: %f\n", game->player->angle);
        ft_draw(game, VISION_LENGTH);
    }
}

t_player *init_player()
{
    t_player *player = malloc(sizeof(t_player));
    if (!player) {
        fprintf(stderr, "Player allocation failed\n");          //<---- Change this later
        return NULL;
    }
    player->x = random() % WIDTH;                                   //<---- Change this later, needs to be a param
    player->y = random() % HEIGHT;
    player->angle = ((double)random() / RAND_MAX);
    printf("Initial player position: (%f, %f)\n", player->x, player->y);
    printf("Initial player angle: %f\n", player->angle);

    return (player);
}