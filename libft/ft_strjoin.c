/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 21:00:39 by amartyne          #+#    #+#             */
/*   Updated: 2018/12/10 14:26:50 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*a;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	a = NULL;
	a = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!a)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		a[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
		a[i++] = s2[j++];
	a[i] = '\0';
	return (a);
}
