/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:45:38 by lduchemi          #+#    #+#             */
/*   Updated: 2023/11/21 17:15:15 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	ft_init_text(t_data *data)
{
	int	width;
	int	height;

	width = 16;
	height = 16;
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
	return (0);
}

void	ft_print(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < data->info.rows)
	{
		y = 0;
		while (data->info.map[x][y] != '\n')
		{
			if (data->info.map[x][y] == 'V' || data->info.map[x][y] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[0], y * 32 + 136, x * 32 + 116);
			else if (data->info.map[x][y] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[1], y * 32 + 136, x * 32 + 116);
			else if (data->info.map[x][y] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[2], y * 32 + 136, x * 32 + 116);
			if (data->info.map[x][y] == 'c' || data->info.map[x][y] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[3], y * 32 + 136, x * 32 + 116);
			y++;
		}
		x++;
	}
}
