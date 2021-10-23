/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 11:21:24 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/10/01 14:33:17 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	duper(t_command *cmd, int *fd)
{
	if (cmd->in)
	{
		dup2 (cmd->in, 0);
		close (cmd->in);
	}
	if (cmd->out != 1)
	{
		dup2 (cmd->out, 1);
		close (cmd->out);
	}
	close(fd[0]);
	close(fd[1]);
}

void	cmd404(t_command **cmd)
{
	ft_putstr_fd((*cmd)->cmd[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	exit (127);
}

int	spawn_proc(t_command *cmd, t_list *env, int *fd)
{
	int		pid;
	char	*path;

	if (cmd->in == -5)
		return (0);
	if (if_builtin(cmd->cmd[0]))
	{
		exec_builtin(cmd, env);
		return (0);
	}
	else
	{
		pid = fork();
		if (!pid)
		{
			duper(cmd, fd);
			path = fix_path(env, cmd->cmd);
			if (!path)
				cmd404(&cmd);
			execve(path, cmd->cmd, env_form(env));
			exit(0);
		}
		return (pid);
	}
	return (0);
}
