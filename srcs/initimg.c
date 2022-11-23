/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initimg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:17:31 by mgamil            #+#    #+#             */
/*   Updated: 2022/11/23 20:30:50 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_numbers(t_data *data)
{
	int	a;

	data->roll[0] = mlx_xpm_file_to_image(data->mlx, "s/0.xpm", &a, &a);
	data->roll[1] = mlx_xpm_file_to_image(data->mlx, "s/1.xpm", &a, &a);
	data->roll[2] = mlx_xpm_file_to_image(data->mlx, "s/2.xpm", &a, &a);
	data->roll[3] = mlx_xpm_file_to_image(data->mlx, "s/3.xpm", &a, &a);
	data->roll[4] = mlx_xpm_file_to_image(data->mlx, "s/4.xpm", &a, &a);
	data->roll[5] = mlx_xpm_file_to_image(data->mlx, "s/5.xpm", &a, &a);
	data->roll[6] = mlx_xpm_file_to_image(data->mlx, "s/6.xpm", &a, &a);
	data->roll[7] = mlx_xpm_file_to_image(data->mlx, "s/7.xpm", &a, &a);
	data->roll[8] = mlx_xpm_file_to_image(data->mlx, "s/8.xpm", &a, &a);
	data->roll[9] = mlx_xpm_file_to_image(data->mlx, "s/9.xpm", &a, &a);
}

void	ft_void(t_map *map, t_data *data)
{
	if (map->cond >= 1)
		mlx_put_image_to_window(data->mlx, data->win, data->portal[0], \
			map->posex * 64, map->posey * 64);
	if (map->cond >= 2)
		mlx_put_image_to_window(data->mlx, data->win, data->portal[1], \
			map->posex * 64, map->posey * 64);
	if (map->cond >= 3)
		mlx_put_image_to_window(data->mlx, data->win, data->portal[2], \
		map->posex * 64, map->posey * 64);
}

void	ft_portal(t_data *data)
{
	int	a;

	data->portal[0] = mlx_xpm_file_to_image(data->mlx, "s/door1.xpm", &a, &a);
	data->portal[1] = mlx_xpm_file_to_image(data->mlx, "s/door2.xpm", &a, &a);
	data->portal[2] = mlx_xpm_file_to_image(data->mlx, "s/door3.xpm", &a, &a);
}

void	ft_putnbr_sprite(int nb, t_data *data, t_map *map)
{
	mlx_put_image_to_window(data->mlx, data->win, data->roll[(nb / 100) % 10], \
		map->x / 2 * 64 - 128, (map->y - 1) * 64);
	mlx_put_image_to_window(data->mlx, data->win, data->roll[(nb / 10) % 10], \
		map->x / 2 * 64 - 64, (map->y -1) * 64);
	mlx_put_image_to_window(data->mlx, data->win, data->roll[nb % 10], \
		map->x / 2 * 64, (map->y - 1) * 64);
}

void	ft_fillstats(t_map *map, t_data *data)
{
	int	width;
	int	height;
	int	i;
	int	j;

	width = map->x + 1;
	i = map->x - 1;
	height = map-> y;
	while (i < width)
	{
		j = 0;
		while (j < height)
		{
			mlx_put_image_to_window(data->mlx, data->win, data->img[4], \
				i * 64, j * 64);
			ft_putnbr_sprite(map->keycount, data, map);
			j++;
		}
		i++;
	}
	ft_void(map, data);
}
