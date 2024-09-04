/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:45:36 by fekiz             #+#    #+#             */
/*   Updated: 2024/09/04 16:38:18 by fekiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	key_press(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == KEY_ESC)
		close_game(game, NULL, 0);
	else if (keycode == KEY_W)
		game->move->w = 1;
	else if (keycode == KEY_S)
		game->move->s = 1;
	else if (keycode == KEY_A)
		game->move->a = 1;
	else if (keycode == KEY_D)
		game->move->d = 1;
	else if (keycode == KEY_RIGHT)
		game->move->right = 1;
	else if (keycode == KEY_LEFT)
		game->move->left = 1;
	return (0);
}

int	key_release(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == KEY_W)
		game->move->w = 0;
	else if (keycode == KEY_S)
		game->move->s = 0;
	else if (keycode == KEY_A)
		game->move->a = 0;
	else if (keycode == KEY_D)
		game->move->d = 0;
	else if (keycode == KEY_RIGHT)
		game->move->right = 0;
	else if (keycode == KEY_LEFT)
		game->move->left = 0;
	return (0);
}

int	key_hook(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	mlx_clear_window(game->mlx, game->win);
	if (game->move->w)
		move_player(game, game->player->dir_x * MOVE_SPEED,
			game->player->dir_y * MOVE_SPEED);
	if (game->move->s)
		move_player(game, -(game->player->dir_x * MOVE_SPEED),
			-(game->player->dir_y * MOVE_SPEED));
	if (game->move->a)
		move_player(game, -(game->player->dir_y * MOVE_SPEED),
			(game->player->dir_x * MOVE_SPEED));
	if (game->move->d)
		move_player(game, (game->player->dir_y * MOVE_SPEED),
			-(game->player->dir_x * MOVE_SPEED));
	if (game->move->right)
		rotate_player(game, -ROT_SPEED);
	if (game->move->left)
		rotate_player(game, ROT_SPEED);
	raycast(game);
	return (0);
}

int	mlx_start(t_game *game)
{
	mlx_hook(game->win, 17, 2, exit_game, game);
	mlx_hook(game->win, 3, 1L << 1, key_release, game);
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_loop_hook(game->mlx, key_hook, game);
	mlx_loop(game->mlx);
	return (0);
}

int	start(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		close_game(game, "Error\nMalloc\n", 1);
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!game->win)
		close_game(game, "Error\nMalloc\n", 1);
	if (get_images(game))
		close_game(game, "Error\nXpm file error", 1);
	if (create_scene(game))
		close_game(game, "Error\nImage error", 1);
	game->ray = ft_calloc(1, sizeof(t_ray));
	game->move = ft_calloc(1, sizeof(t_move));
	if (!game->ray)
		close_game(game, "Error\nMalloc\n", 1);
	mlx_start(game);
	return (0);
}
