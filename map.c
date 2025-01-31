#include "so_long.h"

static void set_map_string(t_map *map, char *file_map)
{
    int fd;
    char *line;
    char *temp;

    fd = open(file_map, O_RDONLY);
    if (fd < 0)
        throw_error("Error\nCannot open map file\n");

    map->map_string = ft_strdup("");
    if (!map->map_string)
        throw_error("Error\nMemory allocation failed\n");

    while ((line = get_next_line(fd)))
    {
        temp = map->map_string;
        map->map_string = ft_strjoin(temp, line);
        free(temp);
        free(line);
        if (!map->map_string)
            throw_error("Error\nMemory allocation failed\n");
    }
    close(fd);
    if (map->map_string[0] == '\0')
        throw_error("Error\nEmpty map file\n");
}

static void set_map_size(t_map *map)
{
    int i;
    int width;

    i = 0;
    width = 0;
    map->height = 0;

    while (map->map_string[i] && map->map_string[i] != '\n')
    {
        width++;
        i++;
    }
    map->width = width;

    i = 0;
    while (map->map_string[i])
    {
        if (map->map_string[i] == '\n')
            map->height++;
        i++;
    }
    map->height++;
}

static void set_map_counter(t_map *map)
{
    int counter_collectable = 0;
    // int counter_enemy = 0;
    int i = 0;

    while (map->map_string[i])
    {
        if (map->map_string[i] == 'C')
            counter_collectable++;
        i++;
    }
    map->collectable = counter_collectable;
}

static void set_2d_map(t_map *map)
{
    map->map = ft_split(map->map_string, '\n');
    if (!map->map)
        throw_error("Error\nFailed to split map\n");
}

void set_map(t_map *map, char *file_map)
{

    set_map_string(map, file_map);
    set_map_size(map);
    set_map_counter(map);
    set_2d_map(map);

    // printf("string:\n%s\n", map->map_string);
    // printf("width: %d\n", map->width);
    // printf("height: %d\n", map->height);
    // printf("collectable: %d\n", map->collectable);

    // printf("\n2D Map:\n");
    // i = 0;
    // while (i < map->height)
    // {
    //     printf("%s\n", map->map[i]);
    //     i++;
    // }
}