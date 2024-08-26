
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
	free_array2D(data->map2d);
	free_array2D(data->texture);
	if (data->floor)
		free_array2D(data->floor);
	if (data->ceiling)
		free_array2D(data->ceiling);
}

int free_data(char *line, char *tx2re, int fd)
{
    if(line)
        free(line);
    if(tx2re)
        free(tx2re);
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