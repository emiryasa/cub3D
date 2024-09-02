/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyasa <eyasa@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 07:52:20 by fekiz             #+#    #+#             */
/*   Updated: 2024/09/01 21:11:15 by eyasa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "unistd.h"
# include "stdio.h"
# include "stdlib.h"
# include "fcntl.h"
# include "stdbool.h"
# include "../mlx/mlx.h"
# include "math.h"

# define PIXEL 96
# define DARK 0x00000
# define WHITE 0xFFFFFF

# define WIN_WIDTH  640
# define WIN_HEIGHT 480

# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_ESC 53

typedef struct imgs
{
	void	*ea;
	void	*we;
	void	*no;
	void	*so;
	char	*no_addr;
	char	*so_addr;
	char	*ea_addr;
	char	*we_addr;
}				t_imgs;

typedef struct fds
{
	int	north;
	int	south;
	int	west;
	int	east;
}			t_files;

typedef struct player
{
	float	move_speed;
	float	rot_speed;
	float	player_x;
	float	player_y;
	float	dir_x;
	float	dir_y;
	float	plane_x;
	float	plane_y;
}			t_player;

typedef struct cube3d
{
	char			**map_values;
	char			**map;
	char			**map_temp;
	char			*temp;
	char			*no;
	char			*we;
	char			*so;
	char			*ea;
	char			*f;
	char			*c;
	char			direction;
	void			*mlx;
	void			*window;
	void			*img_ptr;
	int				*wallpaper;
	int				*last_walls;
	int				fd;
	int				f_color;
	int				c_color;
	int				x_cord;
	int				y_cord;
	int				x;
	int				y;
	struct imgs		imgs;
	struct fds		files;
	struct player	player;
}					t_game;

t_game	*game_data_creats(char *av);

size_t	ft_strlen(const char *str);

char	*ft_get_read(int fd);
char	**ft_split(char *s, char c);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);

int		map_find(char **map, t_game *game);
int		map_check(char **map, t_game *game);
int		give_me_textures_and_colors(char **map, t_game *game);
int		file_name_control(char *s1, char *s2);
int		line_count(t_game *game);
int		any_zero_in_outside(char **map);
int		double_new_line(char *map);
int		start(t_game *game);
int		close_game(t_game *list);
int		ft_atoi(const char *str);
int		get_images(t_game *game);
int		create_wallpaper(t_game *game);
int		keys(int key, t_game *game);
int		raycast(t_game *game);

void	get_free(t_game *list);
void	set_nulls(t_game *game);
void	grilled_draw(t_game *game);
void	get_position(t_game *game);
void	draw_scene(t_game *game);

#endif
