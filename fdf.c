/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 12:34:34 by amartyne          #+#    #+#             */
/*   Updated: 2019/01/03 12:34:35 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <stdio.h>

int	exit_x(t_mass *map)
{
	(void)map;
	exit(1);
	return (0);
}

int	key_press(int keycode, void *param)
{
	if (keycode == 53)
		exit(1);
	else if (keycode == 125 || keycode == 126)
		move_xy(param, keycode);
	else if (keycode == 123 || keycode == 124)
		move_xy(param, keycode);
	else if (keycode == 115 || keycode == 119)
		move_z(param, keycode);
	else if (keycode == 1 || keycode == 13)
		move(param, keycode);
	else if (keycode == 0 || keycode == 2)
		move(param, keycode);
	else if (keycode == 69 || keycode == 78)
		zoom(param, keycode);
	return (0);
}

int	main(int ac, char **av)
{
	t_mass map;

	map.angle[0] = -1;
	map.angle[1] = -0.5;
	map.angle[2] = 0;
	map.center[0] = 0;
	map.center[1] = 0;
	map.koef = 1.1;
	map.weight = 0;
	map.height = 0;
	map.mlx = mlx_init();
	map.wind = mlx_new_window(map.mlx, 1500, 1200, "FDF");
	map.coord = NULL;
	read_map(&map, ac, av);
	rotation_x(&map, 1, map.angle[0]);
	rotation_y(&map, 3, map.angle[1]);
	rotation_z(&map, 3, map.angle[2]);
	draw(&map);
	mlx_hook(map.wind, 2, 0, key_press, &map);
	mlx_hook(map.wind, 17, 0, exit_x, &map);
	mlx_loop(map.mlx);
	return (0);
}
