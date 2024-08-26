
#include "cub3d.h"

void	free_list(t_txtr *texture)
{
	t_txtr	*tmp;

	tmp = texture;
	while (tmp)
	{
		texture = tmp->next;
		free(tmp->key);
		free(tmp->value);
		free(tmp);
		tmp = texture;
	}
	free(texture);
}

void	free_map(t_initData *data)
{
	free_array2D(data->map2d_square);
	data->map2d_square = NULL;
	free_array2D(data->map2d);
	data->map2d = NULL;
	free_array2D(data->texture);
	data->texture = NULL;
	if (data->floor)
	{
		free_array2D(data->floor);
		data->floor = NULL;
	}
	if (data->ceiling)
	{
		free_array2D(data->ceiling);
		data->ceiling = NULL;
	}
}

int free_data(char *line, char *tx2re, int fd)
{
    if(line)
	{
        free(line);
		line = NULL;
	}
    if(tx2re)
	{
        free(tx2re);
		tx2re = NULL;
	}
    if(fd)
        close(fd);
    return(0);
}

int free_array2D(char **array)
{
    int i;

    i = 0;
    while(array[i])
    {
        free(array[i]);
        i++;
    }
    free(array);
    return(0);
}