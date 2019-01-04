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

typedef struct	s_mass
{
	int		height;
	int		weight;
	char	**kart;
	char 	**kart_ch;
	void	*wind;
	void	*mlx;
}				t_mass;

typedef struct  s_d
{
	int dx;
	int dy;
	int d;
	int d1;
	int d2;
	int sx;
	int sy;
}				t_d;

typedef struct	s_t
{
	int x;
	int y;
	int z;
	int z0;
	int z1;
	int x1;
	int y1;
	int x0;
	int y0;
}				t_t;

void			read_map(t_mass *map, int av, char **ac);
void			draw(t_mass *map);
void			draw_line(t_mass *map, t_t *point, long color);
void			iso(int *x, int *y, int z);

#endif