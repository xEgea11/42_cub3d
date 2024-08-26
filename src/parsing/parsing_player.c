
#include "cub3d.h"

void	get_player_position(t_initData *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map2d_square[i])
	{
		j = 0;
		while (data->map2d_square[i][j])
		{
			if (data->map2d_square[i][j] == 'N' || data->map2d_square[i][j] == 'S'
				|| data->map2d_square[i][j] == 'W' || data->map2d_square[i][j] == 'E')
			{
				data->player_x = j;
				data->player_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}
