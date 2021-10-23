/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 13:36:33 by abenouda          #+#    #+#             */
/*   Updated: 2021/09/21 16:34:48 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

char	*get_name(char *env)
{
	char	*s;
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (env[++i] != '=')
		j++;
	s = malloc(j + 1);
	i = -1;
	while (env[++i] != '=')
		s[i] = env[i];
	s[j] = '\0';
	return (s);
}

void	list_env(t_all *all, char **env)
{
	int		i;
	t_env	*v;

	i = -1;
	while (env[++i] != NULL)
	{
		v = (t_env *)malloc(sizeof(t_env));
		v->name = get_name(env[i]);
		v->value = ft_strdup(ft_strchr(env[i], '=') + 1);
		ft_lstadd_back(&all->l_env, ft_lstnew(v));
	}
}

char	**env_form(t_list *list)
{
	t_list	*lst;
	char	**env;
	char	*s;
	int		i;

	lst = list;
	i = ft_lstsize(lst);
	env = (char **)malloc((i + 1) * sizeof(char *));
	env[i] = NULL;
	i = 0;
	while (lst)
	{
		s = ft_strjoinchar(((t_env *)lst->content)->name, '=');
		env[i++] = ft_strjoin(s, ((t_env *)lst->content)->value);
		free(s);
		lst = lst->next;
	}
	return (env);
}
