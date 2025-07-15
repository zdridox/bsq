#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>

int g_size_x;
int g_size_y;

char	*read_file()
{
	char *file;
	int	fd;
	char *buffer;

	buffer = malloc(1024);
	file = "example_map";
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		//printf("error reading the file.\n");
	}

	int bytes_read = read(fd, buffer, 1024);
	buffer[bytes_read] = '\0';
	return buffer;
}

int map_size()
{
	int x;
	int y;
	char *data;

	data = read_file();
	x = 0;
	y = data[0] - '0';
	while(data[x + 5] != '\n')
		x++;
	free(data);
	g_size_x = x;
	g_size_y = y;
	return (x * y);
}

char	**map_to_array()
{
	char **map;
	char *data;
	int nl_counter;
	int i;
	int j;

	map_size();
	data = read_file();
	map = malloc(sizeof(char *) * g_size_y);
	nl_counter = 0;
	i = 5;
	j = 0;
	map[0] = malloc(g_size_x);
	while(nl_counter < g_size_y)
	{
		if (data[i] == '\n')
		{
			nl_counter++;
			j = 0;
			i++;
			if (nl_counter < g_size_y)
				map[nl_counter] = malloc(g_size_x);
		}
		if (nl_counter < g_size_y)
			map[nl_counter][j] = data[i];
		j++;
		i++;
	}
	free(data);
	return (map);
}

void	print_arr(char **arr)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < g_size_y)
	{
		while(j < g_size_x)
		{
			write(1, &arr[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		j = 0;
		i++;
	}
}

void	free_map(char **map)
{
	int i;

	i = 0;
	while(i < g_size_y)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int main()
{
	char **_map;

	_map = map_to_array();
	print_arr(_map);
	free_map(_map);
	return 0;
}