/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_norm_functions1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <mel-hadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 12:32:32 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/09/30 18:04:39 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	handle_dollar_norm5(t_token **token, char **str, char *space)
{
	if (ft_strlen(*str))
	{
		tokadd_back(token, toknew(*str, TEXT));
		*str = ft_strdup("");
	}
	tokadd_back(token, toknew(space, TEXT));
}

void	handle_dollar_norm1(char **str, t_token **token, char **s)
{
	char	*space;

	while (*s && **s)
	{
		space = ft_strdup("");
		while (**s != ' ' && **s)
		{
			space = ft_strjoinchar(space, **s);
			(*s)++;
		}
		if (**s == ' ')
			handle_dollar_norm5(token, str, space);
		if (**s == '\0')
		{
			*str = ft_strjoin1(*str, space);
			free(space);
		}
		if (**s != '\0')
			(*s)++;
	}
}

void	handle_dollar_norm(char **line, t_all *all, char **str, t_token **token)
{
	char	*s;
	char	*tmp;

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
		tmp = s;
		s = grab_env(all->l_env, s);
		s = skip_whitespaces(s);
		handle_dollar_norm1(str, token, &s);
		free(tmp);
	}
}

void	handle_dollar_norm2(char **line, char **str, t_all *all)
{
	char	*tmp;

	tmp = ft_itoa(all->ex);
	(*line)++;
	*str = ft_strjoin1(*str, tmp);
	(*line)++;
	free(tmp);
}

void	handle_dollar_norm3(char **line, char **str, char c)
{
	(*line)++;
	*str = ft_strjoinchar(*str, '$');
	*str = ft_strjoinchar(*str, c);
	(*line)++;
}
