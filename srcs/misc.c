/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 22:02:09 by mgamil            #+#    #+#             */
/*   Updated: 2022/11/23 19:35:34 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_freeloop(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i] != NULL)
		free(tab[i]);
	free(tab);
	return (0);
}

int	ft_isok(char c)
{
	if (c != WALL && c != GROUND && c != PLAYER && c != POLICE
		&& c != COLLECT && c != EXIT && c != '\0')
	{
		ft_printf("c=%c\n", c);
		return (1);
	}
	return (0);
}

int	ft_is_e(char **tab, t_map *map)
{
	int	i;

	i = -1;
	while (++i < (map->x * map->y))
		if ((tab[i / map->x][i % map->x] == EXIT)
			|| (tab[i / map->x][i % map->x] == COLLECT))
			return (1);
	return (0);
}

int	ft_checkber(char *ber)
{
	char	*s;

	s = ft_strnstr(ber, ".ber", ft_strlen(ber));
	if (!s || ft_strlen(s) != 4)
		return (1);
	return (0);
}

int	ft_error(int err)
{
	if (err == 1)
		ft_printf("%rError 1 ->%0 Map invalide\n");
	else if (err == 2)
		ft_printf("%rError 2 ->%0 Malloc du tableau incorrect\n");
	else if (err == 3)
		ft_printf("%rError 3 ->%0 Impossible d'atteindre l'exit ou collect\n");
	else if (err == 4)
		ft_printf("%rError 4 ->%0 chelou\n");
	else if (err == 5)
		ft_printf("%yError 5 ->%g ./so_long maps%0\n");
	else if (err == 6)
		ft_printf("%mError 6 ->%0 mlx failed\n");
	return (0);
}
