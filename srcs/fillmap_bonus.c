/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillmap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 06:11:57 by mgamil            #+#    #+#             */
/*   Updated: 2022/11/23 20:32:33 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "../includes/so_long.h"

int	ft_checkimg(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 9)
		if (!data->img[i])
			return (0);
	i = -1;
	while (++i < 10)
		if (!data->roll[i])
			return (0);
	i = -1;
	while (++i < 3)
		if (!data->portal[i])
			return (0);
	return (1);
}

int	ft_toimage(t_data *data)
{
	int	a;

	data->img[0] = mlx_xpm_file_to_image(data->mlx, "s/stone.xpm", &a, &a);
	data->img[1] = mlx_xpm_file_to_image(data->mlx, "s/mgamil.xpm", &a, &a);
	data->img[2] = mlx_xpm_file_to_image(data->mlx, "s/jmright.xpm", &a, &a);
	data->img[3] = mlx_xpm_file_to_image(data->mlx, "s/jmleft.xpm", &a, &a);
	data->img[4] = mlx_xpm_file_to_image(data->mlx, "s/door.xpm", &a, &a);
	data->img[5] = mlx_xpm_file_to_image(data->mlx, "s/brick.xpm", &a, &a);
	data->img[6] = mlx_xpm_file_to_image(data->mlx, "s/brick2.xpm", &a, &a);
	data->img[7] = mlx_xpm_file_to_image(data->mlx, "s/maxou.xpm", &a, &a);
	data->img[8] = mlx_xpm_file_to_image(data->mlx, "s/maxou2.xpm", &a, &a);
	ft_numbers(data);
	ft_portal(data);
	if (ft_checkimg(data) == 0)
		return (0);
	return (1);
}

int	ft_freemlx(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 9)
		mlx_destroy_image(data->mlx, data->img[i]);
	i = -1;
	while (++i < 10)
		mlx_destroy_image(data->mlx, data->roll[i]);
	i = -1;
	while (++i < 3)
		mlx_destroy_image(data->mlx, data->portal[i]);
	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	return (0);
}

void	ft_fillmap(char ***tab, t_map *map, t_data *data)
{
	int			i;
	static int	z = 0;

	i = -1;
	while (++i < (map->x * map->y))
		if ((*tab)[i / map->x][i % map->x] == '0')
			mlx_put_image_to_window(data->mlx, data->win, \
				data->img[0], (i % map->x) * 64, (i / map->x) * 64);
	else if ((*tab)[i / map->x][i % map->x] == 'P')
		mlx_put_image_to_window(data->mlx, data->win, \
			data->img[1], (i % map->x) * 64, (i / map->x) * 64);
	else if ((*tab)[i / map->x][i % map->x] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->img[(rand() % \
			(3 - 2 + 1) + 2)], (i % map->x) * 64, (i / map->x) * 64);
	else if ((*tab)[i / map->x][i % map->x] == '1' && !z)
		mlx_put_image_to_window(data->mlx, data->win, data->img[(rand() % \
			(6 - 5 + 1) + 5)], (i % map->x) * 64, (i / map->x) * 64);
	else if ((*tab)[i / map->x][i % map->x] == 'E' && !z)
		mlx_put_image_to_window(data->mlx, data->win, \
				data->img[0], (i % map->x) * 64, (i / map->x) * 64);
	else if ((*tab)[i / map->x][i % map->x] == 'R')
		mlx_put_image_to_window(data->mlx, data->win, data->img[(rand() % \
			(8 - 7 + 1) + 7)], (i % map->x) * 64, (i / map->x) * 64);
	z = 1;
}
