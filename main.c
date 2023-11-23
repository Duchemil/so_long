
#include "ft_so_long.h"

int on_destroy(t_data *data)
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
	while(x < data->info.rows)
	{
		free(data->info.map[x]);
		x++;
	}
	if (data->info.map)
	free(data->info.map);
	exit(0);
	return (0);
}

int on_keypress(int keysym, t_data *data)
{
	if (keysym == 53 || keysym == 65307)
		on_destroy(data);
	if (keysym == 119 || keysym == 97 || keysym == 115 || keysym == 100)
		ft_move(keysym, data);
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
void	ft_init(t_data *data, int *collec)
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
	*collec = 0;
}

int main(int argc, char **argv)
{
	t_data data;
	int	i = -1;
	int	fd = 0;
	int	collec;

	if (argc != 2 || ft_ber(argv[1]) == 0)
		return (0);
	ft_init(&data, &collec);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 720, 480, "Jeu banger");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
	ft_init_text(&data, 16, 16);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (on_destroy(&data));
	data.info.rows = ft_count_lines(fd);
	data.info.map = malloc(sizeof(char *) * data.info.rows);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (on_destroy(&data));
	while (++i < data.info.rows)
		get_next_line(fd, i, &data.info);
	if (ft_check(&data, collec) == 0)
		return (on_destroy(&data));
	ft_print(&data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
