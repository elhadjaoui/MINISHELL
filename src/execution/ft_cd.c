/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:20:26 by abenouda          #+#    #+#             */
/*   Updated: 2021/09/20 16:10:32 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	no_path(char *np, t_all *all, int *r)
{
	np = grab_env(all->l_env, "HOME");
	if (!np)
		ft_putstr_fd("cd: HOME not set\n", 2);
	else
	{
		set_oldpwd(all);
		*r = chdir(home_path(all));
		set_pwd(all);
	}
}

void	absolute(char *np, char *path, t_all *all, int *r)
{
	np = ft_strjoin(home_path(all), path + 1);
	set_oldpwd(all);
	*r = chdir(np);
	set_pwd(all);
	free(np);
}

void	home(t_all *all, int *r)
{
	set_oldpwd(all);
	*r = chdir(home_path(all));
	set_pwd(all);
}

void	go_path(t_all *all, char *path, int *r)
{
	set_oldpwd(all);
	*r = chdir(path);
	set_pwd(all);
}

int	ft_cd(t_all *all, char *path)
{
	int		r;
	char	*np;

	r = 0;
	np = NULL;
	if (!path)
		no_path(np, all, &r);
	else if (path[0] == '~' && path[1])
		absolute(np, path, all, &r);
	else if (path[0] == '~' && !path[1])
		home(all, &r);
	else
		go_path(all, path, &r);
	if (r != 0)
	{
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd("\n", 2);
	}
	return (r);
}
