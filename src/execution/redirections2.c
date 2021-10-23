/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 17:09:08 by abenouda          #+#    #+#             */
/*   Updated: 2021/09/22 17:51:51 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	err_msg(char *name)
{
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(strerror(errno), 2);
	return (1);
}

int	handle_type(t_command **cmd, t_redirect **rd, t_list *l_env)
{
	if ((*rd)->type == 3)
		(*rd)->fd = open((*rd)->name, O_RDONLY);
	else if ((*rd)->type == 1)
		(*rd)->fd = open((*rd)->name, O_RDWR | O_TRUNC | O_CREAT, 0644);
	else if ((*rd)->type == 2)
		(*rd)->fd = open((*rd)->name, O_RDWR | O_APPEND | O_CREAT, 0644);
	else if ((*rd)->type == 4)
	{
		if (here_doc((*rd)->name, l_env))
			return (-5);
		(*rd)->fd = open("/tmp/input_tmp", O_RDONLY);
	}
	if ((*rd)->fd == -1)
	{
		(*cmd)->in = -5;
		return (err_msg((*rd)->name));
	}
	else
	{
		if ((*rd)->type == 4 || (*rd)->type == 3)
			(*cmd)->in = (*rd)->fd;
		else if ((*rd)->type == 1 || (*rd)->type == 2)
			(*cmd)->out = (*rd)->fd;
	}
	return (0);
}

int	check_redir(t_command *cmd, t_list *l_env)
{
	t_redirect	*rd;
	int			ret;

	rd = cmd->redirect;
	while (rd)
	{
		ret = handle_type(&cmd, &rd, l_env);
		if (ret)
			return (ret);
		rd = rd->next;
	}
	return (0);
}
