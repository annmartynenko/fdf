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

	ft_printf("START DRAW");
	make_mass(map);
	point.x0 = 0;
	point.y0 = 0;
	point.x1 = 0;
	point.y1 = 0;
	point.x = 0;
	point.y = 0;
	i = 0;
	j = 0;
	while (i < map->height - 1)
	{
		j = 0;
		point.x0 = map->x0[i][j];
		point.y0 = map->y0[i][j];
		point.x1 = map->x0[i][j + 1];
		point.y1 = map->y0[i][j + 1];
		while (j < map->weight - 1)
		{
			if ((i == 1 && j == 1) || (i == 1 && j == 2))
			{
				ft_printf("x0 %d x1 %d ", point.x0, point.x1);
				ft_printf("y0 %d y1 %d ", point.y0, point.y1);
			}
			draw_line(map, &point, 0x4cb55d);
			j++;
			point.x0 = map->x0[i][j];
			point.y0 = map->y0[i][j];
			point.x1 = map->x0[i][j + 1];
			point.y1 = map->y0[i][j + 1];
		}
		//ft_printf("\n");
		i++;
	}
	i = 0;
	j = 0;
	while (i < map->height - 1)
	{
		j = 0;
		point.x0 = map->x0[i][j];
		point.y0 = map->y0[i][j];
		point.x1 = map->x0[i + 1][j];
		point.y1 = map->y0[i + 1][j];
		while (j < map->weight - 1)
		{
			draw_line(map, &point, 0xee6d7f);
			j++;
			point.x0 = map->x0[i][j];
			point.y0 = map->y0[i][j];
			point.x1 = map->x0[i + 1][j];
			point.y1 = map->y0[i + 1][j];
//			if (i == 1 && j == 1)
//			{
//				ft_printf("x0 %d x1 %d ", point.x0, point.x1);
//				ft_printf("y0 %d y1 %d ", point.y0, point.y1);
//			}
		}
//		ft_printf("\n");
//		ft_printf("\n");
		i++;
	}
}

void	make_mass(t_mass *map)
{
	int i;
	int j;
	int a;
	int b;

	i = 0;
	j = 0;
	a = 20;
	b = 20;
	ft_printf("START\n");
	map->x0 = (int**)malloc(sizeof(int*) * map->height + 1);
	map->y0 = (int**)malloc(sizeof(int*) * map->height + 1);
	while (i < map->height)
	{
		j = 1;
		map->x0[i] = (int*)malloc(sizeof(int) * map->weight + 1);
		map->y0[i] = (int*)malloc(sizeof(int) * map->weight + 1);
		map->x0[i][0] = 720 + a;
		map->y0[i][0] = 100 + b;
		while (j < map->weight)
		{
//			if (map->kart[i][j] > 0)
//			{
//				map->x0[i][j] = map->x0[i][j - 1] - 40;
//				map->y0[i][j] = map->y0[i][0] - map->kart[i][j];
//			}
//			else
//			{
				map->x0[i][j] = map->x0[i][j - 1] - 40;
				map->y0[i][j] = map->y0[i][j - 1] + 5;
//			}
			//ft_printf("x %d ", map->x0[i][j]);
			//ft_printf("y %d ", map->y0[i][j]);
			j++;
		}
		a = a + 20;
		b = b + 20;
		//ft_printf("\n");
		i++;
	}
}