/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzdrodow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:34:54 by mzdrodow          #+#    #+#             */
/*   Updated: 2025/07/17 00:49:28 by mzdrodow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

char	**map_to_array(char *file);
void	print_arr(char **arr);
void	free_map(char **map);
void	logic(char **arr, int *s_x, int *s_y, int *s_size);
void	place_box(char **arr, int x, int y, int size);
int	validator(char *file_name);
int	map_size(char *file);
void	set_global_chars(char *file_name);

void	try_file(char *file_name)
{
	char 	**_map;
	int 		save_x;
	int 		save_y;
	int 		save_size;

	save_x = 0;
	save_y = 0;
	save_size = 0;
	if(validator(file_name) == 0)
	{
		map_size(file_name);
		set_global_chars(file_name);
		_map = map_to_array(file_name);
		logic(_map, &save_x, &save_y, &save_size);
		place_box(_map, save_x, save_y, save_size);
		print_arr(_map);
		free_map(_map);
	}
}

void	try_from_stdin()
{
	int		size;
	char	buffer[1024];

	write(1, "file_name: ", 12);
	size = read(0, buffer, sizeof(buffer));
	if (size > 0)
	{
		buffer[size - 1] = '\0';
		try_file(buffer);
	}
}

int	main(int argc, char *argv[])
{
	int	i;

	i = 1;
	if (argc < 2)
	{
		try_from_stdin();
	}
	while (i < argc)
	{
		try_file(argv[i]);
		if(argc != 2 && i != argc - 1)
			write(1, "\n", 1);
		i++;
	}
	return 0;
}
