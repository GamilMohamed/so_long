/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plague.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:35:33 by mgamil            #+#    #+#             */
/*   Updated: 2022/11/22 20:56:43 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_covid(char ***tab, t_map *map)
{
	int	i;

	i = -1;
	map->num = 0;
	while (++i < (map->x * map->y))
	{
		if ((*tab)[i / map->x][i % map->x] == 'P'
			|| (*tab)[i / map->x][i % map->x] == '*')
		{
			ft_virus_row_b(tab, map, i / map->x, i % map->x);
			ft_virus_col_b(tab, map, i / map->x, i % map->x);
			ft_virus_col_h(tab, map, i / map->x, i % map->x);
			ft_virus_row_h(tab, map, i / map->x, i % map->x);
		}
	}
}

void	ft_virus_col_h(char ***tab, t_map *map, int y, int x)
{
	while (y >= 0 && y < map->y - 1
		&& (*tab)[y][x] != WALL && (*tab)[y][x] != POLICE)
	{
		if (!map->num)
			map->num = (*tab)[y][x] != '*';
		(*tab)[y][x] = '*';
		y++;
	}
}

void	ft_virus_col_b(char ***tab, t_map *map, int y, int x)
{
	while (y >= 0 && y < map->y - 1
		&& (*tab)[y][x] != WALL && (*tab)[y][x] != POLICE)
	{
		if (!map->num)
			map->num = (*tab)[y][x] != '*';
		(*tab)[y][x] = '*';
		y--;
	}
}

void	ft_virus_row_h(char ***tab, t_map *map, int y, int x)
{
	while (x >= 0 && x < map->x - 1
		&& (*tab)[y][x] != WALL && (*tab)[y][x] != POLICE)
	{
		if (!map->num)
			map->num = (*tab)[y][x] != '*';
		(*tab)[y][x] = '*';
		x++;
	}
}

void	ft_virus_row_b(char ***tab, t_map *map, int y, int x)
{
	while (x >= 0 && x < map->x - 1
		&& (*tab)[y][x] != WALL && (*tab)[y][x] != POLICE)
	{
		if (!map->num)
			map->num = (*tab)[y][x] != '*';
		(*tab)[y][x] = '*';
		x--;
	}
}
