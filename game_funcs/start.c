/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyasa <eyasa@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:45:36 by fekiz             #+#    #+#             */
/*   Updated: 2024/09/02 20:43:39 by eyasa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
// void key_press(t_game *game)
// {
// 	game->key = 1;
// }

// void key_release(t_game *game)
// {
// 	game->key = 0;
// }

int	main_loop(void *p)
{
	t_game	*game;

	game = (t_game *)p;
	raycast(game);
	// mlx_put_image_to_window(game->mlx, game->win, game->img_ptr, 0, 0);
	return (0);
}

int	mlx_start(t_game *game)
{
	mlx_hook(game->win, 17, 2, close_game, game);
	// mlx_hook(game->win, 3, 1L << 1, key_release, game);
	// mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_loop_hook(game->mlx, main_loop, game);
	mlx_loop(game->mlx);
	return (0);
}

int	start(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (printf("error"),-1);
	game->win = mlx_new_window(game->mlx, PIXEL * game->x_cord,
			PIXEL * game->y_cord, "Cub3D");
	if (!game->win)
		return (-1);
	if (get_images(game))
		return (-1);
	get_position(game);
	if (create_scene(game))
		return (-1);
	game->ray = (t_ray *)malloc(sizeof(t_ray));
	if (!game->ray)
		return (-1);
	game->ray->draw_end = 0;
	game->ray->draw_start = 0;
	game->ray->line_height = 0;
	game->ray->perp_wall_dist = 0;
	game->ray->ray_dir_x = 0;
	game->ray->ray_dir_y = 0;
	game->ray->side = 0;
	game->ray->side_dist_x = 0;
	game->ray->side_dist_y = 0;
	game->ray->step_x = 0;
	game->ray->step_y = 0;
	game->ray->hit = 0;
	game->ray->delta_dist_x = 0;
	game->ray->delta_dist_y = 0;
	game->ray->tex_x = 0;
	game->ray->tex_y = 0;
	game->ray->texture = 0;
	game->ray->tex_pos = 0;
	game->ray->color = 0;
	game->ray->wall_x = 0;
	game->ray->step = 0;
	game->ray->cameraX = 0;
	if (mlx_start(game) == -1)
		return (-1);
	return (0);
}
