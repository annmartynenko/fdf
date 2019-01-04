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

int main(int ac, char **av)
{
	t_mass map;

	map.kart = NULL;
	map.kart_ch = NULL;
	map.weight = 0;
	map.height = 0;
	map.mlx = mlx_init();
	map.wind = mlx_new_window(map.mlx, 900, 1000, "FDF");
	read_map(&map, ac, av);
	draw(&map);
	mlx_loop(map.mlx);
	return (0);
}