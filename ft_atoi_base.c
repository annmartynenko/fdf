/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 18:52:09 by amartyne          #+#    #+#             */
/*   Updated: 2019/01/10 18:52:11 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

int	ft_atoi_base(const char *str, int base)
{
	unsigned long int	a;
	int					i;
	int					b;

	i = 0;
	b = 1;
	a = 0;
	while ((str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
			str[i] == '\f' || str[i] == '\r' || str[i] == '\v') && str[i])
		i++;
	if (str[i] == '-')
		b = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (((str[i] >= '0' && str[i] <= '9')  || (str[i] >= 'a' && str[i] <= 'f') \
	|| (str[i] >= 'A' && str[i] <= 'F')) && str[i])
	{
		a = (a * base) + (str[i] - (str[i] <= 57 ? 48 : str[i] < 97 ? 55 : 87));
		i++;
	}
	return ((int)(a * b));
}