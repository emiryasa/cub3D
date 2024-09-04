/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 07:52:20 by fekiz             #+#    #+#             */
/*   Updated: 2024/09/04 16:42:10 by fekiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include "fcntl.h"
# include "math.h"
# include "stdbool.h"
# include "stdio.h"
# include "stdlib.h"
# include "unistd.h"

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
# define TEX_WIDTH 64
# define TEX_HEIGHT 64
# define ROT_SPEED 0.05
# define MOVE_SPEED 0.05
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_ESC 53

typedef struct s_move
{
	int			w;
	int			a;
	int			s;
	int			d;
	int			left;
	int			right;
	int			shift;
}				t_move;

typedef struct s_imgs
{
	void		*ea;
	void		*we;
	void		*no;
	void		*so;
	int			*no_addr;
	int			*so_addr;
	int			*ea_addr;
	int			*we_addr;
}				t_imgs;

typedef struct s_files
{
	int			north;
	int			south;
	int			west;
	int			east;
}				t_files;

typedef struct s_ray
{
	double		ray_dir_x;
	double		ray_dir_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			tex_x;
	int			tex_y;
	int			*texture;
	double		tex_pos;
	int			color;
	double		wall_x;
	double		step;
	double		camerax;
}				t_ray;

typedef struct s_player
{
	float		player_x;
	float		player_y;
	float		dir_x;
	float		dir_y;
	float		plane_x;
	float		plane_y;
}				t_player;

typedef struct s_game
{
	char		**ccolor;
	char		**fcolor;
	char		**map_values;
	char		**map;
	char		**map_temp;
	char		*temp;
	char		*no;
	char		*we;
	char		*so;
	char		*ea;
	char		*f;
	char		*c;
	char		direction;
	void		*mlx;
	void		*win;
	void		*scene_ptr;
	int			*scene;
	int			*last_walls;
	int			fd;
	int			f_color;
	int			c_color;
	int			x_cord;
	int			y_cord;
	int			x;
	int			y;
	t_ray		*ray;
	t_imgs		imgs;
	t_files		files;
	t_player	*player;
	t_move		*move;
}				t_game;

t_game			*game_data_creats(char *av);

size_t			ft_strlen(const char *str);

char			*ft_get_read(int fd);
char			**ft_split(char *s, char c);
char			*ft_strdup(char *str);
char			*ft_strjoin(char *s1, char *s2);

int				map_find(char **map, t_game *game);
int				map_check(char **map, t_game *game);
int				give_me_textures_and_colors(char **map, t_game *game);
int				file_name_control(char *s1, char *s2);
int				line_count(t_game *game);
int				any_zero_in_outside(char **map);
int				double_new_line(char *map);
int				start(t_game *game);
int				close_game(t_game *game, char *str, int x);
int				ft_atoi(const char *str);
int				get_images(t_game *game);
int				create_scene(t_game *game);
int				control_fc(t_game *game);

void			get_free(t_game *list);
void			move_player(t_game *game, double next_x, double next_y);
void			rotate_player(t_game *game, double rot_speed);
void			draw_scene(t_game *game, int x);

void			set_wall_texture(t_game *game);
void			set_texture_coordinate(t_game *game);
void			set_wall_coordinate(t_game *game);
void			raycast(t_game *game);
void			*ft_calloc(size_t num_elements, size_t element_size);
void			ft_putstr_fd(char *str, int fd);
int				exit_game(t_game *game);

#endif
