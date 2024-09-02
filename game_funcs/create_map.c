/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyasa <eyasa@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:58:04 by fekiz             #+#    #+#             */
/*   Updated: 2024/09/01 20:54:58 by eyasa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	grilled_draw(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->y_cord * PIXEL)
	{
		x = 0;
		while (x < PIXEL * game->x_cord)
		{
			if (x % PIXEL == 0 || y % PIXEL == 0)
				game->wallpaper[x + y * game->x_cord * PIXEL] = DARK;
			x++;
		}
		y++;
	}
}
