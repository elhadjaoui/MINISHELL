/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:57:18 by abenouda          #+#    #+#             */
/*   Updated: 2021/09/21 15:59:29 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	ft_pwd(int fd)
{
	char	*s;

	s = getcwd(NULL, 0);
	ft_putstr_fd(s, fd);
	ft_putstr_fd("\n", fd);
	free(s);
}
