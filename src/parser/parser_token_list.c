/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_token_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <mel-hadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 13:03:34 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/09/24 10:21:18 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

t_command	*new_cmd(char **cmd, t_redirect *redirect)
{
	t_command	*p;

	p = (t_command *)malloc(sizeof(t_command));
	if (!p)
		return (NULL);
	p->cmd = cmd;
	p->redirect = redirect;
	p->in = 0;
	p->out = 1;
	return (p);
}

void	add_cmd_back(t_command **alst, t_command *new)
{
	t_command	*last;

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

int	cmd_list_size(t_command *lst)
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
