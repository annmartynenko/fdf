/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_kart.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 21:26:37 by amartyne          #+#    #+#             */
/*   Updated: 2019/01/13 21:26:41 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	color(int *color, char *file, int *k)
{
	if (file[(*k)] == ',')
	{
		(*k)++;
		*color = ft_atoi_base(&file[(*k) + 2], 16);
		while (file[*k] && (ft_isdigit(file[(*k)]) || ft_isalpha(file[(*k)])))
			(*k)++;
		while (file[*k] && file[(*k)] == ' ')
			(*k)++;
	}
	else
		*color = 0x83c484;
}

void	fill_line(t_mass *map, char *file, int *k, int i)
{
	int j;

	j = 1;
	while (file[*k] && j < map->weight)
	{
		if (ft_isdigit(file[(*k)]))
		{
			map->coord[i][j].x = map->coord[i][j - 1].x + 40;
			map->coord[i][j].y = map->coord[i][j - 1].y;
			map->coord[i][j].z = (double)ft_atoi(&file[(*k)]) * 10;
			while (file[*k] && ft_isdigit(file[(*k)]))
				(*k)++;
		}
		while (file[*k] && file[(*k)] == ' ')
			(*k)++;
		color(&map->coord[i][j].color, file, k);
		j++;
	}
}

void	in_kart(t_mass *map, int i, char *file, int k)
{
	static int b = 0;

	map->coord[i] = (t_xyz*)malloc(sizeof(t_xyz) * (map->weight));
	if (map->coord[i])
	{
		map->coord[i][0].x = 0;
		map->coord[i][0].y = b;
		map->coord[i][0].z = (double)ft_atoi(&file[k]) * 10;
		map->coord[i][0].color = 0;
	}
	b += 40;
}

void	fill_kart(t_mass *map, char *file)
{
	int i;
	int k;

	i = 0;
	k = 0;
	map->coord = (t_xyz**)malloc(sizeof(t_xyz*) * (map->height + 1));
	while (i < map->height)
	{
		while (file[k] && file[k] == ' ')
			k++;
		in_kart(map, i, file, k);
		while (file[k] && ft_isdigit(file[k]))
			k++;
		color(&map->coord[i][0].color, file, &k);
		while (file[k] && file[k] == ' ')
			k++;
		fill_line(map, file, &k, i);
		while (file[k] && (file[k] == ' ' || ft_isalpha(file[(k)])))
			k++;
		i++;
	}
	map->coord[i] = 0;
	ft_strdel(&file);
}
