/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plague.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:35:33 by mgamil            #+#    #+#             */
/*   Updated: 2022/11/20 21:48:31 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_covid(char ***tab, t_map *map)
{
	int	i;

	i = -1;
	map->num = 0;
	while (++i < (map->x * map->y))
		if (((*tab)[i / map->x][i % map->x] == 'P')
			|| ((*tab)[i / map->x][i % map->x] == '*'))
			ft_plague((*tab), i / map->x, i % map->x, map);
}

void	ft_plague(char **tab, int y, int x, t_map *map)
{
	ft_virus_row_b(&tab, map, y, x);
	ft_virus_col_b(&tab, map, y, x);
	ft_virus_col_h(&tab, map, y, x);
	ft_virus_row_h(&tab, map, y, x);
}

void	ft_virus_col_h(char ***tab, t_map *map, int y, int x)
{
	while (y >= 0 && y < map->y - 1 && (*tab)[y][x] != WALL)
	{
		if (!map->num)
			map->num = (*tab)[y][x] != '*';
		(*tab)[y][x] = '*';
		y++;
	}
}

void	ft_virus_col_b(char ***tab, t_map *map, int y, int x)
{
	while (y >= 0 && y < map->y - 1 && (*tab)[y][x] != WALL)
	{
		if (!map->num)
			map->num = (*tab)[y][x] != '*';
		(*tab)[y][x] = '*';
		y--;
	}
}

void	ft_virus_row_h(char ***tab, t_map *map, int y, int x)
{
	while (x >= 0 && x < map->x - 1 && (*tab)[y][x] != WALL)
	{
		if (!map->num)
			map->num = (*tab)[y][x] != '*';
		(*tab)[y][x] = '*';
		x++;
	}
}

void	ft_virus_row_b(char ***tab, t_map *map, int y, int x)
{
	while (x >= 0 && x < map->x - 1 && (*tab)[y][x] != WALL)
	{
		if (!map->num)
			map->num = (*tab)[y][x] != '*';
		(*tab)[y][x] = '*';
		x--;
	}
}
