/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzdrodow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:34:41 by mzdrodow          #+#    #+#             */
/*   Updated: 2025/07/16 23:34:43 by mzdrodow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		get_g_x(void);
int		get_g_y(void);
char	*read_file(char *file);
int		str_len(char *str);
char	*get_first_line(char *file);

int	first_line_len(char *file)
{
	char	*first;
	int		size;

	first = get_first_line(file);
	size = str_len(first);
	free(first);
	return (size);
}

void	initial_vars(int *i, int *j, int *nl, char *file)
{
	*j = 0;
	*nl = 0;
	*i = first_line_len(file) + 1;
}

char	**map_alloc(void)
{
	char	**map;
	int		i;

	i = 0;
	map = malloc(sizeof(char *) * get_g_y());
	while (i < get_g_y())
	{
		map[i] = malloc(get_g_x());
		i++;
	}
	return (map);
}

char	**map_to_array(char *file)
{
	char **map;
	char *data;
	int nl_counter;
	int i;
	int j;

	map = map_alloc();
	data = read_file(file);
	initial_vars(&i, &j, &nl_counter, file);
	while (nl_counter < get_g_y())
	{
		if (j == get_g_x())
		{
			nl_counter++;
			j = 0;
			i++;
		}
		if (nl_counter < get_g_y())
			map[nl_counter][j] = data[i];
		j++;
		i++;
	}
	free(data);
	return (map);
}
