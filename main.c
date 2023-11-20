#include "mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include "ft_so_long.h"

int on_destroy(t_data *data)
{
	int	x;

	x = 0;
	// mlx_destroy_image(data->mlx_ptr, data->textures[0]);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	while(x < data->info.rows)
	{
		free(data->info.map[x]);
		x++;
	}
	free(data->info.map);
	exit(0);
	return (0);
}

int on_keypress(int keysym, t_data *data)
{
	if (keysym == 53 || keysym == 65307)
		on_destroy(data);
	return (0);
}
int	ft_count_lines(int fd)
{
	char	c;
	char	last;
	int		nb;

	nb = 0;
	last = '#';
	while (read(fd, &c, 1) == 1)
	{
		if (c == '\n' && last != '\n')
			nb++;
		last = c;
	}
	return (nb);
}

int main(int argc, char **argv)
{
	t_data data;
	int	i = 0;
	int	fd = 0;
	int	collec;

	if (argc != 2)
		return (0);
	data.info.collec_count = 0;
	data.info.exit.x = -1;
	data.info.exit.y = -1;
	data.info.start.x = -1;
	data.info.start.y = -1;
	data.info.rows = -1;
	collec = 0;
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 720, 480, "Jeu banger");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);

	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (0);
	data.info.rows = ft_count_lines(fd);
	data.info.map = malloc(sizeof(char *) * data.info.rows);
	close(fd);
	fd = open(argv[1], O_RDONLY);
		while(i < data.info.rows)
	{
		get_next_line(fd, i, &data.info);
		i++;
	}
	ft_check(&data, collec);
	mlx_loop(data.mlx_ptr);
	return (0);
}
// Affichage textures
// int	width = 16;
// int height = 16;
// int x = 0;
// int y = 0;
// data.textures[0] = mlx_xpm_file_to_image(data.mlx_ptr, PATH_GROUND, &width, &height);
	// if (!data.textures[0])
	// 	return (free(data.mlx_ptr), 1);
	// while (x < width)
	// {
	// 	y = 0;
	// 	while (y < height)
	// 	{
	// 		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[0], x * 14 + 136, y * 14 + 116);
	// 		y++;
	// 	}
	// 	x++;
	// }
