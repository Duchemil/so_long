/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:31:32 by lduchemi          #+#    #+#             */
/*   Updated: 2023/11/28 15:37:40 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	buff_erase(char *buff)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buff[i] != '\n')
		i++;
	i++;
	while (j < ft_strlen(buff, 0) - i)
	{
		buff[j] = buff[i + j];
		j++;
	}
	buff[j] = '\0';
}

void	get_next_line(int fd, int line, t_info *map)
{
	static char	buff[10];
	int			byte;
	char		*dest;

	dest = NULL;
	byte = 1;
	if (fd < 0)
		return ;
	if (ft_gnl_strchr(buff) == 1)
	{
		buff_erase(buff);
		dest = ft_gnl_strjoin(dest, buff);
	}
	while (byte > 0 && ft_gnl_strchr(dest) == 0)
	{
		byte = read(fd, buff, 9);
		if (byte <= 0)
			map->map[line] = dest;
		buff[byte] = '\0';
		dest = ft_gnl_strjoin(dest, buff);
	}
	map->map[line] = dest;
}

void	reset_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->info.rows)
	{
		j = 0;
		while (data->info.map[i][j])
		{
			if (data->info.map[i][j] == 'V')
				data->info.map[i][j] = '0';
			else if (data->info.map[i][j] == 'C' || data->info.map[i][j] == 'c')
				data->info.map[i][j] = 'C';
			j++;
		}
		i++;
	}
	data->info.map[data->info.start.x][data->info.start.y] = 'P';
	data->info.map[data->info.exit.x][data->info.exit.y] = 'E';
}
