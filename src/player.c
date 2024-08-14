#include "cub3d.h"

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


void move_player(mlx_key_data_t keydata, void* param) {
    t_game *game = (t_game *)param;

    if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT) {
        if (keydata.key) {
            if (keydata.key == MLX_KEY_W) // Move North
                game->player->y -= 5;
            else if (keydata.key == MLX_KEY_S) // Move South
                game->player->y += 5;
            else if (keydata.key ==  MLX_KEY_A) // Move West
                game->player->x -= 5;
            else if (keydata.key == MLX_KEY_D) // Move East
                game->player->x += 5;
            else
                printf ("Invalid key\n");           //<--- Handle error
        }
        printf("Player position: (%f, %f)\n", game->player->x, game->player->y);
        memset(game->img->pixels, 0xFFFFFFFF, WIDTH * HEIGHT * sizeof(uint32_t));
        draw_square(game);

        mlx_image_to_window(game->mlx, game->img, 0, 0); 
    }
}


t_player *init_player()
{
    t_player *player = malloc(sizeof(t_player));
    if (!player) {
        fprintf(stderr, "Player allocation failed\n");
        return NULL;
    }
    player->x = random() % WIDTH;
    player->y = random() % HEIGHT;
    printf("Initial player position: (%f, %f)\n", player->x, player->y);
    return player;
}