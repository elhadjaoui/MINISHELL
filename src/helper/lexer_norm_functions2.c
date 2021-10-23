/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_norm_functions2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <mel-hadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 12:36:04 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/09/30 10:07:42 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	handle_dollar(char **line, t_all *all, char **str, t_token **token)
{
	char	*string;
	char	*tmp;

	string = *line + 1;
	if (ft_search4special_character("\\;|", *string) || *string == '\0')
	{
		(*line)++;
		tmp = *str;
		*str = ft_strjoinchar(*str, '$');
		if (**line && **line != '\"')
			(*line)++;
	}
	else if ((*string <= '9' && *string >= '0'))
	{
		(*line)++;
		(*line)++;
	}
	else if (*string == '=' || *string == '+')
		handle_dollar_norm3(line, str, *string);
	else if (ft_search4special_character("?", *string))
		handle_dollar_norm2(line, str, all);
	else
		handle_dollar_norm(line, all, str, token);
}

int	check_wich_special_charcter(t_token **token, t_redirect **redirect,
	t_all *all)
{
	char	*str;
	int		num;

	str = (*token)->name;
	num = (*token)->num;
	all->ex = 1;
	if (cmp(str, ">"))
		 if (redirect_output(token, redirect, all) == -1)
			return (-1);
	if (cmp(str, "<"))
		if (redirect_input(token, redirect, all) == -1)
			 return (-1);
	return (1);
}
