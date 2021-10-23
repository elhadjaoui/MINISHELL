/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <mel-hadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 11:14:28 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/09/22 13:26:48 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	double_char_to_list(t_list **list, char **str)
{
	int	i;
	int	len;

	len = 0;
	while (str[len])
		len++;
	i = -1;
	while (++i < len)
	{
		if (!*list)
			*list = ft_lstnew(str[i]);
		else
			ft_lstadd_back(list, ft_lstnew(str[i]));
	}
}

void	next_node(t_dlist **list)
{
	if (!*list)
		return ;
	if ((*list)->next != NULL)
		(*list) = (*list)->next;
}

void	prev_node(t_dlist **list)
{
	if (!*list)
		return ;
	if ((*list)->prev != NULL)
		(*list) = (*list)->prev;
}

void	lstadd_dlist(t_dlist **alst, t_dlist *new)
{
	t_dlist	*last;

	if (!new)
		return ;
	last = *alst;
	new->prev = NULL;
	if ((*alst) == NULL)
		(*alst) = new;
	else
	{
		new->next = *alst;
		(*alst)->prev = new;
		*alst = new;
	}
}

t_dlist	*lstnewc(void *node)
{
	t_dlist	*p;

	p = (t_dlist *)malloc(sizeof(t_dlist));
	if (!p)
		return (NULL);
	p->node = node;
	p->next = NULL;
	p->prev = NULL;
	return (p);
}
