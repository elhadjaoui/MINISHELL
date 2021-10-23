/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <mel-hadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 14:20:39 by abenouda          #+#    #+#             */
/*   Updated: 2021/09/25 10:52:33 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

t_token	*toknew(char *name, int num)
{
	t_token	*p;

	p = (t_token *)malloc(sizeof(t_token));
	if (!p)
		return (NULL);
	p->name = name;
	p->num = num;
	return (p);
}

void	tokadd_back(t_token **alst, t_token *new)
{
	t_token	*last;

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

void	tokadd_front(t_token **alst, t_token *new)
{
	if (alst && new)
	{
		new->next = *alst;
		*alst = new;
	}
}

int	toksize(t_token *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
