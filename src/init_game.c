#include "cub3d.h"

int init_game(t_game *game)
{
    game = malloc(sizeof(t_game));
    if (!game) {
        fprintf(stderr, "Memory allocation failed\n");
        return (EXIT_FAILURE);
    }
    game->player = init_player();
    if (!game->player) {
        return (EXIT_FAILURE);
    }
    game->mlx = mlx_init(WIDTH, HEIGHT, "Cub3d", true);
    if (!game->mlx) {
        fprintf(stderr, "MLX42 initialization failed\n");
        return (EXIT_FAILURE);
    }

    // Create an image
    game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
    if (!game->img) {
        fprintf(stderr, "Image creation failed\n");
        return (EXIT_FAILURE);
    }
    // Fill the screen with black color
    ft_draw(game, VISION_LENGTH);
    
    mlx_key_hook(game->mlx, move_player, game);
    // Hook the loop to keep the window open
    mlx_loop(game->mlx);

    return (end_game(game));
}

int end_game(t_game *game)
{
    if (game->img)
        mlx_delete_image(game->mlx, game->img);
    if (game->mlx)
        mlx_terminate(game->mlx);
    if (game->player)
        free(game->player);
    if (game)
        free(game);
    return (EXIT_SUCCESS);
}