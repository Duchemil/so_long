/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:47:55 by lduchemi          #+#    #+#             */
/*   Updated: 2024/01/12 13:42:40 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	ft_check_comps(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < data->info.rows)
	{
		y = 0;
		while (data->info.map[x][y] != '\n')
		{
			if (data->info.map[x][y] == '0' || data->info.map[x][y] == '1'
				|| data->info.map[x][y] == 'C' || data->info.map[x][y] == 'E'
				|| data->info.map[x][y] == 'P' || data->info.map[x][y] == 'H')
			{
				if (ft_add_comps(data, x, y, data->info.map[x][y]) == 0)
					return (0);
				y++;
			}
			else
				return (0);
		}
		x++;
	}
	if (data->info.collec_count == 0)
		return (0);
	return (1);
}

int	ft_add_comps(t_data *data, int x, int y, char c)
{
	if (c == 'C')
		data->info.collec_count++;
	else if (c == 'E')
	{
		if (data->info.exit.x != -1 && data->info.exit.y != -1)
			return (0);
		data->info.exit.x = x;
		data->info.exit.y = y;
	}
	else if (c == 'P')
	{
		if (data->info.start.x != -1 && data->info.start.y != -1)
			return (0);
		data->info.start.x = x;
		data->info.start.y = y;
	}
	return (1);
}

int	ft_check_rec(t_data *data)
{
	int	x;
	int	y;
	int	last_y;

	x = 0;
	last_y = -1;
	while (x < data->info.rows)
	{
		y = 0;
		while (data->info.map[x][y])
		{
			if (data->info.map[x][y] == '\n')
				break ;
			y++;
			if (x == 0)
				last_y = y;
		}
		if (y != last_y)
		{
			write(2, "Error, map isn't rectangular.\n", 31);
			return (0);
		}
		x++;
	}
	return (1);
}

int	ft_check_closed(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < data->info.rows)
	{
		y = 0;
		while (data->info.map[x][y])
		{
			if (((x == 0) || (x == data->info.rows))
				&& data->info.map[x][y] != '1'
				&& data->info.map[x][y] != '\n')
				return (0);
			if (data->info.map[x][y] == '\n' && y != 0)
			{
				if (data->info.map[x][y - 1] != '1')
					return (0);
			}
			if (x == data->info.rows - 1 && data->info.map[x][y] == 'P')
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

int	ft_check(t_data *data)
{
	if (ft_check_comps(data) == 0)
	{
		write(2, "Error, map doesn't have the right components.\n", 47);
		return (0);
	}
	else if (ft_check_closed(data) == 0)
	{
		write(2, "Error, map isn't closed/surrounded by walls.\n", 46);
		return (0);
	}
	else if (ft_check_rec(data) == 0)
		return (0);
	else if ((data->info.start.x == -1 && data->info.start.y == -1)
		|| (data->info.exit.x == -1 && data->info.exit.y == -1))
	{
		write(2, "Error, map has no exit or player start.\n", 41);
		return (0);
	}
	else if (ft_winnable(data, data->info.start.x, data->info.start.y) != 1)
	{
		write(2, "Error, map isn't winnable\n", 27);
		return (0);
	}
	return (1);
}
