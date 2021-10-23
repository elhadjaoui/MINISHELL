/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <mel-hadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 12:42:57 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/09/25 11:53:09 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	str_n_char(char *str, char c)
{
	int	i;
	int	nb;

	i = -1;
	nb = 0;
	while (str[++i])
	{
		if (str[i] == c)
			nb++;
	}
	return (nb);
}

char	*ft_strjoinchar(char *s, char c)
{
	int		i;
	char	*str;

	i = 0;
	str = NULL;
	if (s != NULL)
	{
		while (s[i])
			i++;
		str = (char *)malloc(i + 2);
		if (!str)
			return (0);
		i = -1;
		while (s[++i])
			str[i] = s[i];
		str[i] = c;
		str[i + 1] = '\0';
		free(s);
	}
	return (str);
}

// char	*ft_strjoinchar1(char **s, char c)
// {
// 	int		i;
// 	char	*str;

// 	i = 0;
// 	str = NULL;
// 	if (*s == NULL)
// 		*s = ft_strdup("");
// 	while (*s[i])
// 		i++;
// 	str = (char *)malloc(i + 2);
// 	if (!str)
// 		return (0);
// 	i = -1;
// 	while (*s[++i])
// 		str[i] = *s[i];
// 	str[i] = c;
// 	str[i + 1] = '\0';
// 	free(*s);
// 	return (str);
// }

char	*ft_strndup(const char *str, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	char			*cp;

	i = 0;
	j = 0;
	while (str[i] != '\0')
		i++;
	if (i > size)
		i = size;
	cp = (char *)malloc(sizeof(char) * (i + 1));
	if (!cp)
		return (NULL);
	while (j < (sizeof(char) * i))
	{
		cp[j] = str[j];
		j++;
	}
	cp[j] = '\0';
	return (cp);
}

void	free_content(void *content)
{
	if ((char *)content)
	{
		free((char *)content);
		content = 0;
	}
}

void	free_char(char **s)
{
	int		i;
	char	*ss;

	ss = *s;
	i = ft_strlen(*s);
	free(ss);
	while (i >= 0)
	{
		ss[i] = '\0';
		i--;
	}
}
