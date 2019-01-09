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
