/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzdrodow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:35:08 by mzdrodow          #+#    #+#             */
/*   Updated: 2025/07/16 23:35:09 by mzdrodow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char	*read_file(char *file);
int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(char *str);
char	*get_first_line(char *file);
int		get_g_x(void);
int		get_g_y(void);
int		get_g_br(void);

int	read_checker(char *file_name)
{
	char	*data;

	data = read_file(file_name);
	if (ft_strcmp(data, "error") == 0)
	{
		write(1, "error while reading file.\n", 26);
		return (1);
	}
	free(data);
	return (0);
}

int	line_checker(int i, char *file)
{
	int		j;
	char	*data;
	int		newlines;

	j = 0;
	newlines = 0;
	data = read_file(file);
	while (j < get_g_br())
	{
		if (data[j] == '\n')
			newlines++;
		j++;
	}
	free(data);
	if ((newlines - 1) == i)
		return (0);
	write(1, "error map height not valid\n", 27);
	return (1);
}

int	validator(char *file_name)
{
	int res;
	char *first_line;

	res = 0;
	first_line = "";
	res += read_checker(file_name);
	if (res == 0)
	{
		first_line = get_first_line(file_name);
		res += line_checker(ft_atoi(first_line), file_name);
		free(first_line);
	}
	return (res);
}
