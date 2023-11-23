/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:45:38 by lduchemi          #+#    #+#             */
/*   Updated: 2023/11/23 16:11:48 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	ft_init_text(t_data *data, int width, int height)
{
	data->textures[0] = mlx_xpm_file_to_image(data->mlx_ptr, PATH_GROUND,
			&width, &height);
	if (!data->textures[0])
		return (free(data->mlx_ptr), 1);
	data->textures[1] = mlx_xpm_file_to_image(data->mlx_ptr, PATH_WALL, &width,
			&height);
	if (!data->textures[1])
		return (free(data->mlx_ptr), 1);
	data->textures[2] = mlx_xpm_file_to_image(data->mlx_ptr, PATH_EXIT, &width,
			&height);
	if (!data->textures[2])
		return (free(data->mlx_ptr), 1);
	data->textures[3] = mlx_xpm_file_to_image(data->mlx_ptr, PATH_COIN, &width,
			&height);
	if (!data->textures[3])
		return (free(data->mlx_ptr), 1);
	data->textures[4] = mlx_xpm_file_to_image(data->mlx_ptr, PATH_CHARACTER,
			&width, &height);
	if (!data->textures[4])
		return (free(data->mlx_ptr), 1);
	return (0);
}

void	ft_print(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->info.rows)
	{
		x = 0;
		while (data->info.map[y][x] != '\n')
		{
			ft_print2(x, y, data);
			x++;
		}
		y++;
	}
}

void	ft_print2(int x, int y, t_data *data)
{
	int	size;

	size = data->info.size;
	if (data->info.map[y][x] == 'V' || data->info.map[y][x] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[0],
				x * size, y * size);
	else if (data->info.map[y][x] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[1],
				x * size, y * size);
	else if (data->info.map[y][x] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[2],
				x * size, y * size);
	else if (data->info.map[y][x] == 'P')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[4],
				x * size, y * size);
		data->info.player.x = x;
		data->info.player.y = y;
	}
	else if (data->info.map[y][x] == 'c' || data->info.map[y][x] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[3],
				x * size, y * size);
}
