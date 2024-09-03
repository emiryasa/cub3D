/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyasa <eyasa@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:58:04 by fekiz             #+#    #+#             */
/*   Updated: 2024/09/02 20:40:34 by eyasa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_scene(t_game *game, int x)
{
	t_ray	*ray;
	int		y;

	ray = game->ray;
	ray->step = 1.0 * TEX_HEIGHT / ray->line_height;
	ray->tex_pos = (ray->draw_start - WIN_HEIGHT / 2 + ray->line_height / 2)
		* ray->step;
	y = -1;
	while (++y <= ray->draw_start)
		game->scene[y * WIN_WIDTH + x] = game->c_color;
	while (y < ray->draw_end)
	{
		ray->tex_y = (int)ray->tex_pos & (TEX_HEIGHT - 1);
		ray->tex_pos += ray->step;
		ray->color = ray->texture[TEX_HEIGHT * ray->tex_y + ray->tex_x];
		game->scene[y * WIN_WIDTH + x] = ray->color;
		y++;
	}
	while (y < WIN_HEIGHT)
	{
		game->scene[y * WIN_WIDTH + x] = game->f_color;
		y++;
	}
}
