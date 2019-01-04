/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 16:56:47 by amartyne          #+#    #+#             */
/*   Updated: 2018/04/02 16:04:14 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_atoi(const char *str)
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
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
	{
		if ((a > 922337203685477580 || (a == 922337203685477580 && \
(str[i] - '0') > 7)) && b == 1)
			return (-1);
		else if ((a > 922337203685477580 || (a == 922337203685477580 && \
(str[i] - '0') > 7)) && b == -1)
			return (0);
		a = a * 10 + str[i++] - '0';
	}
	return ((int)(a * b));
}