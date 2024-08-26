#include "cub3d.h"

int main(int argc, char **argv) {
    t_initData *data = malloc(sizeof(t_initData));

    if(!data)
        return (0);
    if(!parsing(argc, argv, data))
        return (0);
    print_initData(data);
    return (0);
}
