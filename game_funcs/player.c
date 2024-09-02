/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyasa <eyasa@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 18:23:56 by fekiz             #+#    #+#             */
/*   Updated: 2024/09/01 21:15:58 by eyasa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
static void	move_player(t_game *game, int key);
void	rotate_player(t_game *game, bool rotate_right);
void	set_player_direction(t_game *game, char dir);
int	keys(int key, t_game *game)
{
	if (key == 53)
		return (close_game(game));
	if (key == 2 || key == 0 || key == 1 || key == 13)
		move_player(game, key);
	if (key == 123 || key == 124)
	{
		rotate_player(game, key == 124);
		mlx_clear_window(game->mlx, game->window);
		mlx_put_image_to_window(game->mlx, game->window, game->img_ptr, 0, 0);
	}
	return (0);
}

void	rotate_player(t_game *game, bool rotate_right)
{
	float	rot_speed;
	float	old_dir_x;
	float	old_plane_x;

	rot_speed = game->player.rot_speed * (rotate_right ? 1 : -1);

	old_dir_x = game->player.dir_x;
	old_plane_x = game->player.plane_x;

	game->player.dir_x = old_dir_x * cos(rot_speed) - game->player.dir_y * sin(rot_speed);
	game->player.dir_y = old_dir_x * sin(rot_speed) + game->player.dir_y * cos(rot_speed);

	game->player.plane_x = old_plane_x * cos(rot_speed) - game->player.plane_y * sin(rot_speed);
	game->player.plane_y = old_plane_x * sin(rot_speed) + game->player.plane_y * cos(rot_speed);
}

void	get_position(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'N' || game->map[i][j] == 'E'
				|| game->map[i][j] == 'W' || game->map[i][j] == 'S')
			{
				game->player.player_x = j;
				game->player.player_y = i;
				set_player_direction(game, game->map[i][j]);
			}
		}
	}
}

void	set_player_direction(t_game *game, char dir)
{
	if (dir == 'N')
	{
		game->player.dir_x = 0;
		game->player.dir_y = -1;
		game->player.plane_x = 0.66;
		game->player.plane_y = 0;
	}
	else if (dir == 'S')
	{
		game->player.dir_x = 0;
		game->player.dir_y = 1;
		game->player.plane_x = -0.66;
		game->player.plane_y = 0;
	}
	else if (dir == 'E')
	{
		game->player.dir_x = 1;
		game->player.dir_y = 0;
		game->player.plane_x = 0;
		game->player.plane_y = 0.66;
	}
	else if (dir == 'W')
	{
		game->player.dir_x = -1;
		game->player.dir_y = 0;
		game->player.plane_x = 0;
		game->player.plane_y = -0.66;
	}
}

static void	move_player(t_game *game, int key)
{
	float	move_step;

	move_step = game->player.move_speed;
	if (key == 13)
	{
		game->player.player_x += game->player.dir_x * move_step;
		game->player.player_y += game->player.dir_y * move_step;
	}
	if (key == 1)
	{
		game->player.player_x -= game->player.dir_x * move_step;
		game->player.player_y -= game->player.dir_y * move_step;
	}
	if (key == 0)
	{
		game->player.player_x += game->player.dir_y * move_step;
		game->player.player_y -= game->player.dir_x * move_step;
	}
	if (key == 2)
	{
		game->player.player_x -= game->player.dir_y * move_step;
		game->player.player_y += game->player.dir_x * move_step;
	}
	mlx_clear_window(game->mlx, game->window);
	mlx_put_image_to_window(game->mlx, game->window, game->img_ptr, 0, 0);
}

int	raycast(t_game *game)
{
	int		x;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		color;

	x = 0;
	while (x < WIN_WIDTH)
	{
		camera_x = 2 * x / (double)WIN_WIDTH - 1;
		ray_dir_x = game->player.dir_x + game->player.plane_x * camera_x;
		ray_dir_y = game->player.dir_y + game->player.plane_y * camera_x;
		map_x = (int)game->player.player_x;
		map_y = (int)game->player.player_y;
		delta_dist_x = fabs(1 / ray_dir_x);
		delta_dist_y = fabs(1 / ray_dir_y);
		hit = 0;
		if (ray_dir_x < 0)
		{
			step_x = -1;
			side_dist_x = (game->player.player_x - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0 - game->player.player_x) * delta_dist_x;
		}
		if (ray_dir_y < 0)
		{
			step_y = -1;
			side_dist_y = (game->player.player_y - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0 - game->player.player_y) * delta_dist_y;
		}
		while (hit == 0)
		{
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1;
			}
			if (game->map[map_x][map_y] == '1')
				hit = 1;
		}
		if (side == 0)
			perp_wall_dist = (map_x - game->player.player_x + (1 - step_x) / 2) / ray_dir_x;
		else
			perp_wall_dist = (map_y - game->player.player_y + (1 - step_y) / 2) / ray_dir_y;
		line_height = (int)(WIN_HEIGHT / perp_wall_dist);
		draw_start = -line_height / 2 + WIN_HEIGHT / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_height / 2 + WIN_HEIGHT / 2;
		if (draw_end >= WIN_HEIGHT)
			draw_end = WIN_HEIGHT - 1;
		color = (side == 1) ? 0xAAAAAA : 0xFFFFFF;
		for (int y = draw_start; y < draw_end; y++)
			mlx_pixel_put(game->mlx, game->window, x, y, color);
		x++;
	}
	return (0);
}
