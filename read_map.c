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

void	clean(char *tmp, char **file)
{
	char *buf;

	buf = tmp;
	tmp = ft_strjoin(tmp, " ");
	free(buf);
	buf = *file;
	*file = ft_strjoin(*file, tmp);
	free(buf);
	ft_strdel(&tmp);
}

void	read_map(t_mass *map, int av, char **ac)
{
	char	*tmp;
	char	*file;
	int		fd;

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
				map->weight = (int)(ft_strlen(tmp) + 2) / 3;
		}
		clean(tmp, &file);
	}
	ft_strdel(&tmp);
	if (map->weight == 0 || map->height == 0)
		exit(0);
	fill_kart(map, file);
}
