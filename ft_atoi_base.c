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

int	ft_atoi_base(const char *s, int base)
{
	unsigned long int	a;
	int					i;
	int					b;
	char				c;

	i = 0;
	b = 1;
	a = 0;
	while (s[i] == ' ' || (s[i] > 8 && s[i] < 14))
		i++;
	if (s[i] == '-')
		b = -1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'f') \
	|| (s[i] >= 'A' && s[i] <= 'F')) && s[i])
	{
		if (s[i] <= 57)
			c = 48;
		else
			c = s[i] < 97 ? 55 : 87;
		a = (a * base) + (s[i] - c);
		i++;
	}
	return ((int)(a * b));
}
