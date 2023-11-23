/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_winnable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:25:19 by lduchemi          #+#    #+#             */
/*   Updated: 2023/11/23 15:39:24 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	ft_ber(char *filename)
{
	int	len;

	len = 0;
	while (filename[len])
		len++;
	if (len < 4)
		return (0);
	if (filename[len - 4] == '.' &&
		filename[len - 3] == 'b' &&
		filename[len - 2] == 'e' &&
		filename[len - 1] == 'r')
		return (1);
	else
		return (0);
}

int	ft_walkable(t_data *data, int x, int y, int *collec)
{
	if (data->info.map[x][y] == 'C')
	{
		data->info.map[x][y] = 'c';
		(*collec)++;
		return (1);
	}
	else if (data->info.map[x][y] == '0' || data->info.map[x][y] == 'P'
			|| data->info.map[x][y] == 'E')
		return (1);
	else
		return (0);
}

int	ft_winnable(t_data *data, int x, int y, int *collec)
{
	if (x == data->info.exit.x && y == data->info.exit.y
		&& *collec == data->info.collec_count)
		return (1);
	if (ft_walkable(data, x, y, collec) == 1)
	{
		if (data->info.map[x][y] != 'E' && data->info.map[x][y] != 'c'
			&& data->info.map[x][y] != 'P')
			data->info.map[x][y] = 'V';
		if (ft_winnable(data, x + 1, y, collec) == 1 || ft_winnable(data, x, y
				+ 1, collec) == 1 || ft_winnable(data, x - 1, y, collec) == 1
			|| ft_winnable(data, x, y - 1, collec) == 1)
			return (1);
		if (data->info.map[x][y] == 'C')
			(*collec)--;
		return (0);
	}
	return (0);
}
