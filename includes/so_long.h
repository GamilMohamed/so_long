/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:18:12 by mgamil            #+#    #+#             */
/*   Updated: 2022/11/23 20:36:54 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx/mlx.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../ft_printf/includes/ft_printf.h"

# define WALL '1'
# define GROUND '0'
# define COLLECT 'C'
# define POLICE 'R'
# define EXIT 'E'
# define PLAYER 'P'

# define W 119
# define A	97
# define S	115
# define D	100

# define UP 65362
# define LEFT 65361
# define DOWN 65364
# define RIGHT 65363

# define Q 113
# define ESC 65307

typedef struct s_map {
	int	x;
	int	y;
	int pospx;
	int pospy;
	int posex;
	int posey;
	int cond;
	int	num;
	char **tab;
	int c_count;
	int	count[3];
	int keycount;

}				t_map;

typedef struct s_data {
	void	*mlx;
	void	*win;
	void	*img[256];
	void	*roll[10];
	void	*portal[10];
	int		width;
	int		height;
	t_map	point;
}				t_data;


int		ft_freeloop(char **tab);
int		ft_checkline(char *s);
int		ft_checklenmap(int fd, t_map *map);
char	**ft_create_tab(int x, int y, int fd);
int		ft_isok(char c);
int		ft_checktab(char **tab, t_map *map, int (*count)[3]);
char	**ft_create_tab(int x, int y, int fd);
int		ft_checkmap(char *ber, t_map *map, int (*count)[3], char ***tab);
void	ft_virus_col_h(char ***tab, t_map *map, int y, int x);
void	ft_virus_col_b(char ***tab, t_map *map, int y, int x);
void	ft_virus_row_h(char ***tab, t_map *map, int y, int x);
void	ft_virus_row_b(char ***tab, t_map *map, int y, int x);
void	ft_covid(char ***tab, t_map *map);
int		ft_is_e(char **tab, t_map *map);
int		ft_checkber(char *ber);
int		ft_error(int err);

int		ft_game(t_map *map);

void	ft_fillmap(char ***tab, t_map *map, t_data *data);
void	ft_fillstats(t_map *map, t_data *data);

int		ft_toimage(t_data *data);
void 	ft_get_p(t_map *map);
int		ft_freemlx(t_data *data);
int		ft_freenret(void *p);
void 	ft_void(t_map *map, t_data *data);
void	ft_portal(t_data *data);
void	ft_putnbr_sprite(int nb, t_data *data, t_map *map);
void	ft_numbers(t_data *data);
int		ft_checkimg(t_data *data);
int		ft_close(t_data *data);





#endif

/*

w	119
a	97
s	115
d	100
esc	65307

*/