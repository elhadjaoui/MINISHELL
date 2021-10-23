/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <mel-hadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 19:08:43 by abenouda          #+#    #+#             */
/*   Updated: 2021/09/23 19:02:41 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	expand_norm2(char **line)
{
	(*line)++;
	(*line)++;
}

void	expand_norm3(char **line, char **result)
{
	(*line)++;
	*result = ft_strjoinchar(*result, '$');
	*result = ft_strjoinchar(*result, '=');
	(*line)++;
}

void	expand_norm4(char **line, char **result, t_all *all)
{
	(*line)++;
	*result = ft_strjoin(*result, ft_itoa(all->ex));
	(*line)++;
}

void	expand_norm5(char **line, char **result)
{
	if (**line != '$')
		*result = ft_strjoinchar(*result, **line);
	if (**line && **line != '$')
		(*line)++;
}

char	*expand_env_vars(char **line, t_all *all)
{
	char	*result;
	char	*string;

	result = ft_strdup("");
	while (**line)
	{
		string = *line + 1;
		if (**line == '$')
		{
			if (ft_search4special_character("\\;|\"", *string) || *string == '\0')
				expand_norm1(line, &result);
			else if ((*string <= '9' && *string >= '0'))
				expand_norm2(line);
			else if (*string == '=')
				expand_norm3(line, &result);
			else if (ft_search4special_character("?", *string))
				expand_norm4(line, &result, all);
			else
				expand_norm(line, all, &result);
		}
		expand_norm5(line, &result);
	}
	return (result);
}
