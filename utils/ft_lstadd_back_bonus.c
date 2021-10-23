/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 02:31:38 by abenouda          #+#    #+#             */
/*   Updated: 2021/10/01 14:54:56 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last;

	if (!new)
		return ;
	last = *alst;
	new->next = NULL;
	if ((*alst) == NULL)
		(*alst) = new;
	else
	{
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}
}
