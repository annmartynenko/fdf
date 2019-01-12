/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 13:16:14 by amartyne          #+#    #+#             */
/*   Updated: 2019/01/03 13:16:16 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	fill_line(t_mass *map, char *file, int *k, int i)
{
	int j;

	j = 1;
	while (file[(*k)] != '\n')
	{
		if(ft_isdigit(file[(*k)]))
		{
			map->coord[i][j].x = map->coord[i][j - 1].x + 40;
			printf("j : %d \n", j);
			map->coord[i][j].y = map->coord[i][j - 1].y;
			map->coord[i][j].z = ft_atoi(&file[(*k)]);
			printf("y0 %f \n", map->coord[i][0].y);
			printf("y1 %f \n", map->coord[i][j - 1].y);

			if (j == 100 && i == 1)
				exit(0);
//			printf("x %f y %f ", map->coord[i][j].x, map->coord[i][j].y);
//			printf("z %f\n", map->coord[i][j].z);
//			printf("%f ", map->coord[i][j].z);
			while (ft_isdigit(file[(*k)]))
				(*k)++;
		}
		if (file[(*k)] == ' ')
			while (file[(*k)] == ' ')
				(*k)++;
		if (file[(*k)] == ',')
		{
			(*k)++;
			map->coord[i][j].color = ft_atoi_base(&file[(*k) + 2], 16);
//			printf("color %x \n", map->coord[i][j].color);
			j++;
			while (ft_isdigit(file[(*k)]) || ft_isalpha(file[(*k)]))
				(*k)++;
			if (file[(*k)] == ' ')
				while (file[(*k)] == ' ')
					(*k)++;
		}
		else
		{
			map->coord[i][j].color = 0x83c484;
//			printf("color %x \n", map->coord[i][j].color);
			j++;
		}

	}
	//printf("j:%d  \n", j);
	//map->coord[i][j] = 0;
}

void	fill_kart(t_mass *map, char *file)
{
	int i;
	int k;
	int b;

	i = 0;
	k = 0;
	b = 0;
	map->coord = (t_xyz**)ft_memalloc(sizeof(t_xyz*) * (map->height + 1));
	while(i < map->height)
	{
		//printf("KART %d\n", i);
		map->coord[i] = (t_xyz*)ft_memalloc(sizeof(t_xyz) * (map->weight + 1));
		map->coord[i][0].x = 0;
		map->coord[i][0].y = 0 + b;
//		printf("y %f \n", map->coord[i][0].y);
		map->coord[i][0].z = (double)ft_atoi(&file[k]);
		while (ft_isdigit(file[k]) || ft_isalpha(file[(k)]))
			k++;
		if (file[(k)] == ' ' || file[(k)] == '\n')
			while (file[k] == ' ' || file[k] == '\n')
				k++;
		fill_line(map, file, &k, i);
		if (file[k] && (file[(k)] == ' ' || file[(k)] == '\n' || ft_isalpha(file[(k)])))
			while (file[k] == ' ' || file[k] == '\n' || ft_isalpha(file[(k)]))
				k++;
		b += 40;
		i++;
	}
	printf("CHECK\n");
	map->coord[i] = 0;
//	printf("CHECK2\n");
}

void	read_map(t_mass *map, int av, char **ac)
{
	char *tmp;
	char *file;
	int fd;

	tmp = NULL;
	file = NULL;
	fd = 0;
	if (av == 2)
		fd = open(ac[1], O_RDONLY);
	while (get_next_line(fd, &tmp) > 0)
	{
		map->height++;
		if (map->weight == 0)
		{
			if (ft_strchr(tmp, ','))
				map->weight = (int)ft_strlen_chr(tmp, ',');
			else
				map->weight = (int) (ft_strlen(tmp) + 2) / 3;
		}

		tmp = ft_strjoin(tmp, "\n");
		file = ft_strjoin(file, tmp);
		ft_strdel(&tmp);
	}
	printf("height %d weight %d\n", map->height, map->weight);
	fill_kart(map, file);
	printf("CHECK3\n");
}

