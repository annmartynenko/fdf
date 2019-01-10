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

int main(int ac, char **av)
{
	t_mass map;

	map.weight = 0;
	map.height = 0;
	map.mlx = mlx_init();
	map.wind = mlx_new_window(map.mlx, 1500, 1200, "FDF");
	map.coord = NULL;
	read_map(&map, ac, av);
	//make_mass(&map);
	do_iso(&map);
	printf("TEST 1");
	draw(&map);
	printf("TEST 2");
	mlx_hook(map.wind, 17, 0, exit_x, &map);
	mlx_loop(map.mlx);
	return (0);
}