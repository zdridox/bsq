/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzdrodow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 02:46:28 by mzdrodow          #+#    #+#             */
/*   Updated: 2025/07/11 03:09:27 by mzdrodow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_numeric(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	if ((c >= 9 && c <= 13) || c == ' ')
		return (2);
	if (c == '-' || c == '+')
		return (2);
	return (0);
}

int	str_len_atoi(char *str)
{
	int	i;
	int	j;
	int	found_nb;

	i = 0;
	j = 0;
	found_nb = 0;
	while (str[i] != '\0')
	{
		if (found_nb == 0 && is_numeric(str[i]) == 1)
			found_nb = 1;
		if (found_nb != 0 && is_numeric(str[i]) != 1)
			break ;
		if (is_numeric(str[i]) == 1)
			j++;
		i++;
	}
	return (j);
}

int	multi(int a, int times)
{
	int	rs;
	int	i;

	rs = a;
	i = 0;
	while (i < times)
	{
		rs *= 10;
		i++;
	}
	return (rs);
}

void	set_vars_to_zero_stupid(int *a, int *b, int *c, int *d)
{
	*a = 0;
	*b = 0;
	*c = 0;
	*d = 0;
}

int	ft_atoi(char *str)
{
	int	rs;
	int	i;
	int	j;
	int	minuses;

	set_vars_to_zero_stupid(&rs, &i, &j, &minuses);
	while (str[i] != '\0')
	{
		if (rs != 0 && is_numeric(str[i]) != 1)
			break ;
		if (rs == 0 && is_numeric(str[i]) == 0)
			return (0);
		if (str[i] == '-')
			minuses++;
		if (is_numeric(str[i]) == 1)
		{
			rs += multi(str[i] - 48, str_len_atoi(str) - j - 1);
			j++;
		}
		i++;
	}
	if (minuses % 2 != 0)
		rs *= -1;
	return (rs);
}
