/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:30:51 by abenouda          #+#    #+#             */
/*   Updated: 2021/09/21 16:30:54 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

char	*if_non_forkable(char *cmd)
{
	if (cmd)
	{
		if (!ft_strcmp(cmd, "cd"))
			return (cmd);
		else if (!ft_strcmp(cmd, "export"))
			return (cmd);
		else if (!ft_strcmp(cmd, "unset"))
			return (cmd);
		else if (!ft_strcmp(cmd, "exit"))
			return (cmd);
	}
	return (NULL);
}

char	*if_builtin(char *cmd)
{
	if (!ft_strcmp(cmd, "echo"))
		return (cmd);
	else if (!ft_strcmp(cmd, "cd"))
		return (cmd);
	else if (!ft_strcmp(cmd, "pwd"))
		return (cmd);
	else if (!ft_strcmp(cmd, "export"))
		return (cmd);
	else if (!ft_strcmp(cmd, "unset"))
		return (cmd);
	else if (!ft_strcmp(cmd, "env"))
		return (cmd);
	else if (!ft_strcmp(cmd, "exit"))
		return (cmd);
	return (NULL);
}
