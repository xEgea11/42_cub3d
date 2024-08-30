#include "cub3d.h"

uint32_t rgb_to_hex(char *str)              //<----- We need to better implement this
{
    int rgb[3];
    int i;
    int j;

    i = 0;
    j = 0;
    while (!ft_isdigit(str[i]))
        i++;
    while (str[i] != '\0') 
    {
        if (ft_isdigit(str[i]))
        {
            rgb[j] = ft_atoi(&str[i]);  // Convert the number and store it in the array
            j++;
            while (ft_isdigit(str[i])) 
                i++;  // Skip the digits to the next character
        } 
        else 
            i++;
    }
    return (rgb[0] << 24 | rgb[1] << 16 | rgb[2] << 8 | 0x000000FF);
}

double abs_min(double a, double b)
{
    if (fabs(a) < fabs(b))
        return (fabs(a));
    return (fabs(b));
}

void draw_ceiling_3d(t_game *game)
{
    int y;
    int x;
    uint32_t color;

    y = 0;
    x = WIDTH_SCREEN / 2;
    color = rgb_to_hex(game->data->texture[5]);
    while (y < HEIGHT_SCREEN / 2)
    {
        x = WIDTH_SCREEN / 2;
        while (x < WIDTH_SCREEN)
        {
            mlx_put_pixel(game->img, x, y, color);      //Testing 
            x++;
        }
        y++;
    }
}

void draw_floor_3d(t_game *game)
{
    int y;
    int x;
    uint32_t color;

    y = HEIGHT_SCREEN / 2;
    x = WIDTH_SCREEN / 2;
    color = rgb_to_hex(game->data->texture[4]);
    while (y < HEIGHT_SCREEN)
    {
        x = WIDTH_SCREEN / 2;
        while (x < WIDTH_SCREEN)
        {
            mlx_put_pixel(game->img, x, y, color);         //Testing 
            x++;
        }
        y++;
    }
}