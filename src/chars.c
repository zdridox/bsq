/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzdrodow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:34:45 by mzdrodow          #+#    #+#             */
/*   Updated: 2025/07/16 23:34:47 by mzdrodow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	g_obstacle;
char	g_full;
char	*get_first_line(char *file);
int		str_len(char *str);

char	get_g_obstacle(void)
{
	return (g_obstacle);
}

char	get_g_full(void)
{
	return (g_full);
}

void	set_global_chars(char *file_name)
{
	char *str;
	int fl_size;

	str = get_first_line(file_name);
	fl_size = str_len(str);
	g_full = str[fl_size - 1];
	g_obstacle = str[fl_size - 2];
	free(str);
}
