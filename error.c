#include "so_long.h"

void throw_error(char *str)
{
    int i = 0;
    while (str[i])
    {
        write(2, &str[i], 1);
        i++;
    }
    exit(1);
}