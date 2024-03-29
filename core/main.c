/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:51:35 by lduchemi          #+#    #+#             */
/*   Updated: 2024/01/12 14:01:02 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	on_destroy2(t_data *data, int i)
{
	int	x;
	int	j;

	x = 0;
	j = 0;
	while (j < i - 1)
	{
		mlx_destroy_image(data->mlx_ptr, data->textures[j]);
		j++;
	}
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	while (x < data->info.rows)
	{
		free(data->info.map[x]);
		x++;
	}
	if (data->info.map)
		free(data->info.map);
	write(2, "Error, texture files have a problem\n", 37);
	exit(0);
	return (0);
}

int	on_destroy(t_data *data)
{
	int	x;

	x = 0;
	mlx_destroy_image(data->mlx_ptr, data->textures[0]);
	mlx_destroy_image(data->mlx_ptr, data->textures[1]);
	mlx_destroy_image(data->mlx_ptr, data->textures[2]);
	mlx_destroy_image(data->mlx_ptr, data->textures[3]);
	mlx_destroy_image(data->mlx_ptr, data->textures[4]);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	while (x < data->info.rows)
	{
		free(data->info.map[x]);
		x++;
	}
	if (data->info.map)
		free(data->info.map);
	exit(0);
	return (0);
}

int	on_keypress(int keysym, t_data *data)
{
	if (keysym == 53 || keysym == 65307)
		on_destroy(data);
	if (keysym == 119 || keysym == 97 || keysym == 115 || keysym == 100)
		ft_move(keysym, data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	if (argc != 2)
		return (write(2, "Error, args aren't correct\n", 28), 0);
	if (ft_ber(argv[1]) == 0)
		return (write(2, "Error, map's file isn't correct\n", 33), 0);
	ft_init(&data);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	if (ft_check_size(&data, argv[1]) == 1)
		return (on_destroy3(&data));
	data.win_ptr = mlx_new_window(data.mlx_ptr, 32 * data.info.off_x,
			data.info.off_y * 32, "So long");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	mlx_hook(data.win_ptr, DestroyNotify, (1L << 17), &on_destroy, &data);
	i = ft_init_text(&data, 16, 16);
	if (i != 0)
		on_destroy2(&data, i);
	if (!ft_so_long2(&data, argv[1]))
		return (0);
	return (0);
}

int	ft_so_long2(t_data *data, char *argv)
{
	int	fd;
	int	i;

	i = -1;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (on_destroy(data));
	data->info.rows = ft_count_lines(fd);
	if (data->info.rows != data->info.off_y)
	{
		data->info.rows = 0;
		return (write(2, "Map has empty lines\n", 21), on_destroy(data));
	}
	data->info.map = malloc(sizeof(char *) * data->info.rows);
	close(fd);
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (on_destroy(data));
	while (++i < data->info.rows)
		get_next_line(fd, i, &data->info);
	if (ft_check(data) == 0)
		return (on_destroy(data));
	ft_print(data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
