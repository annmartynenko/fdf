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

void	read_map(t_mass *map, int av, char **ac)
{
	char *tmp;
	char *file;
	//int i = 0;
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
		ft_strdel(&tmp);
	}
	map->kart_ch = ft_strsplit(file, ' ');
//	while(map->kart_ch[i])
//	{
//		ft_printf("%s ", map->kart_ch[i]);
//		ft_printf("\n");
//		i++;
//	}
//	ft_printf("\n %d , %d", map->height, map->weight);
}

