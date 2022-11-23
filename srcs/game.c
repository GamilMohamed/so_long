/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 01:24:03 by mgamil            #+#    #+#             */
/*   Updated: 2022/11/23 20:40:07 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_vertical(t_data *data, int add)
{
	data->point.keycount++;
	if (data->point.tab[data->point.pospy + add][data->point.pospx] == WALL)
		return (0);
	if (data->point.tab[data->point.pospy + add][data->point.pospx] == POLICE)
	{
		ft_printf("%rYOU TOUCHED %mMAXOU%r, YOU'RE DEAD.%0\n");
		return (mlx_loop_end(data->mlx));
	}
	if (data->point.tab[data->point.pospy + add][data->point.pospx] == COLLECT)
		ft_printf("%i/%i JM's\n", ++data->point.c_count, data->point.count[1]);
	if (data->point.c_count == data->point.count[1] && data->point.cond < 3)
		ft_printf("%bTHE PORTAL IS APPEARING..%0\n", data->point.cond++);
	if (data->point.cond > 0 && data->point.posex == data->point.pospx
		&& data->point.posey == data->point.pospy + add)
	{
		ft_printf("%gYOU MADE IT IN %i STEPS%0\n", data->point.keycount);
		return (mlx_loop_end(data->mlx));
	}	
	data->point.tab[data->point.pospy][data->point.pospx] = '0';
	data->point.pospy += add;
	data->point.tab[data->point.pospy][data->point.pospx] = 'P';
	ft_fillmap(&data->point.tab, &data->point, data);
	ft_fillstats(&data->point, data);
	return (1);
}

int	ft_horizontal(t_data *data, int add)
{
	data->point.keycount++;
	if (data->point.tab[data->point.pospy][data->point.pospx + add] == WALL)
		return (0);
	if (data->point.tab[data->point.pospy][data->point.pospx + add] == POLICE)
	{
		ft_printf("%rYOU TOUCHED %mMAXOU%r, YOU'RE DEAD.%0\n");
		return (mlx_loop_end(data->mlx));
	}
	if (data->point.tab[data->point.pospy][data->point.pospx + add] == COLLECT)
		ft_printf("%i/%i JM's\n", ++data->point.c_count, data->point.count[1]);
	if (data->point.c_count == data->point.count[1] && data->point.cond < 3)
		ft_printf("%bTHE PORTAL IS APPEARING..%0\n", data->point.cond++);
	if (data->point.cond > 0 && data->point.posex == data->point.pospx + add
		&& data->point.posey == data->point.pospy)
	{
		ft_printf("%gYOU MADE IT IN %i STEPS%0\n", data->point.keycount);
		return (mlx_loop_end(data->mlx));
	}	
	data->point.tab[data->point.pospy][data->point.pospx] = '0';
	data->point.pospx += add;
	data->point.tab[data->point.pospy][data->point.pospx] = 'P';
	ft_fillmap(&data->point.tab, &data->point, data);
	ft_fillstats(&data->point, data);
	return (1);
}

int	key_hook(int keycode, t_data *data)
{
	ft_get_p(&data->point);
	if (keycode == W || keycode == UP)
		ft_vertical(data, -1);
	if (keycode == A || keycode == LEFT)
		ft_horizontal(data, -1);
	if (keycode == S || keycode == DOWN)
		ft_vertical(data, 1);
	if (keycode == D || keycode == RIGHT)
		ft_horizontal(data, 1);
	if (keycode == ESC || keycode == Q)
		return (mlx_loop_end(data->mlx));
	return (0);
}

int	ft_freewin(t_data *data, int boolean)
{
	if (boolean == 1)
	{
		mlx_clear_window(data->mlx, data->win);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
	}
	free(data->mlx);
	return (0);
}

int	ft_game(t_map *map)
{
	t_data	data;

	map->keycount = 0;
	map->cond = 0;
	data.point = (*map);
	data.point.c_count = 0;
	ft_checktab(map->tab, map, &map->count);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (0);
	data.win = mlx_new_window(data.mlx, map->x * 64 - 64, map->y * 64, "GAME");
	if (!data.win)
		return (ft_freewin(&data, 0));
	if (ft_toimage(&data) == 0)
		return (ft_freewin(&data, 1));
	ft_fillmap(&map->tab, map, &data);
	mlx_hook(data.win, data.point.c_count, 1L << 0, &key_hook, &data);
	mlx_hook(data.win, 17, 0, &ft_close, &data);
	ft_printf("ok\n");
	ft_fillstats(map, &data);
	ft_get_p(map);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_loop(data.mlx);
	ft_freemlx(&data);
	return (1);
}
