/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyasa <eyasa@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 18:23:56 by fekiz             #+#    #+#             */
/*   Updated: 2024/09/02 20:55:14 by eyasa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	move_player(t_game *game, int key);

int	keys(int key, t_game *game)
{
	if (key == 65307)
		return (close_game(game));
	if (key == 119 || key == 97 || key == 115 || key == 100)
		move_player(game, key);
	if (key == 123)
		rotate_player(game, -ROT_SPEED);
	if (key == 124)
		rotate_player(game, ROT_SPEED);
	return (0);
}

void	rotate_player(t_game *game, double rot_speed)
{
	float	old_dir_x;
	float	old_plane_x;

	old_dir_x = game->player.dir_x;
	old_plane_x = game->player.plane_x;
	game->player.dir_x = old_dir_x * cos(rot_speed) - game->player.dir_y
		* sin(rot_speed);
	game->player.dir_y = old_dir_x * sin(rot_speed) + game->player.dir_y
		* cos(rot_speed);
	game->player.plane_x = old_plane_x * cos(rot_speed) - game->player.plane_y
		* sin(rot_speed);
	game->player.plane_y = old_plane_x * sin(rot_speed) + game->player.plane_y
		* cos(rot_speed);
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
			}
		}
	}
}

static void	move_player(t_game *game, int key)
{
	if (key == 119)
	{
		game->player.player_x += game->player.dir_x * MOVE_SPEED;
		game->player.player_y += game->player.dir_y * MOVE_SPEED;
	}
	if (key == 115)
	{
		game->player.player_x -= game->player.dir_x * MOVE_SPEED;
		game->player.player_y -= game->player.dir_y * MOVE_SPEED;
	}
	if (key == 97)
	{
		game->player.player_x += game->player.dir_y * MOVE_SPEED;
		game->player.player_y -= game->player.dir_x * MOVE_SPEED;
	}
	if (key == 100)
	{
		game->player.player_x -= game->player.dir_y * MOVE_SPEED;
		game->player.player_y += game->player.dir_x * MOVE_SPEED;
	}
}
