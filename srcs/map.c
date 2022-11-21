/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:14:30 by mgamil            #+#    #+#             */
/*   Updated: 2022/11/21 08:33:20 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_checkline(char *s)
{
	int	i;

	i = -1;
	if (!s)
		return (0);
	while (s[++i])
		if (s[i] != '1' && s[i] != '\n')
			return (1);
	return (0);
}

int	ft_checklenmap(int fd, t_map *map)
{
	int			i;
	int			len;
	char		*s;

	i = 0;
	map->y = 0;
	s = get_next_line(fd);
	map->x = ft_strlen(s);
	if (ft_checkline(s))
	{
		free(s);
		return (0);
	}
	while (s)
	{
		len = ft_strlen(s);
		if (len != map->x || ((s[len - 2] != '1') || (s[0] != '1')))
			break ;
		free(s);
		s = get_next_line(fd);
		map->y++;
	}
	if (len + 1 != map->x || ft_checkline(s))
	{
		free(s);
		return (0);
	}
	map->y++;
	free(s);
	return (1);
}

char	**ft_create_tab(int x, int y, int fd)
{
	char	**tab;
	char	*s;
	int		i;

	i = 0;
	tab = malloc(sizeof(char *) * (y + 1));
	if (!tab)
	{
		ft_freeloop(tab);
		return (NULL);
	}
	while (i < y)
	{
		tab[i] = malloc(sizeof(char) * (x));
		if (!tab[i])
		{
			ft_freeloop(tab);
			return (NULL);
		}
		s = get_next_line(fd);
		ft_strlcpy(tab[i], s, x);
		free(s);
		i++;
	}
	tab[i] = 0;
	return (tab);
}

int	ft_checktab(char **tab, t_map *map, int (*count)[3])
{
	int	i;

	i = -1;
	while (++i < (map->x * map->y))
	{
		if (tab[i / map->x][i % map->x] == EXIT)
			(*count)[0]++;
		else if (tab[i / map->x][i % map->x] == COLLECT)
			(*count)[1]++;
		else if (tab[i / map->x][i % map->x] == PLAYER)
			(*count)[2]++;
		else if (ft_isok(tab[i / map->x][i % map->x]))
		{
			(*count)[0] = 0;
			return (ft_error(5));
		}
	}
	return (1);
}

int	ft_checkmap(char *ber, t_map *map, int (*count)[3], char ***tab)
{
	int		fd;

	fd = open(ber, O_RDONLY);
	if (ft_checklenmap(fd, map) == 0)
		return (ft_error(1));
	fd = open(ber, O_RDONLY);
	(*tab) = ft_create_tab(map->x, map->y, fd);
	if (!*tab)
	{
		ft_printf("sal");
		return (ft_error(ft_freeloop((*tab)) + 1));
	}
	if (ft_checktab((*tab), map, count) == 0)
		return (ft_error(ft_freeloop((*tab)) + 1));
	if ((*count)[0] == 1 && (*count)[1] > 0 && (*count)[2] == 1)
	{
		while (ft_is_e((*tab), map) && map->num)
			ft_covid(tab, map);
		if (map->num == 0)
			return (ft_error(ft_freeloop((*tab)) + 3));
	}	
	else
	{
		ft_freeloop((*tab));
		return (ft_error(1));
	}
	return (1);
}
