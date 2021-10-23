/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <mel-hadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 11:14:45 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/09/22 14:48:31 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	ft_search4special_character(const char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

int	cmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (!*s1 && !*s2)
			return (1);
		s1++;
		s2++;
	}
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	display_token(t_token *token)
{
	while (token)
	{
		printf("token = (%s %d)\n", token->name, token->num);
		token = token->next;
	}
}

char	*skip_whitespaces(char *line)
{
	if (line == NULL)
		return (NULL);
	while (*line == ' ' || *line == '\t')
		line++;
	return (line);
}
