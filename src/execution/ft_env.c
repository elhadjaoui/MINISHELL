/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:41:24 by abenouda          #+#    #+#             */
/*   Updated: 2021/09/21 15:44:15 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	print_env(t_list *list, int fd)
{
	t_list	*l;

	l = list;
	while (l)
	{
		if (((t_env *)l->content)->value)
		{
			ft_putstr_fd(((t_env *)l->content)->name, fd);
			ft_putstr_fd("=", fd);
			ft_putstr_fd(((t_env *)l->content)->value, fd);
			ft_putstr_fd("\n", fd);
		}
		l = l->next;
	}
}

void	ft_env(t_list *env, int fd)
{
	t_list	*list;

	list = env;
	print_env(list, fd);
}
