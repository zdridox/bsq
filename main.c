#include <unistd.h>


char	**map_to_array();
void	print_arr(char **arr);
void	free_map(char **map);
void 	logic(char **arr, int *s_x, int *s_y, int *s_size);
void	place_box(char **arr, int x, int y, int size);

int main(int argc, char *argv[])
{
	char **_map;
	int save_x = 0;
	int save_y = 0;
	int save_size = 0;
	int i;

	i = 1;
	if (argc < 2)
		return (0);
	while (i < argc)
	{
		_map = map_to_array(argv[i]);
		logic(_map, &save_x, &save_y, &save_size);
		place_box(_map, save_x, save_y, save_size);
		print_arr(_map);
		free_map(_map);
		if(argc != 2 && i != argc - 1)
			write(1, "\n", 1);
		save_x = 0;
		save_y = 0;
		save_size = 0;
		i++;
	}
	return 0;
}