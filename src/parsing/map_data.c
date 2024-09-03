
#include "cub3d.h"

int largest_line(t_initData *data)
{
    int i;
    int maxlen;
    int len;

    i = 0;
    maxlen = 0;
    while(data->map2d[i])
    {
        len = ft_strlen(data->map2d[i]);
        if(len > maxlen)
            maxlen = len;
        i++;
    }
    return(maxlen);
}

int map_size(char **map)
{
    int i;

    i = 0;
    while(map[i])
        i++;
    return(i);
}

char *fix_line(char *line, int maxlen)
{
    char *new_line;
    int i;

    new_line = ft_calloc(sizeof(char), maxlen + 1);
    if(!new_line)
        return(NULL);
    i = 0;
    while(line[i])
    {
        new_line[i] = line[i];
        i++;
    }
    while(i < maxlen)
    {
        new_line[i] = ' ';
        i++;
    }
	new_line[i] = '\0';
    return(new_line);
}

int	h_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] )
		{
			if (map[i][j] != ' ' && (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'W' || map[i][j] == 'E' || map[i][j] == '0'))
			{
				if ((map[i][j - 1] == ' ' || map[i][j + 1] == ' ') && (map[i][j] != '1'))
				{
					return (0);
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	w_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != ' ' && (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'W' || map[i][j] == 'E' || map[i][j] == '0'))
			{
				if ((map[i - 1][j] == ' ' || map[i + 1][j] == ' ') && (map[i][j] != '1'))
				{
					return (0);
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}
