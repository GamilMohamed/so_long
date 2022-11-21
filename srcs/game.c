/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 01:24:03 by mgamil            #+#    #+#             */
/*   Updated: 2022/11/21 09:57:30 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_vertical(t_data *data, int add)
{
	if (data->point.tab[data->point.pospy + add][data->point.pospx] == WALL)
		return (0);
	data->point.tab[data->point.pospy][data->point.pospx] = '0';
	data->point.pospy  += add;
	data->point.tab[data->point.pospy][data->point.pospx] = 'P';
	ft_fillmap(&data->point.tab, &data->point, data);
	return (1);
}

int	ft_horizontal(t_data *data, int add)
{
	if (data->point.tab[data->point.pospy][data->point.pospx + add] == WALL)
		return (0);
	data->point.tab[data->point.pospy][data->point.pospx] = '0';
	data->point.pospx += add;
	data->point.tab[data->point.pospy][data->point.pospx] = 'P';
	ft_fillmap(&data->point.tab, &data->point, data);
	return (1);
}


int	key_hook(int keycode, t_data *data)
{
	ft_getP(&data->point);
	// ft_printf("P[%i][%i]\n", data->point.pospx, data->point.pospy);
	if (keycode == W)
		ft_vertical(data, -1);
	if (keycode == A)
		ft_horizontal(data, -1);
	if (keycode == S)
		ft_vertical(data, 1);
	if (keycode == D)
		ft_horizontal(data, 1);
	if (keycode == ESC)
		return (mlx_loop_end(data->mlx));
	return (0);
}

int	ft_game(t_map *map)
{
	t_data	data;

	data.point = (*map);
	ft_printf("map size\nwitdth\t%i\nheight\t%i\n", map->x, map->y);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, map->x * 64, map->y * 64, "narvalo");
	ft_toimage(&data);
	ft_fillmap(&map->tab, map, &data);
	ft_printf("win size\nx\t%i\ny\t%i\n", map->x * 64, map->y * 64);
	// mlx_loop_hook(data.mlx, render_next_frame, data.mlx);
	ft_getP(map);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_loop(data.mlx);
	// int		mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string);
	return (0);
}
