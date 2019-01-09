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

void	fill_line(char *line, char *file, int *k, int weight)
{
	int j;

	j = 0;
	while (j < weight && file[(*k)])
	{
		if(ft_isdigit(file[(*k)]))
		{
			line[j] = (char)ft_atoi(&file[(*k)]);
			ft_printf("%3d", line[j]);
			j++;
		}
		while (ft_isdigit(file[(*k)]))
			(*k)++;
		while (!ft_isdigit(file[(*k)]))
			(*k)++;
	}
	line[j] = '\0';
}

void	fill_kart(t_mass *map, char *file)
{
	int i;
	int k;

	i = 0;
	k = 0;
	map->kart = (char**)malloc(sizeof(char*) * map->height + 1);
	while(i < map->height)
	{
		map->kart[i] = (char*)malloc(sizeof(char) * map->weight + 1);
		fill_line(map->kart[i], file, &k, map->weight);
		ft_printf("\n");
		i++;
	}
	map->kart[i] = 0;
}

void	read_map(t_mass *map, int av, char **ac)
{
	char *tmp;
	char *file;
	int fd = 0;

	tmp = NULL;
	file = NULL;
	if (av == 2)
		fd = open(ac[1], O_RDONLY);
	while (get_next_line(fd, &tmp))
	{
		map->height++;
		if (map->weight == 0)
			map->weight = (int)(ft_strlen(tmp) + 2) / 3;
		file = ft_strjoin(file, tmp);
		file = ft_strjoin(file, " ");
		ft_strdel(&tmp);
	}
	fill_kart(map, file);
}

