#include <stdio.h>


char	**map_to_array();
void	print_arr(char **arr);
void	free_map(char **map);
void 	logic(char **arr, int *s_x, int *s_y, int *s_size);
void	place_box(char **arr, int x, int y, int size);

int main()
{
	char **_map;
	int save_x = 0;
	int save_y = 0;
	int save_size = 0;

	_map = map_to_array();
	logic(_map, &save_x, &save_y, &save_size);
	place_box(_map, save_x, save_y, save_size);
	printf("x:%d, y:%d, size:%d\n", save_x, save_y, save_size);
	print_arr(_map);
	free_map(_map);
	return 0;
}