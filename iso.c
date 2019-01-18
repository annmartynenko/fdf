/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 17:23:56 by amartyne          #+#    #+#             */
/*   Updated: 2019/01/04 17:23:58 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void	small_big(t_mass *map, int mark)
{
	int i;
	int j;

	midpoint(map, mark);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->weight)
		{
			map->coord[i][j].x *= map->koef;
			map->coord[i][j].y *= map->koef;
			map->coord[i][j].z *= map->koef;
			j++;
		}
		i++;
	}
	midpoint(map, 2);
}

void	zoom(t_mass *map, int keycode)
{
	if (keycode == 69)
	{
		map->koef = 1.1;
		small_big(map, 3);
		mlx_clear_window(map->mlx, map->wind);
		draw(map);
	}
	else if (keycode == 78)
	{
		map->koef = 0.9;
		small_big(map, 3);
		mlx_clear_window(map->mlx, map->wind);
		draw(map);
	}
}
