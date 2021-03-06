/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 12:43:46 by amartyne          #+#    #+#             */
/*   Updated: 2019/01/03 12:43:47 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "./libft/libft.h"
# include "mlx.h"
# include <math.h>

typedef struct	s_xyz
{
	double	x;
	double	y;
	double	z;
	int		color;
}				t_xyz;

typedef struct	s_mass
{
	int		height;
	int		weight;
	void	*wind;
	void	*mlx;
	t_xyz	**coord;
	double	angle[3];
	double	koef;
	double	center[2];
}				t_mass;

void			read_map(t_mass *map, int av, char **ac);
void			draw(t_mass *map);
void			iso(double *x, double *y, double z);
void			rotation_z(t_mass *map, int mark, double angle);
void			rotation_y(t_mass *map, int mark, double angle);
void			rotation_x(t_mass *map, int mark, double angle);
void			line(t_mass *fdf, t_xyz *d0, t_xyz *d1);
void			midpoint(t_mass *map, int mark);
void			do_iso(t_mass *map);
int				ft_atoi_base(const char *str, int base);
size_t			ft_strlen_chr(const char *s, int c);
void			change(t_mass *map);
void			move_xy(t_mass *map, int keycode);
void			move_z(t_mass *map, int keycode);
void			move(t_mass *map, int keycode);
void			zoom(t_mass *map, int keycode);
void			fill_kart(t_mass *map, char *file);

#endif
