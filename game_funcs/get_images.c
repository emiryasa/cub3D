/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyasa <eyasa@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:17:37 by fekiz             #+#    #+#             */
/*   Updated: 2024/09/01 21:09:23 by eyasa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	get_images(t_game *game)
{
	int	x;
	int	y;
	int	z;

	game->imgs.ea = mlx_xpm_file_to_image(game->mlx, game->ea + 3, &x, &y);
	game->imgs.we = mlx_xpm_file_to_image(game->mlx, game->we + 3, &x, &y);
	game->imgs.so = mlx_xpm_file_to_image(game->mlx, game->so + 3, &x, &y);
	game->imgs.no = mlx_xpm_file_to_image(game->mlx, game->no + 3, &x, &y);
	if (!(game->imgs.ea) || !(game->imgs.we) || !(game->imgs.so)
		|| !(game->imgs.no))
		return (1);
	game->imgs.ea_addr = (int *)mlx_get_data_addr(game->imgs.ea, &x, &y, &z);
	game->imgs.we_addr = (int *)mlx_get_data_addr(game->imgs.we, &x, &y, &z);
	game->imgs.so_addr = (int *)mlx_get_data_addr(game->imgs.so, &x, &y, &z);
	game->imgs.no_addr = (int *)mlx_get_data_addr(game->imgs.no, &x, &y, &z);
	if (!(game->imgs.ea_addr) || !(game->imgs.no_addr) || !(game->imgs.we_addr)
		|| !(game->imgs.so_addr))
		return (1);
	return (0);
}
