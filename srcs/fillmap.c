/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 06:11:57 by mgamil            #+#    #+#             */
/*   Updated: 2022/11/21 10:41:00 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_toimage(t_data *data)
{
	int a[2];

	data->img[0] = mlx_xpm_file_to_image(data->mlx, "./sprites/stone.xpm", &a[0], &a[1]);
	data->img[1] = mlx_xpm_file_to_image(data->mlx, "./sprites/mgamil.xpm", &a[0], &a[1]);
	data->img[2] = mlx_xpm_file_to_image(data->mlx, "./sprites/jm2.xpm", &a[0], &a[1]);
	data->img[5] = mlx_xpm_file_to_image(data->mlx, "./sprites/jmstone.xpm", &a[0], &a[1]);
	data->img[3] = mlx_xpm_file_to_image(data->mlx, "./sprites/brick.xpm", &a[0], &a[1]);
	data->img[4] = mlx_xpm_file_to_image(data->mlx, "./sprites/door.xpm", &a[0], &a[1]);
}

void	ft_fillmap(char ***tab, t_map *map, t_data *data)
{
	int	i;
	int	r;
	static int a = 0;
	i = 0;
	mlx_string_put(data->mlx, data->win, 64 * (map->x - 1), (map->y) + 15, 0x8b0000, "PLANTE LE");
	while (i < map->y)
	{
		r = 0;
		while (r < map->x)
		{
			ft_printf("i=%i,r:%i\n", i, r);
			if ((*tab)[i][r] == '0')
				mlx_put_image_to_window(data->mlx, data->win, data->img[0], r * 64 , i * 64);
			if ((*tab)[i][r] == 'P')
				mlx_put_image_to_window(data->mlx, data->win, data->img[1], r * 64 , i * 64);
			if ((*tab)[i][r] == 'C')
			{
				if (a % 2 == 0)
					mlx_put_image_to_window(data->mlx, data->win, data->img[2], r * 64 , i * 64);
				else
					mlx_put_image_to_window(data->mlx, data->win, data->img[5], r * 64 , i * 64);
			}
			if ((*tab)[i][r] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->img[3], r * 64 , i * 64);
			if ((*tab)[i][r] == 'E')
				mlx_put_image_to_window(data->mlx, data->win, data->img[4], r * 64 , i * 64);
			r++;
			a++;
		}
		i++;
	}
}
