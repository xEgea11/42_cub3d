#include "cub3d.h"

double scale_minimap_x_axis(double x)                   //<------------- DIS NO GUD
{
    return (x * (MINIMAP_WIDTH / WIDTH));
}

double scale_minimap_y_axis(double y)                   //<------------- DIS NO GUD
{
    return (y * (MINIMAP_HEIGHT / HEIGHT));
}

void draw_square(t_game *game)
{
    mlx_put_pixel(game->img, (int)game->player->x, (int)game->player->y, 0xFF0000FF);
    mlx_put_pixel(game->img, (int)game->player->x + 1, (int)game->player->y, 0xFF0000FF);
    mlx_put_pixel(game->img, (int)game->player->x, (int)game->player->y + 1, 0xFF0000FF);
    mlx_put_pixel(game->img, (int)game->player->x + 1, (int)game->player->y + 1, 0xFF0000FF);
    mlx_put_pixel(game->img, (int)game->player->x + 1, (int)game->player->y - 1, 0xFF0000FF);
    mlx_put_pixel(game->img, (int)game->player->x - 1, (int)game->player->y, 0xFF0000FF);
    mlx_put_pixel(game->img, (int)game->player->x, (int)game->player->y - 1, 0xFF0000FF);
    mlx_put_pixel(game->img, (int)game->player->x - 1, (int)game->player->y - 1, 0xFF0000FF);
    mlx_put_pixel(game->img, (int)game->player->x - 1, (int)game->player->y + 1, 0xFF0000FF);
}

void draw_pov(mlx_image_t *img, t_player *player, int length) {
    double x1 = player->x + length * cos(player->angle);
    double y1 = player->y + length * sin(player->angle);

    // Loop through the line length and put each pixel
    for (int i = 0; i <= length; i++) {
        int x = (int)(player->x + i * (x1 - player->x) / length);
        int y = (int)(player->y + i * (y1 - player->y) / length);
        mlx_put_pixel(img, x, y, DARK_MAGENTA);
    }
}

void draw_cone(mlx_image_t *img, t_player *player, int length) {
    for (double angle1 = player->angle - M_PI / 6; angle1 <= player->angle + M_PI / 6; angle1 += 0.01) {
        double x1 = player->x + length * cos(angle1); // + M_PI / 6
        double y1 = player->y + length * sin(angle1); // + M_PI / 6

        // Loop through the line length and put each pixel
        for (int i = 0; i <= length; i++) {
            int x = (int)(player->x + i * (x1 - player->x) / length);
            int y = (int)(player->y + i * (y1 - player->y) / length);
            mlx_put_pixel(img, x, y, SKY_BLUE);
        }
    }
}

void ft_draw(t_game *game, int length)
{
    memset(game->img->pixels, 0xFFFFFFFF, WIDTH * HEIGHT * sizeof(uint32_t));
    draw_square(game);
    draw_cone(game->img, game->player, length);
    draw_pov(game->img, game->player, length);
    mlx_image_to_window(game->mlx, game->img, 0, 0); 
}




// Function to move the player forward
void move_forward(t_player *player) {
    double delta_x = cos(player->angle) * 5;
    double delta_y = sin(player->angle) * 5;
    player->x += delta_x;
    player->y += delta_y;
}

// Function to move the player backward
void move_backward(t_player *player) {
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
                move_backward(game->player);
            else if (keydata.key ==  MLX_KEY_A) // Move West
                move_left(game->player);
            else if (keydata.key == MLX_KEY_D) // Move East
                move_right(game->player);
            else if (keydata.key == MLX_KEY_LEFT) // Rotate Left
                game->player->angle -= 0.1;
            else if (keydata.key == MLX_KEY_RIGHT) // Rotate Right
                game->player->angle += 0.1;
            else
                printf ("Invalid key\n");           //<--- Handle error
        }
        printf("Player position: (%f, %f)\n", game->player->x, game->player->y);
        printf("Player angle: %f\n", game->player->angle);
        ft_draw(game, 100);
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
    player->angle = ((double)random() / RAND_MAX) * (2 * M_PI);
    printf("Initial player position: (%f, %f)\n", player->x, player->y);
    printf("Initial player angle: %f\n", player->angle);

    return (player);
}