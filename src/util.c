/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzdrodow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:35:04 by mzdrodow          #+#    #+#             */
/*   Updated: 2025/07/16 23:35:05 by mzdrodow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		get_g_x(void);
int		get_g_y(void);
char	*read_file(char *file);

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	print_arr(char **arr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < get_g_y())
	{
		while (j < get_g_x())
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
	int	i;

	i = 0;
	while (i < get_g_y())
	{
		free(map[i]);
		i++;
	}
	free(map);
}

char	*get_first_line(char *file)
{
	char	*str;
	int		size;
	int		i;
	char	*data;

	size = 0;
	i = 0;
	data = read_file(file);
	while (data[size] != '\n')
		size++;
	str = malloc(size + 1);
	while (i < size)
	{
		str[i] = data[i];
		i++;
	}
	str[i] = '\0';
	free(data);
	return (str);
}

int	str_len(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
