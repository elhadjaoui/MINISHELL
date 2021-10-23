/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:39:09 by abenouda          #+#    #+#             */
/*   Updated: 2021/09/21 15:40:18 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

t_list	*search_lst_unset(t_list *list, char *var, t_list **before)
{
	t_list	*f;
	int		i;

	f = NULL;
	i = 0;
	while (list)
	{
		if (ft_strcmp(((t_env *)list->content)->name, var) == 0)
		{
			f = list;
			break ;
		}
		if (i)
			*before = list;
		i = 1;
		list = list->next;
	}
	return (f);
}

void	ft_unset(t_all *all, char *var)
{
	t_list	*list;
	t_list	*f;
	t_list	*before;

	before = NULL;
	list = all->l_env;
	f = search_lst_unset(list, var, &before);
	if (f)
	{
		if (before)
			before->next = f->next;
		else
		{
			list = list->next;
			all->l_env = list;
		}
		free(f->content);
		free(f);
	}
}

void	ft_unset_loop(t_all *all, t_command *cmd)
{
	int	i;

	if (cmd->cmd[1])
	{
		i = 0;
		while (cmd->cmd[++i])
			ft_unset(all, cmd->cmd[i]);
	}
}
