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
			else if (mark == 3)
			{
				map->coord[i][j].x = map->coord[i][j].x - 1500 / 2;
				map->coord[i][j].y = map->coord[i][j].y - 1200 / 2;
			}
			j++;
		}
		i++;
	}
}

void	up_down(t_mass *map, int mark, int plus)
{
	double pr_y;
	int i;
	int j;

	midpoint(map, mark);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->weight)
		{
			pr_y = map->coord[i][j].y;
			map->coord[i][j].y = pr_y + plus;
			j++;
		}
		i++;
	}
	midpoint(map, 2);
}

void	left_right(t_mass *map, int mark, int plus)
{
	double pr_x;
	int i;
	int j;

	midpoint(map, mark);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->weight)
		{
			pr_x = map->coord[i][j].x;
			map->coord[i][j].x = pr_x + plus;
			j++;
		}
		i++;
	}
	midpoint(map, 2);
}

//void	move(t_mass *map, int keycode)
//{
//	if (keycode == 1)
//	{
//		up_down(map, 3, 10);
//		mlx_clear_window(map->mlx, map->wind);
//		draw(map);
//	}
//	else if (keycode == 13)
//	{
//		up_down(map, 3, -10);
//		mlx_clear_window(map->mlx, map->wind);
//		draw(map);
//	}
//	if (keycode == 0)
//	{
//		left_right(map, 3, -10);
//		mlx_clear_window(map->mlx, map->wind);
//		draw(map);
//	}
//	else if (keycode == 2)
//	{
//		left_right(map, 3, 10);
//		mlx_clear_window(map->mlx, map->wind);
//		draw(map);
//	}
//}