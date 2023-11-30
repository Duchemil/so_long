/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:15:21 by lduchemi          #+#    #+#             */
/*   Updated: 2023/11/30 16:26:49 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	ft_animation(t_data *data)
{
	int	height;
	int	width;

	height = 16;
	width = 16;
	data->info.frame = (data->info.frame % 5) + 1;
	mlx_destroy_image(data->mlx_ptr, data->textures[3]);
	data->textures[3] = mlx_xpm_file_to_image(data->mlx_ptr,
			data->info.coin_path[data->info.frame], &width, &height);
	ft_print_anim(data);
	usleep(50000);
	return (0);
}

int	ft_coin_path(t_data *data)
{
	data->info.coin_path[0] = ft_strdup("./textures/coin-1.xpm");
	if (!data->info.coin_path[0])
		return (0);
	data->info.coin_path[1] = ft_strdup("./textures/coin-2.xpm");
	if (!data->info.coin_path[1])
		return (ft_free_coin(data, 1), 0);
	data->info.coin_path[2] = ft_strdup("./textures/coin-3.xpm");
	if (!data->info.coin_path[2])
		return (ft_free_coin(data, 2), 0);
	data->info.coin_path[3] = ft_strdup("./textures/coin-4.xpm");
	if (!data->info.coin_path[3])
		return (ft_free_coin(data, 3), 0);
	data->info.coin_path[4] = ft_strdup("./textures/coin-5.xpm");
	if (!data->info.coin_path[4])
		return (ft_free_coin(data, 4), 0);
	data->info.coin_path[5] = ft_strdup("./textures/coin-6.xpm");
	if (!data->info.coin_path[5])
		return (ft_free_coin(data, 5), 0);
	return (1);
}

void	ft_free_coin(t_data *data, int nb)
{
	int	i;

	i = 0;
	while (i <= nb)
	{
		free(data->info.coin_path[i]);
		i++;
	}
}
void	ft_print_anim(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->info.rows)
	{
		x = 0;
		while (data->info.map[y][x] != '\n')
		{
			if (data->info.map[y][x] == 'c' || data->info.map[y][x] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[3],
					x * data->info.size, y * data->info.size);
			x++;
		}
		y++;
	}
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 10, 0xFFFFFF, "Moves : ");
	data->info.mov_count = ft_itoa(data->info.count);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 60, 10, 0xFFFFFF, data->info.mov_count);
	free(data->info.mov_count);
}
