/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyasa <eyasa@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:31:41 by eyasa             #+#    #+#             */
/*   Updated: 2024/09/03 20:11:31 by eyasa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
		write(fd, &str[i++], 1);
}

void	*ft_calloc(size_t num_elements, size_t element_size)
{
	size_t	total_size;
	void	*memory;
	char	*ptr;
	size_t	i;

	total_size = num_elements * element_size;
	memory = malloc(total_size);
	if (!memory)
		return (0);
	else
	{
		ptr = (char *)memory;
		i = 0;
		while (i < total_size)
		{
			ptr[i] = 0;
			i++;
		}
	}
	return (memory);
}
