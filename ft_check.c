/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:47:55 by lduchemi          #+#    #+#             */
/*   Updated: 2023/11/14 17:04:27 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	ft_check_row(int nb_row, char **map)
{
	int	x;
	int	y;
	int	nb;

	x = 1;
	nb = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
			y++;
		if (nb == 0)
			nb = y;
		if (x != 0 && y != nb)
			return (-1);
		x++;
	}
	if (x != nb_row + 1 || x < 1 || y < 1)
		return (-1);
	return (x);
}

int	ft_cmp(char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
		i++;
	j = i - 3;
	while (j < i - 1)
	{
		if (str[j] == c)
			return (1);
		j++;
	}
	return (0);
}

int	ft_check_charac(char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (x == 0 && map[x][y] != '1' || y == 0 && map[x][y] != '1')
				return (0);
			if (map[x][y] == '1' || map[x][y] == '0' || map[x][y] == 'C'
					|| map[x][y] == 'E' || map[x][y] == 'P')
				y++;
			else
				return (0);
		}
		x++;
	}
	return (1);
}

int	ft_check_components(char **map)
{
	int	y;
	int	x;
	int	e;
	int	c;
	int	p;

	x = 0;
	y = 0;
	e = 0;
	p = 0;
	c = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'E')
		}
		x++;
	}
	if ()
	return (1);
}

int	ft_check(char **map, int nb_row)
{
	if (ft_check_charac(map) == 0 || ft_check_row(nb_row, map) == -1
		|| ft_check_first_row(map[0]) == 0)
		return (0);
	return (1);
}
