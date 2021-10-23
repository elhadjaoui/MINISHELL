/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 18:45:34 by abenouda          #+#    #+#             */
/*   Updated: 2021/09/22 18:45:35 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

t_redirect	*new_redirection(int type, char *name)
{
	t_redirect	*p;

	p = (t_redirect *)malloc(sizeof(t_redirect));
	if (!p)
		return (NULL);
	p->name = name;
	p->type = type;
	return (p);
}

void	add_redirection_back(t_redirect **alst, t_redirect *new)
{
	t_redirect	*last;

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

int	redirection_list_size(t_redirect *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
