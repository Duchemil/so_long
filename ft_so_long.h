/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:48:08 by lduchemi          #+#    #+#             */
/*   Updated: 2023/11/17 14:51:49 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# define PATH_GROUND "./textures/ground.xpm"
# define PATH_WALL "./textures/wall.xpm"
# define PATH_COIN "./textures/coin.xpm"
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
	int		collec_count;
}			t_info;

typedef struct s_data
{
	void *mlx_ptr;     // MLX pointer
	void *win_ptr;     // MLX window pointer
	void *textures[5]; // MLX image pointers (on the stack)
	t_info	info;
	// Map pointer (contains map details- preferably kept on the stack)
}			t_data;

void		get_next_line(int fd, int line, t_info *map);
char		*ft_strndup(const char *src, int n);
int			ft_check_rec(t_data data);
int			ft_check(t_data data);
int			ft_add_comps(t_data data, int x, int y, char c);
int			ft_gnl_strlen(char *s, int j);
char		*test(char *s1, char *dest);
char		*ft_gnl_strjoin(char *s1, char *s2);
int			ft_gnl_strchr(char *s);
void		buff_erase(char *buff);

#endif
