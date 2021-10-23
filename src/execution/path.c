/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <mel-hadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 11:21:35 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/09/27 13:09:52 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

char	*grab_env(t_list *lenv, char *wanted)
{
	t_list	*tmp;
	char	*val;

	tmp = lenv;
	val = NULL;
	while (tmp)
	{
		if (!ft_strcmp(((t_env *)tmp->content)->name, wanted))
		{
			val = ((t_env *)tmp->content)->value;
			return (val);
		}
		tmp = tmp->next;
	}
	return (val);
}

char	**getpaths(char *path)
{
	char	**content;

	content = ft_split(path, ':');
	return (content);
}

char	*adapt_path(char **paths, char **args)
{
	char		*res;
	char		*leftover;
	struct stat	a;

	while (*paths)
	{
		leftover = ft_strjoin(*paths++, "/");
		res = ft_strjoin(leftover, args[0]);
		free(leftover);
		if (stat(res, &a) != -1)
			return (res);
	}
	return (NULL);
}

void	free_split(char **p)
{
	int	i;

	i = 0;
	while (p[i])
	{
		free(p[i]);
		i++;
	}
	free(p);
}
