/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:14:30 by mgamil            #+#    #+#             */
/*   Updated: 2022/11/21 09:34:10 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void ft_getP(t_map *map)
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
	static int		count[3];
	t_map			map;
	char			**tab;

	map.num = 1;
	if (ac != 2 || ft_checkber(av[1]))
		return (ft_error(5));
	if (open(av[1], O_RDONLY) < 3)
		return (ft_printf("invalide"));
	if (ft_checkmap(av[1], &map, &count, &tab) == 0)
		return (0);
	int i = -1;
		while (tab[++i])
			ft_printf("%s\n", tab[i]);
	ft_freeloop(tab);
	tab = ft_create_tab(map.x, map.y, open(av[1], O_RDONLY));
	map.tab = tab;
	// ft_freeloop(tab);
	ft_printf("%gsuccess%0\n");
	ft_game(&map);
}
// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }


// int	main(void)
// {
// 	t_data	data;
// 	int	i, j;
// 	int	x;
// 	int	y;

// 	i = 0;
// 	j = 0;
// 	x = 300;
// 	y = 300;

// 	data.mlx = mlx_init();
// 	data.win = mlx_new_window(data.mlx, x, y, "Hello world!");
// 	data.img = mlx_new_image(data.mlx, x, y);
// 	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
//							 &data.line_length,
// 								&data.endian);
// 	while (i < y)
// 	{
// 		j = 0;
// 		while (j < x)
// 		{
// 			if (i < 100)
// 				my_mlx_pixel_put(&data, j++, i, 0x00FF0000);
// 			else if (i > 100 && i < 200)
// 				my_mlx_pixel_put(&data, j++, i, 0x00FFFFFF);
// 			else
// 				my_mlx_pixel_put(&data, j++, i, 0x00);

// 		}
// 		i++;
// 	}
// 	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
// 	// my_mlx_pixel_put(&data, 1000, 1000, 0x00FF0000);
// 	mlx_loop(data.mlx);

// }

	// for (int i = 0; i < 1920; i++){
	// 	for(int y = 0; y < 1080; y++) {
	// 		mlx_pixel_put(img.mlx ,img.win, i, y,  0x00FF0000);
	// 	}
	// }