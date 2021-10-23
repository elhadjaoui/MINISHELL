/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_fncts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:22:51 by abenouda          #+#    #+#             */
/*   Updated: 2021/09/20 15:22:53 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

char	*home_path(t_all *all)
{
	char	*ret;

	ret = grab_env(all->l_env, "HOME");
	if (!ret)
		ret = getenv("HOME");
	return (ret);
}

t_list	*search_lst(t_list *list, char *var)
{
	t_list	*search;
	t_list	*f;

	search = list;
	f = NULL;
	while (search)
	{
		if (ft_strcmp(((t_env *)search->content)->name, var) == 0)
		{
			f = search;
			break ;
		}
		search = search->next;
	}
	return (f);
}

void	set_oldpwd(t_all *all)
{
	t_list	*f;

	f = search_lst(all->l_env, "OLDPWD");
	if (f)
	{
		free(((t_env *)f->content)->value);
		((t_env *)f->content)->value = getcwd(NULL, 0);
	}
}

void	set_pwd(t_all *all)
{
	t_list	*f;

	f = search_lst(all->l_env, "PWD");
	if (f)
	{
		free(((t_env *)f->content)->value);
		if (getcwd(NULL, 0))
			((t_env *)f->content)->value = getcwd(NULL, 0);
	}
}
