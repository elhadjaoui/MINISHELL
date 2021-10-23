/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <mel-hadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:20:37 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/09/22 19:25:26 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	error_multiline(void)
{
	printf("minishel : multiline\n");
}

void	syntax_error(char *str)
{
	printf("minishel : syntax error near unexpected token `%s'\n", str);
}
