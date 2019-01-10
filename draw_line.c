/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 17:05:11 by amartyne          #+#    #+#             */
/*   Updated: 2019/01/03 17:05:12 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void	line(t_mass *fdf, t_xyz *d0, t_xyz *d1)
{
	int	xy[2];

	xy[0] = (int)d0->x;
	xy[1] = (int)d0->y;
	if (fabs(d1->y - d0->y) > fabs(d1->x - d0->x))
		while (d0->y > d1->y ? xy[1] >= d1->y : xy[1] <= d1->y)
		{
			xy[0] = (int)((xy[1] - d0->y) / (d0->y - d1->y) * (d0->x - d1->x) + d0->x);
			mlx_pixel_put(fdf->mlx, fdf->wind, xy[0], xy[1], d0->color);
			d1->y > d0->y ? xy[1]++ : xy[1]--;
		}
	else
		while (d0->x > d1->x ? xy[0] >= d1->x : xy[0] <= d1->x)
		{
			xy[1] = (int)((xy[0] - d0->x) / (d0->x - d1->x) * (d0->y - d1->y) + d0->y);
			mlx_pixel_put(fdf->mlx, fdf->wind, xy[0], xy[1], d0->color);
			d1->x > d0->x ? xy[0]++ : xy[0]--;
		}
}
