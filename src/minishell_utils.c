/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:14:53 by abenouda          #+#    #+#             */
/*   Updated: 2021/10/01 15:07:19 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	ctrl_d(void)
{
	rl_replace_line("", 0);
	rl_redisplay();
	ft_putendl_fd("exit", 1);
	exit(0);
}

void	ctrl_c(int num)
{
	t_all	*all;

	all = all_init_static();
	all->ex = num + 128;
	if (!all->heredocfd)
	{
		write(1, "\n", 1);
		if (!all->fork)
		{
			all->ex = 1;
			rl_replace_line("", 0);
			rl_redisplay();
			term_prompt();
		}
	}
}

void	ctrl_AS(int a)
{
	t_all	*all;

	(void)a;
	all = all_init_static();
	if (all->fork == 1)
		ft_putendl_fd("Quit: 3", 1);
	else
	{
		rl_on_new_line();
		rl_redisplay();
	}
}

t_all	*all_init_static(void)
{
	static t_all	all;

	return (&all);
}

void	init_all(t_all *all)
{
	all->l_cmd = NULL;
	all->l_env = NULL;
	all->l_history = NULL;
	all->env = NULL;
	all->line = NULL;
	all->ex = 0;
	all->fork = 0;
	all->heredocfd = 0;
}
