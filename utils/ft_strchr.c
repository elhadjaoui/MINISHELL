/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 18:50:42 by abenouda          #+#    #+#             */
/*   Updated: 2021/10/01 15:04:53 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	j;

	j = 0;
	while (s[j])
		j++;
	i = 0;
	while (i <= j)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		else
			i++;
	}
	return (NULL);
}
