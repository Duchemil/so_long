/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:33:51 by lduchemi          #+#    #+#             */
/*   Updated: 2023/11/23 16:37:22 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	ft_move(int key, t_data *data)
{
	if (ft_possible_move(key, data) != 1)
	{
		ft_change_text(data);
		data->info.count++;
		if (data->info.collec_count == 0
			&& data->info.map[data->info.player.y ][data->info.player.x] == 'E')
			{
				write(1, "C'est gagne !\n", 15);
				on_destroy(data);
			}
		return (0);
	}
	return (1);
}

int	ft_possible_move(int key, t_data *data)
{
	data->info.movement.y = 0;
	data->info.movement.x = 0;
	if (key == 119)
		data->info.movement.y = -1;
	else if (key == 97)
		data->info.movement.x = -1;
	else if (key == 115)
		data->info.movement.y = 1;
	else if (key == 100)
		data->info.movement.x = 1;
	if (data->info.map[data->info.player.y + data->info.movement.y]
		[data->info.player.x + data->info.movement.x] == '1')
			return (1);
	if (data->info.map[data->info.player.y + data->info.movement.y]
		[data->info.player.x + data->info.movement.x] == 'C'
		|| data->info.map[data->info.player.y + data->info.movement.y]
		[data->info.player.x + data->info.movement.x] == 'c')
		{
			data->info.collec_count--;
			data->info.map[data->info.player.y + data->info.movement.y]
				[data->info.player.x + data->info.movement.x] = '0';
		}
	return (0);
}

int	ft_change_text(t_data *data)
{
	int	text;
	int	size;
	int	x;
	int	y;

	size = data->info.size;
	x = data->info.player.x;
	y = data->info.player.y;
	text = 0;

	if (data->info.map[y][x] == 'E')
		text = 2;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[text],
		data->info.player.x * size, data->info.player.y * size);
	data->info.player.x = data->info.player.x + data->info.movement.x;
	data->info.player.y = data->info.player.y + data->info.movement.y;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[4],
		data->info.player.x * size, data->info.player.y * size);
	return (0);
}
