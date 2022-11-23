/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:14:30 by mgamil            #+#    #+#             */
/*   Updated: 2022/11/23 20:37:13 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	ft_close(t_data *data)
{
	return (mlx_loop_end(data->mlx));
}

int	ft_freenret(void *p)
{
	free(p);
	return (0);
}

void	ft_get_p(t_map *map)
{
	int	i;

	i = -1;
	while (++i < (map->x * map->y))
	{
		if (map->tab[i / map->x][i % map->x] == PLAYER)
		{
			map->pospx = i % map->x;
			map->pospy = i / map->x;
		}
	}
}

int	main(int ac, char **av)
{
	char			**tab;
	static t_map	map = {
		.count = {0},
		.num = 1,
		.y = 0
	};

	if (ac != 2 || ft_checkber(av[1]))
		return (ft_error(5));
	if (open(av[1], O_RDONLY) < 3)
		return (ft_printf("%rfichier non accessible!%0\n"));
	if (ft_checkmap(av[1], &map, &map.count, &tab) == 0)
		return (0);
	ft_freeloop(tab);
	tab = ft_create_tab(map.x, map.y, open(av[1], O_RDONLY));
	map.tab = tab;
	ft_printf("%ymap charged successfully%0\n");
	if (ft_game(&map) == 0)
	{
		ft_freeloop(tab);
		return (ft_error(6));
	}
	ft_freeloop(tab);
}
