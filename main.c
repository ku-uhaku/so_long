#include "so_long.h"

void so_long(char *file_map)
{
	t_map map;

	set_map(&map, file_map);
	valide_map(&map);
}

int main(int ac, char **av)
{
	if (ac == 2)
		so_long(av[1]);
	else
		throw_error("./a.out <map.bre>\n");
}
