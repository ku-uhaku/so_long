#include "so_long.h"

static void check_syntax(t_map *map)
{
    int i = 0;
    char *str = map->map_string;
    while (str[i])
    {
        if (!(str[i] == '1' || str[i] == '0' || str[i] == 'P' ||
              str[i] == 'E' || str[i] == 'C' || str[i] == '\n'))
            throw_error("Error\nInvalid character in map\n");
        i++;
    }
}

static void check_shape(t_map *map)
{
    int width;
    int heigth;
    int i;

    width = ft_strlen(map->map[0]);
    heigth = map->height;
    i = 0;
    while (i < heigth)
    {
        if (ft_strlen(map->map[i]) != width)
            throw_error("The map is not rectangle");
        i++;
    }
}

static void check_wall(t_map *map)
{
    int i = 0;
    int j = 0;
    while (i < map->height)
    {
        if (map->map[i][0] != '1' || map->map[i][map->width - 1] != '1')
            throw_error("Error\nMap is not surrounded by walls\n");
        i++;
    }
    i = 0;
    while (j < map->width)
    {
        if (map->map[0][j] != '1' || map->map[map->height - 1][j] != '1')
            throw_error("Error\nMap is not surrounded by walls\n");
        j++;
    }
}

static void check_element(t_map *map)
{
    int i = 0;
    int j = 0;
    int player_count = 0;
    int exit_count = 0;
    int collect_count = 0;

    while (i < map->height)
    {
        j = 0;
        while (j < map->width)
        {
            if (map->map[i][j] == 'P')
                player_count++;
            if (map->map[i][j] == 'E')
                exit_count++;
            if (map->map[i][j] == 'C')
                collect_count++;
            j++;
        }
        i++;
    }

    if (player_count != 1 || exit_count != 1 || collect_count < 1)
        throw_error("Error\nMap must have exactly 1 player, 1 exit, and 1 collectible\n");
}

void valide_map(t_map *map)
{
    check_syntax(map);
    check_shape(map);
    check_wall(map);
    check_element(map);
    check_path(map);
}