/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:47:55 by lduchemi          #+#    #+#             */
/*   Updated: 2023/11/17 16:47:03 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

// int	ft_check_comps(t_data data)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	while (data.info.map[x])
// 	{
// 		y = 0;
// 		while (data.info.map[x][y])
// 		{
// 			if (data.info.map[x][y] == '0' || data.info.map[x][y] == '1'
// 				|| data.info.map[x][y] == 'C' || data.info.map[x][y] == 'E'
// 				|| data.info.map[x][y] == 'P')
// 			{
// 				if (ft_add_comps(data, x, y, data.info.map[x][y]) == 0)
// 					return (0);
// 				y++;
// 			}
// 			else
// 				return (0);
// 		}
// 		x++;
// 	}
// 	return (1);
// }
// int	ft_add_comps(t_data data, int x, int y, char c)
// {
// 	if (c == 'C')
// 		data.info.collec_count++;
// 	else if (c == 'E')
// 	{
// 		if (data.info.exit.x != -1 || data.info.exit.y != -1)
// 			return (0);
// 		data.info.exit.x = x;
// 		data.info.exit.y = y;
// 	}
// 	else if (c == 'P')
// 	{
// 		if (data.info.start.x != -1 || data.info.start.y != -1)
// 			return (0);
// 		data.info.start.x = x;
// 		data.info.start.y = y;
// 	}
// 	return (1);
// }
int	ft_check_rec(t_data data)
{
	int	x;
	int	y;
	int	last_y;

	x = 0;
	while(x < data.info.rows)
	{
		y = 0;
		while (data.info.map[x][y])
		{
			if (data.info.map[x][y] == '\n')
				break;
			y++;
			if (x == 0)
				last_y = y;
		}
		if (y != last_y)
			return (0);
		x++;
	}
	return (1);
}

// int	ft_check_charac(char **map)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	while (map[x])
// 	{
// 		y = 0;
// 		while (map[x][y])
// 		{
// 			if (x == 0 && map[x][y] != '1' || y == 0 && map[x][y] != '1')
// 				return (0);
// 			if (map[x][y] == '1' || map[x][y] == '0' || map[x][y] == 'C'
// 				|| map[x][y] == 'E' || map[x][y] == 'P')
// 				y++;
// 			else
// 				return (0);
// 		}
// 		x++;
// 	}
// 	return (1);
// }

// int	ft_check_components(char **map)
// {
// 	int	y;
// 	int	x;
// 	int	e;
// 	int	c;
// 	int	p;

// 	x = 0;
// 	y = 0;
// 	e = 0;
// 	p = 0;
// 	c = 0;
// 	while (map[x])
// 	{
// 		y = 0;
// 		while (map[x][y])
// 		{
// 			if (map[x][y] == 'E')
// 		}
// 		x++;
// 	}
// 	if ()
// 		return (1);
// }

int	ft_check(t_data data)
{
	if (ft_check_rec(data) == 0)
		return (0);
	return (1);
}
