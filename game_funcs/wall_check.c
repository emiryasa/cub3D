/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyasa <eyasa@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 18:23:56 by fekiz             #+#    #+#             */
/*   Updated: 2024/09/01 21:01:48 by eyasa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	can_move(char **map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	// F'lerin etrafını kontrol et.
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'F')
			{
				if (i == 0)
				{
					if (map[i][j - 1] != 'F' && map[i][j - 1] != '1')
						return (-1);
					else if (map[i][j + 1] != 'F' && map[i][j + 1] != '1')
						return (-1);
					else if (map[i + 1][j] != 'F' && map[i + 1][j] != '1')
						return (-1);
				}
			}
		}
	}
	return (0);
}
