/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 12:45:34 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/10/01 12:40:25 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	return_error_norm(void)
{
	error_multiline();
	return (-1);
}

void	free_and_null(char **str)
{
	free(*str);
	*str = NULL;
}
