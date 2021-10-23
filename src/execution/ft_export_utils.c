/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:46:33 by abenouda          #+#    #+#             */
/*   Updated: 2021/09/29 18:46:28 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	export_parse(t_list *lenv, char *s)
{
	int		i;
	t_env	*env;

	i = 0;
	if (s[i] == 96 || (s[i] > 'Z' && s[i] < '_') || s[i] < 'A' || s[i] > 'z')
	{
		printf("export: `%s': not a valid identifier\n", s);
		return ;
	}
	while (s[i] && s[i] != '=')
		i++;
	env = (t_env *)malloc(sizeof(t_env));
	if (s[i])
	{
		env->name = ft_strndup(s, i);
		env->value = ft_strdup(s + i + 1);
	}
	else
	{
		env->name = ft_strdup(s);
		env->value = NULL;
	}
	ft_export_wa(lenv, env);
}

void	print_export(t_list *list, int fd)
{
	t_list	*l;

	l = list;
	while (l)
	{
		ft_putstr_fd("declare -x ", fd);
		ft_putstr_fd(((t_env *)l->content)->name, fd);
		if (((t_env *)l->content)->value)
		{
			ft_putstr_fd("=\"", fd);
			ft_putstr_fd(((t_env *)l->content)->value, fd);
			ft_putstr_fd("\"", fd);
		}
		ft_putstr_fd("\n", fd);
		l = l->next;
	}
}
