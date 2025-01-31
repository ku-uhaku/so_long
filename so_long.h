#ifndef SO_LONG_H
#define SO_LONG_H

#include "./get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct s_map
{
    char **map;
    char *map_string;
    int width;
    int height;
    int collectable;
} t_map;

typedef struct s_position
{
    int x;
    int y;
} t_position;

typedef struct s_check
{
    char **temp_map;
    int collect_count;
    int found_exit;
    int target_collect;
} t_check;

/* Function prototypes */
void throw_error(char *str);
void so_long(char *file_map);
void set_map(t_map *map, char *file_map);
char **ft_split(char const *s, char c);
void valide_map(t_map *map);
void check_path(t_map *map);
int backtrack(t_check *check, t_position pos);

#endif