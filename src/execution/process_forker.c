/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_forker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 18:34:20 by abenouda          #+#    #+#             */
/*   Updated: 2021/10/01 15:06:44 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	piper(int *fd, t_command **cmd, t_all *all, int *in)
{
	int	ret;

	while ((*cmd)->next)
	{
		pipe (fd);
		(*cmd)->in = *in;
		(*cmd)->out = fd[1];
		ret = check_redir(*cmd, all->l_env);
		if ((!ret || ret == 1) && (*cmd)->cmd[0])
			spawn_proc (*cmd, all->l_env, fd);
		else
			return (-1);
		close(fd[1]);
		if (*in)
			close(*in);
		*in = fd[0];
		*cmd = (*cmd)->next;
	}
	return (0);
}

int	fork_pipes(t_command *cmd, t_list *env, t_all *all)
{
	int	pid;
	int	in;
	int	fd[2];
	int	status;

	in = 0;
	pid = 0;
	if (piper(fd, &cmd, all, &in) == -1)
		return (-1);
	cmd->in = in;
	if (!check_redir(cmd, env) && cmd->cmd[0])
	{
		pid = spawn_proc(cmd, env, fd);
		if (cmd->in)
			close(cmd->in);
	}
	else
		return (-1);
	while (wait(&status) != -1)
		;
	if (WIFEXITED(status))
		all->ex = WEXITSTATUS(status);
	else if (WIFSIGNALED(status) && (WTERMSIG(status) + 128 != 141))
		all->ex = WTERMSIG(status) + 128;
	return (pid);
}
