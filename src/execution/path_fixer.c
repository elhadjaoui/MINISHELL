/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_fixer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:42:59 by abenouda          #+#    #+#             */
/*   Updated: 2021/10/04 15:13:45 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	no_such_file(char *arg)
{
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
	exit (127);
}

char	*executable(char **args, struct stat *a)
{
	if (stat(args[0], a) == 0)
	{
		if (S_IFDIR == (a->st_mode & S_IFMT))
		{
			ft_putstr_fd(args[0], 2);
			ft_putstr_fd(": is a directory\n", 2);
			exit (126);
		}
		if (S_IFREG == (a->st_mode & S_IFMT))
		{
			if (a->st_mode & S_IXUSR)
				return (args[0]);
			else
			{
				ft_putstr_fd(args[0], 2);
				ft_putstr_fd(": Permission denied\n", 2);
				exit (126);
			}
		}
	}
	else
		no_such_file(args[0]);
	return (NULL);
}

char	*slash(struct stat *a, char **args)
{
	if (stat(args[0], a) == 0)
	{
		if (S_IFDIR == (a->st_mode & S_IFMT))
		{
			ft_putstr_fd(args[0], 2);
			ft_putstr_fd(": is a directory\n", 2);
			exit (126);
		}
		if (S_IFREG == (a->st_mode & S_IFMT))
			return (args[0]);
	}
	else
	{
		ft_putstr_fd(args[0], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		exit (127);
	}
	return (NULL);
}

char	*fix_path(t_list *env, char **args)
{
	char		*PATH;
	char		**p;
	char		*res;
	struct stat	a;

	PATH = NULL;
	res = NULL;
	if (args[0][0] == '.' && args[0][1] == '/')
		return (executable(args, &a));
	else if (args[0][0] == '/')
		return (slash(&a, args));
	else
	{
		PATH = grab_env(env, "PATH");
		if (PATH)
		{
			p = getpaths(PATH);
			res = adapt_path(p, args);
			free_split(p);
			return (res);
		}
	}
	return (NULL);
}
