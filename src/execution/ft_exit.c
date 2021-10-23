/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:14:45 by abenouda          #+#    #+#             */
/*   Updated: 2021/09/21 14:19:00 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	ft_exit_continuation(t_command *cmd, int i, int j, int *n)
{
	if ((!ft_isdigit(cmd->cmd[i][0]) && cmd->cmd[i][0] != '-') || j == -1)
	{
		ft_putstr_fd("exit: ", 2);
		ft_putstr_fd(cmd->cmd[i], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		exit(255);
	}
	while (cmd->cmd[i])
		i++;
	if (i > 2)
		ft_putstr_fd("exit: too many arguments\n", 2);
	else
	{
		*n = ft_atoi(cmd->cmd[1]);
		ft_putstr_fd("exit\n", 1);
		if (*n < 0 || *n > 255)
			exit(*n % 256);
		exit(*n);
	}
}

void	ft_exit(t_command *cmd)
{
	int	i;
	int	j;
	int	n;

	i = 1;
	j = 1;
	if (!cmd->cmd[1])
	{
		ft_putstr_fd("exit\n", 1);
		exit(0);
	}
	if (ft_strlen(cmd->cmd[i]) > 1)
	{
		while (cmd->cmd[i][j])
			if (!ft_isdigit(cmd->cmd[i][j++]))
				j = -1;
	}
	ft_exit_continuation(cmd, i, j, &n);
}
