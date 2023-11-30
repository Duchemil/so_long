/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_winnable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:25:19 by lduchemi          #+#    #+#             */
/*   Updated: 2023/11/30 16:08:21 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	ft_ber(char *filename)
{
	int		len;
	int		fd;
	char	c;
	int		x;

	len = 0;
	x = 0;
	while (filename[len])
		len++;
	if (len < 4)
		return (0);
	if (filename[len - 4] == '.' && filename[len - 3] == 'b' && filename[len
			- 2] == 'e' && filename[len - 1] == 'r')
	{
		fd = open(filename, O_RDONLY);
		if (fd == -1)
			return (0);
		while (read(fd, &c, 1) > 0)
		{
			if (c != '\n')
				x++;
		}
		return (x);
	}
	return (0);
}

int	ft_walkable(t_data *data, int y, int x)
{
	if (data->info.map[y][x] == 'C')
	{
		data->info.map[y][x] = 'c';
		if (data->info.mapReset == 0)
			data->info.collec++;
		return (1);
	}
	else if (data->info.map[y][x] == '0' || data->info.map[y][x] == 'P'
		|| data->info.map[y][x] == 'E')
		return (1);
	else
		return (0);
}

int	ft_winnable(t_data *data, int y, int x)
{
	if (data->info.collec == data->info.collec_count
		&& data->info.mapReset == 0)
	{
		reset_map(data);
		data->info.mapReset = 1;
	}
	if (x == data->info.exit.y && y == data->info.exit.x
		&& data->info.collec == data->info.collec_count)
		return (1);
	if (ft_walkable(data, y, x) == 1)
	{
		if (data->info.map[y][x] != 'c' && data->info.map[y][x] != 'E')
			data->info.map[y][x] = 'V';
		if (ft_winnable(data, y + 1, x) == 1 || ft_winnable(data, y, x + 1) == 1
			|| ft_winnable(data, y - 1, x) == 1 || ft_winnable(data, y, x
				- 1) == 1)
			return (1);
		if (data->info.map[y][x] == 'C')
			data->info.collec--;
		else if (data->info.map[y][x] != 'P' && data->info.map[y][x] != 'E'
			&& data->info.map[y][x] == 'C')
			data->info.map[y][x] = '0';
		return (0);
	}
	return (0);
}

int	ft_init(t_data *data)
{
	data->info.collec_count = 0;
	data->info.exit.x = -1;
	data->info.exit.y = -1;
	data->info.start.x = -1;
	data->info.start.y = -1;
	data->info.rows = -1;
	data->info.movement.x = 0;
	data->info.movement.y = 0;
	data->info.count = 0;
	data->info.size = 32;
	data->info.map = NULL;
	data->info.collec = 0;
	data->info.frame = 0;
	data->info.mapReset = 0;
	if (ft_coin_path(data) == 0)
		return (0);
	return (1);
}

int	ft_check_size(t_data *data, char *argv)
{
	char	c;
	int		x;
	int		y;
	int		old_y;

	x = 0;
	y = 0;
	data->info.fd = open(argv, O_RDONLY);
	if (data->info.fd == -1)
		return (0);
	while (read(data->info.fd, &c, 1) > 0)
	{
		if (c == '\n')
		{
			x++;
			y = 0;
		}
		else
			y++;
		if (x > 34 || y > 60)
			return (close(data->info.fd), 1);
		if (y > 0)
			old_y = y;
	}
	return (ft_fd(data, x, old_y), x);
}
