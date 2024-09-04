/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:51:06 by eyasa             #+#    #+#             */
/*   Updated: 2024/09/04 13:57:06 by fekiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	set_wall_texture(t_game *game)
{
	t_ray	*ray;

	ray = game->ray;
	if (ray->side == 0 && ray->ray_dir_x > 0)
		ray->texture = game->imgs.we_addr;
	else if (ray->side == 0 && ray->ray_dir_x < 0)
		ray->texture = game->imgs.ea_addr;
	else if (ray->side == 1 && ray->ray_dir_y > 0)
		ray->texture = game->imgs.no_addr;
	else
		ray->texture = game->imgs.so_addr;
	game->ray = ray;
}

void	set_texture_coordinate(t_game *game)
{
	t_ray	*ray;

	ray = game->ray;
	ray->tex_x = (int)(ray->wall_x * (double)(TEX_WIDTH));
	if (ray->side == 0 && ray->ray_dir_x > 0)
		ray->tex_x = TEX_WIDTH - ray->tex_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		ray->tex_x = TEX_WIDTH - ray->tex_x - 1;
	game->ray = ray;
}

void	set_wall_coordinate(t_game *game)
{
	t_ray	*ray;

	ray = game->ray;
	if (ray->side == 0)
		ray->wall_x = game->player->player_y + ray->perp_wall_dist
			* ray->ray_dir_y;
	else
		ray->wall_x = game->player->player_x + ray->perp_wall_dist
			* ray->ray_dir_x;
	ray->wall_x -= floor(ray->wall_x);
	game->ray = ray;
}
