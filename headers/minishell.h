/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:54:15 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/10/01 15:06:59 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../utils/utils.h"
# include <unistd.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/stat.h>
# include <signal.h>
# include <fcntl.h>
# include <stdbool.h>

# define SPECIAL_C " <>'\"$|"
# define SPECIAL_C1 " <>$|"
# define NORMAL 0  // state NORMAL (all the special charachter handled here)
# define QUOTE1 1  // state QUOTE1 ( "" \ $ special charachter handled here)
# define QUOTE2 2  // state QUOTE2 (all is charachter)

# define S_QUOTE 3
# define D_QUOTE 4
# define BACK_S 92
# define SEMICOLON 36
# define TEXT -1
# define PIP 124
# define MYSPACE 32
# define SKIP_CHAR 48
# define GREAT 62
# define LESS 60
# define DOLLAR 61
# define QMARK 88

# define KEY_UP 183
# define KEY_DOWN 184
# define KEY_LEFT 186
# define KEY_RIGHT 185
# define ENTER 10
# define KEY_REMOVE 127

typedef struct s_token
{
	char				*name;
	int					num;
	struct s_token		*next;
}						t_token;

typedef struct s_env
{
	char				*name;
	char				*value;
}						t_env;

typedef struct s_dlist
{
	void				*node;
	struct s_dlist		*prev;
	struct s_dlist		*next;
}						t_dlist;

typedef struct s_redirect
{
	int					type;
	char				*name;
	int					fd;
	struct s_redirect	*next;
}						t_redirect;

typedef struct s_command
{
	char				**cmd;
	t_redirect			*redirect;
	int					in;
	int					out;
	struct s_command	*next;
}						t_command;

typedef struct s_all
{
	t_list				*l_cmd;
	t_dlist				*l_history;
	t_list				*l_env;
	t_env				*env;
	t_command			*cmd;
	t_token				*token;
	char				*line;
	char				*ref_line;
	int					ex;
	int					fork;
	int					heredocfd;
	int					ret;
}						t_all;

int			term_loop(t_all *all);
//------------------------EXECUTION-------------------------
t_all		*all_init_static(void);
int			pipeline(t_all *all);
void		printpp(t_list *pp);
char		*grab_env(t_list *lenv, char *wanted);
char		*adapt_path(char **paths, char **args);
char		*fix_path(t_list *env, char **args);
char		**getpaths(char *path);
int			fork_pipes(t_command *cmd, t_list *env, t_all *t_all);
void		printpp(t_list *pp);
int			pipeline(t_all *all);
int			here_doc(char *stop, t_list *l_env);
int			err_msg(char *name);
int			check_redir(t_command *cmd, t_list *l_env);
int			spawn_proc(t_command *cmd, t_list *env, int *fd);
char		*get_name(char *env);
void		list_env(t_all *all, char **env);
char		**env_form(t_list *list);
void		ft_echo(char **arg);
int			ft_cd(t_all *all, char *path);
void		ft_pwd(int fd);
void		ft_export(t_list *env, t_command *cmd);
void		ft_export_na(t_list *env, int fd);
void		ft_export_wa(t_list *env, t_env *var);
void		ft_env(t_list *env, int fd);
void		ft_unset(t_all *all, char *var);
void		ft_exit(t_command *cmd);
char		*if_builtin(char *cmd);
void		exec_builtin(t_command *cmd, t_list *env);
void		exec_echo(t_command *cmd);
char		*if_non_forkable(char *cmd);
void		exec_export(t_command *cmd, t_list *env);
void		exec_env(t_command *cmd, t_list *env);
void		exec_pwd(t_command *cmd);
void		ft_export(t_list *env, t_command *cmd);
void		ft_unset_loop(t_all *all, t_command *cmd);
void		ft_exit(t_command *cmd);
//**************************************
char		*expand_env_vars(char **line, t_all *all);
void		expand_norm(char **line, t_all *all, char **result);
void		expand_norm1(char **line, char **result);
int			here_doc(char *stop, t_list *l_env);
char		*home_path(t_all *all);
t_list		*search_lst(t_list *list, char *var);
void		set_oldpwd(t_all *all);
void		set_pwd(t_all *all);
void		export_parse(t_list *lenv, char *s);
void		print_export(t_list *list, int fd);
void		free_split(char **p);
//--------------------------------------PARSING--------------------------------
int			parser(t_token *token, t_all *all);
int			cmd_list_size(t_command *lst);
void		add_cmd_back(t_command **alst, t_command *new);
t_command	*new_cmd(char **cmd, t_redirect *redirect);
void		add_redirection_back(t_redirect **alst, t_redirect *new);
t_redirect	*new_redirection(int type, char *name);
int			redirection_list_size(t_redirect *lst);
int			redirect_input(t_token **token, t_redirect **redirect, t_all *all);
int			redirect_output(t_token **token, t_redirect **redirect, t_all *all);
//-------------------------LEXING---------------------------------------
t_token		*build_lexer(t_all *all);
t_token		*toknew(char *name, int num);
void		tokadd_back(t_token **alst, t_token *new);
void		tokadd_front(t_token **alst, t_token *new);
int			toksize(t_token *lst);
//-------------------------ERROR-----------------------------------------
void		error_multiline(void);
void		syntax_error(char *str);
//-------------------------HELPERS-----------------------------------------
int			ft_search4special_character(const char *str, char c);
int			cmp(char *s1, char *s2);
int			ft_strcmp(const char *s1, const char *s2);
int			str_n_char(char *str, char c);
char		*ft_strjoinchar(char *s, char c);
char		*ft_strndup(const char *str, size_t size);
void		next_node(t_dlist **list);
void		prev_node(t_dlist **list);
void		double_char_to_list(t_list **list, char **str);
t_dlist		*lstnewc(void *node);
void		lstadd_dlist(t_dlist **alst, t_dlist *new);
void		display_token(t_token *token);
char		*skip_whitespaces(char *line);
int			search_for_special_character(char **line, char **str,
				t_token **token,
				t_all *all);
int			search_forNext_quote(char **line, char **str);
void		add_special_character_to_token(char **str, t_token **token,
				char **line);
int			search_forNext_Dquote(char **line, char **str, t_all *all,
				t_token **token);
int			add_special_character(t_token **token, char **line, char **str);
void		display_parser(t_command *cmd);
void		handle_dollar(char **line, t_all *all, char **str,
				t_token **token);
int			get_env_value(t_token **token, char **string, t_all *all);
int			check_wich_special_charcter(t_token **token,
				t_redirect **redirect, t_all *all);
void		join_characters(char **string, t_token *token);
void		free_string(char **str);
int			check_cmd_starts(char *str, int num, t_all *all);
int			check_multiple_pipes(t_token *token, t_all *all);
int			check_next_token_after_redirection(char *str, char *str2,
				t_all *all);
int			parser_justForNorm(t_token **token, t_redirect **redirect,
				char **string, t_all *all);
int			return_error_norm(void);
void		handle_dollar_norm1(char **str, t_token **token, char **s);
void		handle_dollar_norm(char **line, t_all *all, char **str,
				t_token **token);
void		handle_dollar_norm2(char **line, char **str, t_all *all);
void		handle_dollar_norm3(char **line, char **str, char c);
void		handle_dollar(char **line, t_all *all, char **str, t_token **token);
void		clear_token(t_token **lst, void (*del)(void*));
void		clear_parser(t_command **lst);
void		clear_redirect(t_redirect **lst, void (*del)(void*));
void		ft_free(char **str);
char		*ft_strjoinchar1(char **s, char c);
int			parser_justForNorm1(t_token **token, t_redirect **redirect,
				char **string, t_all *all);
int			check_start(t_token *token, t_all *all);
int			return_error_pipes(char **string);
int			free_and_return(char **str);
void		free_and_null(char **str);
//---------------------------------main-------------------------------------
void		ctrl_d(void);
void		ctrl_c(int num);
void		ctrl_AS(int a);
t_all		*all_init_static(void);
void		init_all(t_all *all);
void		term_prompt(void);
#endif
