/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:14:30 by mgamil            #+#    #+#             */
/*   Updated: 2022/11/20 06:23:19 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	ft_freeloop(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int		ft_checkline(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return 0;
	while (s[i])
	{
		if (s[i] != '1' && s[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

int		ft_checklenmap(int fd, t_map *map)
{
	int			i;
	size_t		len;
	char		*s;

	i = 0;
	map->y = 0;
	s = get_next_line(fd);
	map->x = ft_strlen(s);
	if (ft_checkline(s))
	{
		ft_printf("%s\n", "ici");
		free(s);
		return (0);
	}
	while (s)
	{
		len = ft_strlen(s);
		if (len != map->x || ((s[len - 2] != '1') || (s[0] != '1')))
			break;
		free(s);
		// ft_printf("%s", s);
		s = get_next_line(fd);
		map->y++;
	}
	// ft_printf("%s\n", s);
	if (len + 1 != map->x || ft_checkline(s))
	{
		free(s);
		return 0;
	}
	map->y++;
	free(s);
	return (1);
}

char	**ft_create_tab(size_t x, size_t y, int fd)
{
	char	**tab;
	char	*s;
	size_t		i;

	i = 0;
	tab = malloc(sizeof(char *) * (y + 1));
	if (!tab)
		return (NULL);
	while (i < y)
	{
		tab[i] = malloc(sizeof(char) * (x));
		if (!tab)
			return (NULL);
		s = get_next_line(fd);
		ft_strlcpy(tab[i], s, x);
		free(s);
		i++;
	}
	tab[i] = 0;	
	return (tab);
}

int		ft_isok(char c)
{
	if (c != WALL && c != GROUND && c != PLAYER && c != POLICE && c != COLLECT && c != EXIT && c != '\0')
	{
		printf("c=%c\n", c);
		return 1;
	}
	return (0);
}

void	ft_checktab(char **tab, t_map *map, size_t (*count)[2])
{
	size_t	i;

	i = 0;
	while (i < (map->x * map->y))
	{
		if (tab[i/map->x][i%map->x] == EXIT || tab[i/map->x][i%map->x] == COLLECT)
			(*count)[0]++;
		if (tab[i/map->x][i%map->x] == GROUND)
			(*count)[1]++;
		// ft_printf("tab[%i][%i]\n", i/map->x, i%map->x);
		if (ft_isok(tab[i/map->x][i%map->x]))
		{
			(*count)[0] = 0;
			return ;
		}
		i++;
	}
}
//							6		2		
int	ft_VIRUS(char ***tab, size_t y, size_t x, t_map *map)
{
	size_t col;
	size_t row;

	col = y;
	row = x;
	while ((*tab)[col][x] != WALL && col < map->y)
	{
		(*tab)[col][x] = '*';
		col++;
	}
	while ((*tab)[y][row] != WALL && row < map->x)
	{
		(*tab)[y][row] = '*';
		row++;
	}
	col = y;
	row = x;
	while ((*tab)[col][x] != WALL && col < map->y)
	{
		(*tab)[col][x] = '*';
		col--;
	}
	while ((*tab)[y][row] != WALL && row < map->x)
	{
		(*tab)[y][row] = '*';
		row--;
	}
	return 1;		
}

size_t	ft_COVID(char ***tab, t_map *map)
{
	size_t	i;
	size_t	stars;

	i = 0;
	stars = 0;
	while (i < (map->x * map->y))
	{
		// ft_printf("i=%i\n", i);
		if ((*tab)[i/map->x][i%map->x] == '*' || (*tab)[i/map->x][i%map->x] == 'P')
		{
			stars++;

			ft_VIRUS(tab, i/map->x, i%map->x, map);
		}
		i++;
	}
	map->num += 1;
	return stars;
}

int	ft_isE(char **tab, t_map *map)
{
	size_t i;

	i= 0;
	while (i < (map->x * map->y))
	{
		if (tab[i/map->x][i%map->x] == 'E')
		{
			return 1;
		}
		i++;
	}
	return 0;
}

int	main(int ac, char **av)
{
	int		fd;
	int		i;
	char	**tab;
	size_t	count[2];
	size_t	stars;
	t_map	map;

	map.num = 0;
	stars = 0;
	count[0] = 0;
	count[1] = 0;
	i = -1;
	if (ac != 2)
		return (ft_printf("./so_long maps\n"));
	if (open(av[1], O_RDONLY) < 3)
		return (0);
	fd = open(av[1], O_RDONLY);
	if (ft_checklenmap(fd, &map) == 0)
	{
		close(fd);
		return (ft_printf("invalid map\n"));
	}
	fd = open(av[1], O_RDONLY);
	ft_printf("map->x=%i\n", map.x);
	ft_printf("map->y=%i\n", map.y);
	tab = ft_create_tab(map.x, map.y, fd);
	if (!tab)
		return (ft_printf("malloc de tab echoue"));
	// while (tab[++i])
	// 	printf("tab[%i]=%s\n",i, tab[i]);
	ft_checktab(tab, &map, &count);
	if (count[0])
	{
		ft_printf("count[0]=%i\n", count[0]);
		ft_printf("count[1]=%i\n", count[1]);
		ft_printf("valid map\n");
		while (ft_isE(tab, &map))
		{
			stars = ft_COVID(&tab, &map);
			ft_printf("stars=%i,map.num:%i\n", stars, map.num);
			
			i = -1;
			while (tab[++i])
				ft_printf("%s\n", tab[i]);
		}
	}
	else
		printf("invalid map");
	printf("OKKKKKKKKKKK");
	ft_freeloop(tab);
}

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

	// s = ft_strnstr(av[1], ".ber", ft_strlen(av[1]));
	// if (ft_strlen(s) != 4)
	// 	return (ft_printf("%s\n", "fichier invalide"));
	// ft_printf("s=%s\n", "ok");
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