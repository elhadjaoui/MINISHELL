/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_pipeline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 11:21:01 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/09/21 18:32:05 by ç         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	exec_non_forkable(t_command *cmd, t_all *all)
{
	if (!ft_strcmp(cmd->cmd[0], "cd"))
		ft_cd(all, cmd->cmd[1]);
	else if (!ft_strcmp(cmd->cmd[0], "export"))
		ft_export(all->l_env, cmd);
	else if (!ft_strcmp(cmd->cmd[0], "unset"))
		ft_unset_loop(all, cmd);
	else if (!ft_strcmp(cmd->cmd[0], "exit"))
		ft_exit(cmd);
}

int	pipeline(t_all *all)
{
	t_command	*cmd;

	cmd = all->cmd;
	if (cmd)
	{
		all->fork = 1;
		if (!cmd->next && if_non_forkable(cmd->cmd[0]))
			exec_non_forkable(cmd, all);
		else
			if (fork_pipes(cmd, all->l_env, all))
				return (-1);
	}
	return (0);
}
