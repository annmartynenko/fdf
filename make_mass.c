/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_mass.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:47:47 by amartyne          #+#    #+#             */
/*   Updated: 2019/01/09 14:47:49 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <stdio.h>

void	draw(t_mass *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->weight - 1)
		{
			line(map, &map->coord[i][j], &map->coord[i][j + 1]);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < map->height - 1)
	{
		j = 0;
		while (j < map->weight)
		{
			line(map, &map->coord[i][j], &map->coord[i + 1][j]);
			j++;
		}
		i++;
	}
}

void	midpoint(t_mass *map, int mark)
{
	int i;
	int j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->weight)
		{
			if (mark == 1)
			{
				map->coord[i][j].x = map->coord[i][j].x - (map->weight * 40) / 2;
				map->coord[i][j].y = map->coord[i][j].y - (map->height * 40) / 2;
			}
			else if (mark == 2)
			{
				map->coord[i][j].x = map->coord[i][j].x + 1500 / 2;
				map->coord[i][j].y = map->coord[i][j].y + 1200 / 2;
			}
			j++;
		}
		i++;
	}
}

//void	make_mass(t_mass *map)
//{
//	int i;
//	int j;
//	double b;
//
//	i = 0;
//	j = 0;
//	b = 0;
//	while (i < map->height)
//	{
//		map->coord[i] = (t_xyz*)malloc(sizeof(t_xyz) * map->weight + 1);
//		map->coord[i][0].x = 0;
//		map->coord[i][0].y = 0 + b;
//		map->coord[i][0].z = (double)map->kart[i][j];
//		j = 1;
//		while (j < map->weight)
//		{
//			map->coord[i][j].x = map->coord[i][j - 1].x + 40;
//			map->coord[i][j].y = map->coord[i][j - 1].y;
//			map->coord[i][j].z = (double)map->kart[i][j] * 2;
//			j++;
//		}
//		b += 40;
//		i++;
//	}
//}