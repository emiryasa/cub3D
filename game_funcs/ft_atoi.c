/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekiz <fekiz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:13:13 by fekiz             #+#    #+#             */
/*   Updated: 2024/09/04 16:54:05 by fekiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	close_game(t_game *game, char *str, int x)
{
	if (str)
		ft_putstr_fd(str, 2);
	if (game->scene_ptr)
		mlx_destroy_image(game->mlx, game->scene_ptr);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	get_free(game);
	if (x)
		exit(1);
	exit (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	count;

	i = 0;
	sign = 1;
	count = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i])
	{
		if ((str[i] >= 'A' && str[i] <= 'Z')
			|| (str[i] >= 'a' && str[i] <= 'z'))
			return (-1);
		count = (str[i] - 48) + (10 * count);
		i++;
	}
	return (count * sign);
}
