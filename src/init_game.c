#include "cub3d.h"

void create_map(t_game *game)           // For testing purposes, remove later
{
    int i;
    int j;

    i = 0;
    while (i < HEIGHT_MAP)
    {
        j = 0;
        while (j < WIDTH_MAP)
        {
            if (rand() * 100 % 6 == 0 || i == 0 || i == HEIGHT_MAP - 1 || j == 0 || j == WIDTH_MAP - 1)
                game->map[i][j] = 1;
            else
                game->map[i][j] = 0;
            printf("%d  ", game->map[i][j]);
            j++;
        }
        i++;
        printf("\n");
    }
}

int init_game(t_game *game)
{
    game = malloc(sizeof(t_game));
    if (!game) {
        fprintf(stderr, "Memory allocation failed\n");
        return (EXIT_FAILURE);
    }
    create_map(game);
    game->player = init_player();
    if (!game->player) {
        return (EXIT_FAILURE);
    }
    game->y_scale = (double)HEIGHT / HEIGHT_MAP;
    game->x_scale = (double)WIDTH / WIDTH_MAP;
    game->mlx = mlx_init(WIDTH_SCREEN, HEIGHT_SCREEN, "Cub3d", true);
    if (!game->mlx) {
        fprintf(stderr, "MLX42 initialization failed\n");
        return (EXIT_FAILURE);
    }
    // Create an image
    game->img = mlx_new_image(game->mlx, WIDTH_SCREEN, HEIGHT_SCREEN);
    if (!game->img) {
        fprintf(stderr, "Image creation failed\n");
        return (EXIT_FAILURE);
    }
    // Fill the screen with black color
    ft_draw(game);
    
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