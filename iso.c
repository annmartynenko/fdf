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

void	iso(double *x, double *y, double z)
{
	double pr_x;
	double pr_y;

	pr_x = *x;
	pr_y = *y;
	*x = (pr_x - pr_y) * cos(0.523599);
	*y = -z + (pr_x + pr_y) * sin(0.523599);
}

void	do_iso(t_mass *map)
{
	int i;
	int j;

	midpoint(map, 1);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->weight)
		{
			iso(&map->coord[i][j].x, &map->coord[i][j].y, map->coord[i][j].z);
			j++;
		}
		i++;
	}
	midpoint(map, 2);
}
