/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <mel-hadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 12:44:57 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/09/30 17:46:42 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	get_env_value(t_token **token, char **string, t_all *all)
{
	char	*str;

	if ((*token)->next != NULL)
	{
		(*token) = (*token)->next;
		str = grab_env(all->l_env, (*token)->name);
		if (str != NULL)
			*string = ft_strjoin1(*string, str);
	}
	return (1);
}

int	get_qmark_value(t_token **token, char **string, t_all *all)
{
	char	*str;

	if ((*token)->next != NULL)
	{
		(*token) = (*token)->next;
		str = ft_itoa(all->ex);
		if (str != NULL)
			*string = ft_strjoin1(*string, str);
		*string = ft_strjoin1(*string, " ");
	}
	return (1);
}

void	join_characters(char **string, t_token *token)
{
	*string = ft_strjoin1(*string, token->name);
	*string = ft_strjoin1(*string, "@\0");
}

int	check_cmd_starts(char *str, int num, t_all *all)
{
	if (*str == '|' && num != 1)
	{
		all->ex = 258;
		syntax_error("|");
		return (-1);
	}
	return (1);
}

int	return_error_pipes(char **string)
{
	free(*string);
	return (-1);
}
