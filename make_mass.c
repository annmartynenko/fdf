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
	t_xyz **coord;

	coord = make_mass(map);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->weight - 1)
		{
			line(map, &coord[i][j], &coord[i][j + 1]);
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
			line(map, &coord[i][j], &coord[i + 1][j]);
			j++;
		}
		i++;
	}
}

t_xyz	**make_mass(t_mass *map)
{
	int i;
	int j;
	double b;
	t_xyz **coord;

	i = 0;
	j = 0;
	b = 20;
	coord = (t_xyz**)malloc(sizeof(t_xyz*) * map->height + 1);
	while (i < map->height)
	{
		coord[i] = (t_xyz*)malloc(sizeof(t_xyz) * map->weight + 1);
		coord[i][0].x = 400 - (map->weight * 40) / 2 + 1500 / 2;
		coord[i][0].y = 20 + b - (map->height * 40) / 2 + 1200 / 2;
		coord[i][0].z = (double)map->kart[i][j];
		j = 1;
		while (j < map->weight)
		{
			coord[i][j].x = coord[i][j - 1].x + 40;
			coord[i][j].y = coord[i][j - 1].y;
			coord[i][j].z = (double)map->kart[i][j] * 2;
			j++;
		}
		b += 40;
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->weight)
		{
			iso(&coord[i][j].x, &coord[i][j].y, coord[i][j].z);
			j++;
		}
		i++;
	}
	return (coord);
}