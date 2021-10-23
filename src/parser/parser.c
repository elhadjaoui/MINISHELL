/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <mel-hadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 16:05:17 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/09/30 17:46:17 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	check_redirect_output(t_token **token, char *str, t_redirect **redirect,
		t_all *all)
{
	char	*str1;
	char	*str2;

	(*token) = (*token)->next;
	str1 = (*token)->name;
	if ((*token)->next != NULL)
		str2 = (*token)->next->name;
	else
		str2 = NULL;
	if (cmp(str1, str))
	{
		if (check_next_token_after_redirection(str, str2, all) == -1)
			return (-1);
		(*token) = (*token)->next;
		add_redirection_back(redirect, new_redirection(2, str2));
	}
	else
		add_redirection_back(redirect, new_redirection(1, str1));
	return (1);
}

int	check_redirect_input(t_token **token, char *str, t_redirect **redirect,
		t_all *all)
{
	char	*str1;
	char	*str2;

	(*token) = (*token)->next;
	str1 = (*token)->name;
	if ((*token)->next != NULL)
		str2 = (*token)->next->name;
	else
		str2 = NULL;
	if (cmp(str1, str))
	{
		if (check_next_token_after_redirection(str, str2, all) == -1)
			return (-1);
		(*token) = (*token)->next;
		add_redirection_back(redirect, new_redirection(4, str2));
	}
	else
		add_redirection_back(redirect, new_redirection(3, str1));
	return (1);
}

int	redirect_input(t_token **token, t_redirect **redirect, t_all *all)
{
	if ((*token)->next == NULL)
	{
		all->ex = 258;
		syntax_error("newline");
		return (-1);
	}
	else if (cmp((*token)->next->name, "|"))
	{
		all->ex = 258;
		syntax_error("|");
		return (-1);
	}
	else if (check_redirect_input(token, "<", redirect, all) == -1)
		return (-1);
	return (1);
}

int	redirect_output(t_token **token, t_redirect **redirect, t_all *all)
{
	if ((*token)->next == NULL)
	{
		all->ex = 258;
		syntax_error("newline");
		return (-1);
	}
	else if (cmp((*token)->next->name, "|"))
	{
		all->ex = 258;
		syntax_error("|");
		return (-1);
	}
	else if (cmp((*token)->next->name, "<"))
	{
		all->ex = 258;
		syntax_error("<");
		return (-1);
	}
	else if (check_redirect_output(token, ">", redirect, all) == -1)
		return (-1);
	return (1);
}

int	parser(t_token *token, t_all *all)
{
	t_command	*cmd;
	t_redirect	*redirect;
	char		*string;

	cmd = NULL;
	all->token = token;
	if (check_start(token, all) == -1)
		return (-1);
	while (token)
	{
		string = ft_strdup("");
		redirect = NULL;
		if (parser_justForNorm1(&token, &redirect, &string, all) == -1)
			return (-1);
		if (token)
			if (check_multiple_pipes(token, all) == -1)
				return (return_error_pipes(&string));
		add_cmd_back(&cmd, new_cmd(ft_split(string, '@'), redirect));
		if (token)
			token = token->next;
		free(string);
	}
	all->cmd = cmd;
	return (1);
}
