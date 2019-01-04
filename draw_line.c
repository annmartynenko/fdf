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

void	condition1(t_mass *map, t_t *point, t_d *d, long color)
{
	d->d = (d->dy << 1) - d->dx;
	d->d1 = d->dy << 1;
	d->d2 = (d->dy - d->dx) << 1;
	mlx_pixel_put(map->mlx, map->wind, point->x0, point->y0, color);
	point->x = point->x0 + 1;
	point->y = point->y0;
	while (point->x <= point->x1)
	{
		if (d->d > 0)
		{
			d->d += d->d2;
			point->y += 1;
		}
		else
			d->d += d->d1;
		mlx_pixel_put(map->mlx, map->wind, point->x, point->y, color);
		point->x++;
	}
}

void	condition2(t_mass *map, t_t *point, t_d *d, long color)
{
	int i;

	i = 1;
	d->d = (d->dx << 1) - d->dy;
	d->d1 = d->dx << 1;
	d->d2 = (d->dx - d->dy) << 1;
	mlx_pixel_put(map->mlx, map->wind, point->x0, point->y0, color);
	point->x = point->x0;
	point->y = point->y0 + d->sy;
	while (i <= d->dy)
	{
		if (d->d > 0)
		{
			d->d += d->d2;
			point->x += d->sx;
		}
		else
			d->d += d->d1;
		mlx_pixel_put(map->mlx, map->wind, point->x, point->y, color);
		i++;
		point->y += d->sy;
	}
}

void	draw_line(t_mass *map, t_t *point, long color)
{
	t_d d;

	d.dx = abs(point->x1 - point->x0);
	d.dy = abs(point->y1 - point->y0);
	d.sx = point->x1 >= point->x0 ? 1 : -1;
	d.sy = point->y1 >= point->y0 ? 1 : -1;
	if (d.dy <= d.dx)
		condition1(map, point, &d, color);
	else
		condition2(map, point, &d, color);
}

void	draw(t_mass *map)
{
	t_t point;
	int i;
	int j;
	int k;
	int a;
	int b;

	i = 0;
	j = 0;
	k = 0;
	point.x0 = 60;
	point.y0 = 60;
	point.x1 = 100;
	point.y1 = 60;
	while (i < map->height)
	{
		point.x0 = 60;
		point.x1 = 100;
		point.y0 += 40;
		point.y1 += 40;
		j = 0;
		while (j < map->weight - 1)
		{
			if (map->kart_ch[k][1] == 0)
			{
				draw_line(map, &point, 0xf2f181);
			}
			else
			{
				a = point.y1;
				b = point.y0;
				point.y1 /= 3;
				point.y0 /= 3;
				draw_line(map, &point, 0xfefdfa);
				point.y1 = a;
				point.y0 = b;
			}
			point.x0 += 40;
			point.x1 += 40;
			k++;
			j++;
		}
		i++;
	}
	point.x0 = 60;
	point.y0 = 60;
	point.x1 = 60;
	point.y1 = 100;
	i = 0;
	j = 0;
	k = 0;
	while (i < map->height)
	{
		point.x0 = 60;
		point.x1 = 60;
		point.y0 += 40;
		point.y1 += 40;
		j = 0;
		while (j < map->weight - 1)
		{
			if (map->kart_ch[k][1] == 0)
			{
				draw_line(map, &point, 0xf2f181);
			}
			else
			{
				a = point.y1;
				point.y1 /= 3;
				draw_line(map, &point, 0xdd91d1);
				point.y1 = a;
			}
			point.x0 += 40;
			point.x1 += 40;
			k++;
			j++;
		}
		i++;
	}
}