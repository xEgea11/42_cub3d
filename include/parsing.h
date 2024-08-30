
#ifndef PARSING_H
# define PARSING_H
# include "cub3d.h"

typedef struct s_txtr
{
	char			*key;
	char			*value;
	struct s_txtr	*next;
}	t_txtr;

typedef struct s_initData
{
    char    **map2d;
    char    **map2d_square;     // int map[][];   0->48;    1->49; 
    int     m_rows;             // HEIGHT_MAP
    int     m_cols;             // WIDTH_MAP
    int     width;
    int     height;
    int     player_x;           // X_PLAYER
    int     player_y;           // Y_PLAYER
    int     fd;
    int     counter;
    char    *line;
    char    *map;
    char    *tx2re;
    char    **texture;
    char    **floor;
    char    **ceiling;
    char    **rgb;
    t_txtr	*t;
} t_initData;

int parsing(int argc, char **argv, t_initData *data);
int extensionChecker(char *file);
/* MAP PARSING */
int read_map(char *file, t_initData *data);
int map_validation(t_initData *data);
int largest_line(t_initData *data);
int map_size(char **map);
char *fix_line(char *line, int maxlen);
int h_map(char **map);
int w_map(char **map);
void get_rows_cols(t_initData *data);
char *get_map(t_initData *data);
/* APROVE MAP */
int aprove_map(t_initData *data);
int check_texture_space(t_initData *data);
int check_texture_if_valid(char *line);
int parse_rgb(char **texture);
int count_vergules(char *rgb);
int check_pos_ofv(char *line);   /* mirarbienbien */
int check_duplicate(t_initData *data);
int check_first_last_line(char **map);
char *get_last_line(char **map);
int surrounded_by_one(char **map);
/* TEXTURES PARSING */
int check_color_texture(char *line);
int check_texture_mount(t_initData *data);
int list_texture(t_initData *data);
t_txtr    *new_texture(char *line);
int get_index(char *line, int i);
void	list_back_texture(t_txtr *texture, t_txtr *new);
int colors_texture(t_initData *data);
void	ft_process_rgb_color(t_txtr *tmp, t_initData *data);
int check_color_value(char **rgb);
/* PLAYER */
void get_player_position(t_initData *data);
/* FREE DATA */
int free_data(char *line, char *tx2re, int fd);
int free_array2D(char **array);
void free_map(t_initData *data);
void free_list(t_txtr *texture);
/* PRINTF ALL */
void print_initData(t_initData *data);

#endif 