/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <mel-hadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 12:12:20 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/09/30 18:21:52 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minishell.h"

void	term_prompt(void)
{
	write(1, "<%%%%|==========> ", 18);
}

int	isNotEmpty(char *s)
{
	if (ft_strlen(s) == 0)
		return (0);
	return (1);
}

void	helper1(t_all *all)
{
	signal(SIGINT, ctrl_c);
	signal(SIGQUIT, ctrl_AS);
	all->fork = 0;
	all->heredocfd = 0;
	all->line = readline("<%%%%|==========> ");
	if (!all->line)
		ctrl_d();
	if (all->line[0] != '\0')
		add_history(all->line);
}

int	helper2(int *r, t_all *all)
{
	t_token	*token;

	token = build_lexer(all);
	if (token == NULL)
	{
		clear_token(&all->token, free);
		return (1);
	}
	if (parser(token, all) == 1)
	{
		*r = pipeline(all);
		clear_token(&all->token, free);
		clear_parser(&all->cmd);
		if (*r)
			return (1);
	}
	else
	{
		clear_token(&all->token, free);
		clear_parser(&all->cmd);
	}
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_all	*all;
	int		r;

	if (argc != 1)
		return (0);
	(void)argv;
	all = all_init_static();
	init_all(all);
	list_env(all, env);
	while (1)
	{
		helper1(all);
		if (isNotEmpty(all->line))
		{
			if (helper2(&r, all))
			{
				free(all->line);
				continue ;
			}
		}
		free(all->line);
	}
	return (1);
}
