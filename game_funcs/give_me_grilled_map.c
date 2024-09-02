/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_me_grilled_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyasa <eyasa@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:58:04 by fekiz             #+#    #+#             */
/*   Updated: 2024/09/01 21:09:40 by eyasa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	grilled_draw(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->y_cord * 156)
	{
		x = 0;
		while (x < 156 * game->x_cord)
		{
			if (x % 156 == 0 || y % 156 == 0)
				game->wallpaper[x + y * game->x_cord * 156] = DARK;
			x++;
		}
		y++;
	}
}
