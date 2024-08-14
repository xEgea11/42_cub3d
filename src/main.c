#include "cub3d.h"

// Main function to initialize window and display the image
int main(void) {
    //Initialize MLX42
    t_game *game = malloc(sizeof(t_game));
    game->player = init_player();
    if (!game->player) {
        return EXIT_FAILURE;
    
    }
    game->mlx = mlx_init(WIDTH, HEIGHT, "Cub3d", true);
    if (!game->mlx) {
        fprintf(stderr, "MLX42 initialization failed\n");
        return EXIT_FAILURE;
    }

    // Create an image
    game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
    if (!game->img) {
        fprintf(stderr, "Image creation failed\n");
        mlx_terminate(game->mlx);
        return EXIT_FAILURE;
    }

    // Fill the screen with black color
    memset(game->img->pixels, 0xFFFFFFFF, WIDTH * HEIGHT * sizeof(uint32_t));
    draw_square(game);
    mlx_image_to_window(game->mlx, game->img, 0, 0);          //<--- Da shit is not gud
    
    mlx_key_hook(game->mlx, move_player, game);
    
    // Hook the loop to keep the window open
    mlx_loop(game->mlx);

    // Clean up
    mlx_delete_image(game->mlx, game->img);
    mlx_terminate(game->mlx);
    return EXIT_SUCCESS;
}
