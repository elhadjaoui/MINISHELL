/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:27:25 by abenouda          #+#    #+#             */
/*   Updated: 2021/09/22 19:09:28 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	handlec(int a)
{
	(void)a;
	write(1, "\n", 1);
	exit(-5);
}

void	fork_herdoc(t_all *all, int *fd, char *stop)
{
	char	*str;

	signal(SIGINT, handlec);
	str = strdup("");
	while (1)
	{
		str = readline("> ");
		if (!str || !ft_strcmp(str, stop))
			break ;
		if (!str)
			continue ;
		str = expand_env_vars(&str, all);
		ft_putendl_fd(str, *fd);
	}
	if (str)
		free(str);
	exit(0);
}

int	here_doc(char *stop, t_list *l_env)
{
	int		fd;
	int		pid;
	int		status;
	t_all	*all;

	(void)l_env;
	all = all_init_static();
	fd = open("/tmp/input_tmp", O_RDWR | O_TRUNC | O_CREAT, 0644);
	all->heredocfd = fd;
	if (fd < 0)
		return (-1);
	pid = fork();
	if (!pid)
		fork_herdoc(all, &fd, stop);
	while (waitpid(pid, &status, 0) != -1)
		usleep(200000);
	if (WIFEXITED(status))
	{
		close(fd);
		return (WEXITSTATUS(status));
	}
	return (0);
}
