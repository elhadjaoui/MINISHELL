/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 11:13:07 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/10/01 17:46:51 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	get_tokens(t_token **token, char **line, t_all *all, char **str)
{
	*line = skip_whitespaces(*line);
	while (**line && **line != ' ')
	{
		if (**line == '$')
			handle_dollar(line, all, str, token);
		if (ft_search4special_character("><|", **line))
		{
			add_special_character_to_token(str, token, line);
			free(*str);
			*str = NULL;
		}
		if (!ft_search4special_character(SPECIAL_C1, **line))
		{
			while (**line && **line != ' ')
			{
				if (search_for_special_character(line, str, token, all) == -1)
					return (-1);
			}
		}
		if (**line != '\0' && **line != ' ' && **line != '$')
			(*line)++;
	}
	if (ft_strlen(*str))
		tokadd_back(token, toknew(*str, TEXT));
	return (1);
}

t_token	*build_lexer(t_all *all)
{
	char	*line;
	t_token	*token;
	char	*str;

	token = NULL;
	line = all->line;
	line = skip_whitespaces(line);
	while (*line)
	{
		str = ft_strdup("");
		if (get_tokens(&token, &line, all, &str) == -1)
		{
			all->ex = 258;
			clear_token(&token, free);
			return (NULL);
		}
		if ((*line) != '\0' && (*line) != '$')
			line++;
	}
	return (token);
}
