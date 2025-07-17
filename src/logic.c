/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzdrodow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:34:50 by mzdrodow          #+#    #+#             */
/*   Updated: 2025/07/16 23:34:51 by mzdrodow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		get_g_x(void);
int		get_g_y(void);
char	get_g_obstacle(void);
char	get_g_full(void);

int	try_box(char **arr, int x, int y, int size)
{
	int	i;
	int	j;

	i = y;
	j = x;
	if (x + size > get_g_x() || y + size > get_g_y())
		return (1);
	while (i < y + size)
	{
		while (j < x + size)
		{
			if (arr[i][j] == get_g_obstacle())
				return (1);
			j++;
		}
		j = x;
		i++;
	}
	return (0);
}

int	check_cell(int x, int y, char **arr)
{
	int	i;

	i = 0;
	while (try_box(arr, x, y, i) == 0)
		i++;
	return (i - 1);
}

void	logic(char **arr, int *s_x, int *s_y, int *s_size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < get_g_y() - 1)
	{
		while (j < get_g_x() - 1)
		{
			if (check_cell(j, i, arr) > *s_size)
			{
				*s_x = j;
				*s_y = i;
				*s_size = check_cell(j, i, arr);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	place_box(char **arr, int x, int y, int size)
{
	int	i;
	int	j;

	i = y;
	j = x;
	while (i < y + size)
	{
		while (j < x + size)
		{
			arr[i][j] = get_g_full();
			j++;
		}
		j = x;
		i++;
	}
}
