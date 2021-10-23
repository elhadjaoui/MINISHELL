/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:46:09 by abenouda          #+#    #+#             */
/*   Updated: 2021/09/29 17:04:25 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	alpha_sort(t_list *list)
{
	t_list	*b;
	void	*tmp;

	b = NULL;
	while (list != NULL)
	{
		b = list->next;
		while (b != NULL)
		{
			if (ft_strcmp(((t_env *)list->content)->name,
					((t_env *)b->content)->name) > 0)
			{
				tmp = list->content;
				list->content = b->content;
				b->content = tmp;
			}
			b = b->next;
		}
		list = list->next;
	}
}

void	ft_export_na(t_list *env, int fd)
{
	t_list	*list;

	list = env;
	alpha_sort(list);
	print_export(list, fd);
}

void	ft_export_wa(t_list *env, t_env *var)
{
	t_list	*list;
	t_list	*exist;

	list = env;
	exist = search_lst(list, var->name);
	if (exist && var->value)
		exist->content = var;
	else if (!exist)
		ft_lstadd_back(&env, ft_lstnew(var));
}

void	ft_export(t_list *env, t_command *cmd)
{
	int	i;

	if (cmd->cmd[1])
	{
		i = 0;
		while (cmd->cmd[++i])
			export_parse(env, cmd->cmd[i]);
	}
	else
	{
		if (!check_redir(cmd, env) && cmd->cmd[0])
			ft_export_na(env, cmd->out);
	}
}
