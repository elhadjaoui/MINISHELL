/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <mel-hadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 18:59:31 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/09/30 12:04:41 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	expand_norm(char **line, t_all *all, char **result)
{
	char	*s;

	s = ft_strdup("");
	(*line)++;
	if (**line != '\0')
	{
		while (**line && ((**line <= 'z' && **line >= 'a')
				|| (**line <= 'Z' && **line >= 'A')
				|| (**line <= '9' && **line >= '0')))
		{
			s = ft_strjoinchar(s, **line);
			(*line)++;
		}
		s = grab_env(all->l_env, s);
		if (s != NULL)
			*result = ft_strjoin1(*result, s);
	}
}

void	expand_norm1(char **line, char **result)
{
	(*line)++;
	*result = ft_strjoinchar(*result, '$');
	if (**line && **line != '\"')
		(*line)++;
}
