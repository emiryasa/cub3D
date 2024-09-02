/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyasa <eyasa@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:45:36 by fekiz             #+#    #+#             */
/*   Updated: 2024/09/01 21:14:16 by eyasa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main_loop(void *p)
{
	t_game	*game;

	game = (t_game *)p;
	mlx_put_image_to_window(game->mlx, game->window, game->img_ptr, 0, 0);
	return (0);
}

int	mlx_start(t_game *game)
{
	mlx_hook(game->window, 17, 2, close_game, game);
	mlx_hook(game->window, 2, 1L << 0, keys, game);
	mlx_loop_hook(game->mlx, main_loop, game);
	mlx_loop(game->mlx);
	return (0);
}

int	start(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (-1);
	game->window = mlx_new_window(game->mlx, PIXEL * game->x_cord,
			PIXEL * game->y_cord, "Cub3D");
	if (!game->window)
		return (-1);
	if (get_images(game) == -1)
		return (-1);
	get_position(game);
	if (create_wallpaper(game) == -1)
		return (-1);
	if (!(game->wallpaper))
		return (-1);
	grilled_draw(game);
	if (mlx_start(game) == -1)
		return (-1);
	return (0);
}
