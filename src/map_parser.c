/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzdrodow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:34:59 by mzdrodow          #+#    #+#             */
/*   Updated: 2025/07/16 23:37:32 by mzdrodow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int		g_size_x;
int		g_size_y;
int		g_read_bytes;
char	*get_first_line(char *data);
int		ft_atoi(char *str);
int		str_len(char *str);

int	get_g_x(void)
{
	return (g_size_x);
}

int	get_g_y(void)
{
	return (g_size_y);
}

int	get_g_br(void)
{
	return (g_read_bytes);
}

char	*read_file(char *file)
{
	int		fd;
	int		size;
	char	*buffer;
	int		bytes_read;

	fd = open(file, O_RDONLY);
	size = 0;
	if (fd == -1)
	{
		return ("error");
	}
	buffer = malloc(1024);
	bytes_read = read(fd, buffer, sizeof(buffer));
	while (bytes_read > 0)
	{
		size += bytes_read;
		bytes_read = read(fd, buffer, sizeof(buffer));
	}
	close(fd);
	free(buffer);
	buffer = malloc(size);
	fd = open(file, O_RDONLY);
	bytes_read = read(fd, buffer, size);
	g_read_bytes = bytes_read;
	return (buffer);
}

int	map_size(char *file)
{
	int		x;
	int		y;
	char	*data;
	char	*first_line;

	data = read_file(file);
	x = 0;
	first_line = get_first_line(file);
	y = ft_atoi(first_line);
	while (data[x + str_len(first_line) + 1] != '\n')
		x++;
	free(first_line);
	free(data);
	g_size_x = x;
	g_size_y = y;
	return (x * y);
}
