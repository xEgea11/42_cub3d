#include "cub3d.h"

t_player *init_player(t_initData *data)
{
    t_player *player = malloc(sizeof(t_player));
    if (!player) {
        fprintf(stderr, "Player allocation failed\n");          //<---- Change this later
        return (NULL);
    }

    //ft_check_initial_position(game, X_PLAYER, Y_PLAYER);
    player->x_pos = data->player_x;
    player->y_pos = data->player_y;
    player->angle = ((double)random() / RAND_MAX);
    player->speed = SPEED_PLAYER;
    printf(GREEN"Initial player OG: (%f, %f)\n"RESET, player->x_pos, player->y_pos);
    printf("Initial player angle: %f\n", player->angle);

    return (player);
}