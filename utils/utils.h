/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 00:39:08 by abenouda          #+#    #+#             */
/*   Updated: 2021/10/01 15:20:37 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_atoi(const char *str);

char				*ft_itoa(int n);

void				ft_putendl_fd(char *s, int fd);

void				ft_putstr_fd(char *s, int fd);

char				**ft_split(const char *s, char c);

char				*ft_strdup(const char *s);

char				*ft_strjoin(char *s1, char const *s2);

int					ft_isdigit(int c);

char				*ft_strchr(const char *s, int c);

size_t				ft_strlen(const char *str);

t_list				*ft_lstnew(void *content);

int					ft_lstsize(t_list *lst);

void				ft_lstadd_back(t_list **alst, t_list *new);

char				*ft_strjoin1(char *s1, char const *s2);

#endif
