/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:18:12 by mgamil            #+#    #+#             */
/*   Updated: 2022/11/20 16:43:12 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../ft_printf/includes/ft_printf.h"
# define WALL '1'
# define GROUND '0'
# define COLLECT 'C'
# define POLICE 'R'
# define EXIT 'E'
# define PLAYER 'P'



typedef struct	s_data {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_map {
	int	x;
	int	y;
	int test;
}				t_map;

// int	ft_VIRUS(char ***tab, size_t y, size_t x, t_map *map);
void ft_COVID(char ***tab, t_map *map);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif