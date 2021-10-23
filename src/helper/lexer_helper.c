/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <mel-hadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 10:51:39 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/09/30 18:10:51 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	display_parser(t_command *cmd)
{
	int	i;

	while (cmd)
	{
		i = 0;
		while (cmd->cmd[i])
		{
			printf("cmd/arg = (%s)\n", cmd->cmd[i]);
			i++;
		}
		while (cmd->redirect)
		{
			printf("redirect = (%s - %d)\n", cmd->redirect->name,
				cmd->redirect->type);
			cmd->redirect = cmd->redirect->next;
		}
		cmd = cmd->next;
		printf("-------------------\n");
	}
}

void	clear_token(t_token **lst, void (*del)(void*))
{
	t_token	*next_node;
	t_token	*current;

	if (lst && del)
	{
		next_node = (*lst);
		current = (*lst);
		while (next_node != NULL)
		{
			current = next_node;
			next_node = next_node->next;
			(*del)(current->name);
			free(current);
		}
		*lst = NULL;
	}
}

void	clear_parser(t_command **lst)
{
	t_command	*next_node;
	t_command	*current;
	int			i;

	i = 0;
	if (lst)
	{
		next_node = (*lst);
		current = (*lst);
		while (next_node != NULL)
		{
			current = next_node;
			next_node = next_node->next;
			while (current->cmd[i])
			{
				free(current->cmd[i]);
				i++;
			}
			i = 0;
			free(current->cmd);
			clear_redirect(&current->redirect, free);
			free(current);
		}
		*lst = NULL;
	}
}

void	clear_redirect(t_redirect **lst, void (*del)(void*))
{
	t_redirect	*next_node;
	t_redirect	*current;

	if (lst && del)
	{
		next_node = (*lst);
		current = (*lst);
		while (next_node != NULL)
		{
			current = next_node;
			next_node = next_node->next;
			free(current);
		}
		*lst = NULL;
	}
}

int	free_and_return(char **str)
{
	free(*str);
	return (-1);
}
