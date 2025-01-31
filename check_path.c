#include "so_long.h"

static t_position find_player(char **map)
{
    t_position pos;

    pos.y = 0;
    while (map[pos.y])
    {
        pos.x = 0;
        while (map[pos.y][pos.x])
        {
            if (map[pos.y][pos.x] == 'P')
                return (pos);
            pos.x++;
        }
        pos.y++;
    }
    return (pos);
}

static char **copy_map(char **map)
{
    char **temp;
    int i;

    i = 0;
    while (map[i])
        i++;
    temp = malloc(sizeof(char *) * (i + 1));
    if (!temp)
        throw_error("Error\nMemory allocation failed\n");
    i = 0;
    while (map[i])
    {
        temp[i] = ft_strdup(map[i]);
        if (!temp[i])
            throw_error("Error\nMemory allocation failed\n");
        i++;
    }
    temp[i] = NULL;
    return (temp);
}

static t_position get_next_pos(t_position pos, int direction)
{
    t_position next;

    next = pos;
    if (direction == 0)
        next.x = pos.x + 1;
    else if (direction == 1)
        next.y = pos.y + 1;
    else if (direction == 2)
        next.x = pos.x - 1;
    else if (direction == 3)
        next.y = pos.y - 1;
    return (next);
}

int backtrack(t_check *check, t_position pos)
{
    t_position next;
    int i;

    if (check->temp_map[pos.y][pos.x] == '1' || check->temp_map[pos.y][pos.x] == 'V')
        return (0);
    if (check->temp_map[pos.y][pos.x] == 'C')
        check->collect_count++;
    if (check->temp_map[pos.y][pos.x] == 'E')
        check->found_exit = 1;
    check->temp_map[pos.y][pos.x] = 'V';
    if (check->collect_count == check->target_collect && check->found_exit)
        return (1);
    i = 0;
    while (i < 4)
    {
        next = get_next_pos(pos, i);
        if (backtrack(check, next))
            return (1);
        i++;
    }
    return (0);
}

void check_path(t_map *map)
{
    t_check check;
    t_position player_pos;
    int i;

    check.temp_map = copy_map(map->map);
    check.collect_count = 0;
    check.found_exit = 0;
    check.target_collect = map->collectable;
    player_pos = find_player(check.temp_map);
    if (!backtrack(&check, player_pos))
        throw_error("Error\nNo valid path to collect all items and exit\n");
    i = 0;
    while (check.temp_map[i])
        free(check.temp_map[i++]);
    free(check.temp_map);
}