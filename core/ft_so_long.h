/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:48:08 by lduchemi          #+#    #+#             */
/*   Updated: 2023/12/04 13:45:14 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# define PATH_GROUND "./textures/ground.xpm"
# define PATH_WALL "./textures/wall.xpm"
# define PATH_COIN "./textures/coin-1.xpm"
# define PATH_EXIT "./textures/exit.xpm"
# define PATH_CHARACTER "./textures/character.xpm"
# define WIDTH 1280
# define HEIGHT 720

typedef struct s_pos
{
	int		x;
	int		y;
}			t_pos;

typedef struct s_info_map
{
	char	**map;
	int		rows;
	int		cols;
	t_pos	exit;
	t_pos	start;
	t_pos	player;
	t_pos	movement;
	char	*mov_count;
	int		count;
	int		fd;
	int		size;
	int		off_x;
	int		off_y;
	int		collec_count;
	int		collec;
	int		map_reset;
}			t_info;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*textures[5];
	t_info	info;
}			t_data;

void		get_next_line(int fd, int line, t_info *map);
char		*ft_strndup(const char *src, int n);
int			ft_check_rec(t_data *data);
int			ft_change_text(t_data *data);
int			ft_move(int key, t_data *data);
void		ft_print2(int x, int y, t_data *data);
int			ft_check_size(t_data *data, char *argv);
int			on_destroy(t_data *data);
int			on_destroy3(t_data *data);
int			on_destroy2(t_data *data, int i);
int			ft_possible_move(int key, t_data *data);
int			ft_check(t_data *data);
int			ft_count_lines(int fd);
void		ft_init(t_data *data);
void		reset_map(t_data *data);
int			ft_ber(char *filename);
int			ft_fd(t_data *data, int x, int old_y);
void		ft_put_di(int number);
int			ft_so_long2(t_data *data, char *argv);
int			ft_init_text(t_data *data, int width, int height);
void		ft_print(t_data *data);
int			ft_winnable(t_data *data, int y, int x);
int			ft_walkable(t_data *data, int y, int x);
int			ft_add_comps(t_data *data, int x, int y, char c);
int			ft_check_closed(t_data *data);
int			ft_strlen(char *s, int j);
char		*test(char *s1, char *dest);
char		*ft_gnl_strjoin(char *s1, char *s2);
int			ft_gnl_strchr(char *s);
void		buff_erase(char *buff);

#endif
