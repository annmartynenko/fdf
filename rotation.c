/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 16:21:04 by amartyne          #+#    #+#             */
/*   Updated: 2019/01/09 16:21:06 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void	rotation_x(double *x, double *y, double z)
{
	double pr_x;
	double pr_y;

	pr_x = *x;
	pr_y = *y;
	*x = pr_x;
	*y = pr_y * cos(0.523599) + z * sin(0.523599);
	z = -pr_y * sin(0.523599) + z * cos(0.523599);
}

void	rotation_y(double *x, double *y, double z)
{
	double pr_x;
	double pr_y;

	pr_x = *x;
	pr_y = *y;
	*x = pr_x * cos(0.523599) + z * sin(0.523599);
	*y = pr_y;
	z = -pr_x * sin(0.523599) + z * cos(0.523599);
}

void	rotation_z(double *x, double *y, double z)
{
	double pr_x;
	double pr_y;

	pr_x = *x;
	pr_y = *y;
	*x = pr_x * cos(0.523599) - pr_y * sin(0.523599);
	*y = pr_x * sin(0.523599) + pr_y * cos(0.523599);
	z = z + 0;
}