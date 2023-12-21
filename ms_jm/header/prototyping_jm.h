/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototyping_jm.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoraes- <jmoraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:21:41 by phialfai          #+#    #+#             */
/*   Updated: 2023/12/15 00:17:25 by jmoraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPING_JM_H
# define PROTOTYPING_JM_H

//PROTOTYPES
//BUILTINS2
//ms_jm/builtins2/cd.c
int			ft_cd(char *cmd, char **args, t_env **s_msenv);
char		*ft_getpath(char *args, t_env **s_msenv);
int			ft_cd_error(void);
//ms_jm/builtins2/echo.c
int			ft_echo(char *cmd, char **args, t_env **s_msenv);
//ms_jm/builtins2/env.c
int			ft_env(char *cmd, char **args, t_env **s_msenv);
///ms_jm/builtins2/exit.c
int			test_all(char *str);
int			ft_exit(char *cmd, char **args, t_env **s_msenv);
//ms_jm/builtins2/export.c
int			ft_export(char *cmd, char **args, t_env **s_msenv);
//ms_jm/builtins2/export_key.c
int			ft_valkey(char *name);
//ms_jm/builtins2/export_utils1.c
char		*ft_keyonly(char *key_pair);
char		*ft_valueonly(char *key_pair);
int			ft_declare_env(t_env *s_msenv);
void		declarex(char *voidkeys);
//ms_jm/builtins2/pwd.c
int			ft_pwd(char *cmd, char **args, t_env **s_msenv);
//ms_jm/builtins2/builtins_utils.c
int			ft_strlen(char *str);
char		*ft_strnstr(const char *bg, const char *lt, size_t len);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			is_builtin(char *cmd);
//ms_jm/builtins2/unset.c
int			ft_unset(char *cmd, char **args, t_env **s_msenv);
//MSENV
//ms_jm/msenv2/msenv_cleanup.c
void		msenv_cleanupnode(t_env *s_msenv);
void		msenv_cleanup(t_env **s_msenv);
//ms_jm/msenv2/msenv_getnode.c
char		*msenv_getkey(char *value, t_env **s_msenv);
char		*msenv_getvalue(char *key, t_env **s_msenv);
t_env		*msenv_getnode(char *key, t_env **s_msenv);
//ms_jm/msenv2/msenv_ini.c
t_env		*msenv_ini(char **envp);
//ms_jm/msenv2/msenv_convert.c
size_t		msenv_size(t_env *s_msenv);
char		**msenv_to_envp(t_env *s_msenv);
//ms_jm/msenv2/msenv_load.c
int			lst_load(char *args, t_env **s_msenv);
void		msenv_load(char **envp, t_env **s_msenv);
//ms_jm/msenv2/msenv_minload.c
void		lst_minload(char *envp, t_env **s_msenv);
void		msenv_minload(t_env **s_msenv);
//ms_jm/msenv2/msenv_shlvlup.c
void		shlvl_update(t_env **s_msenv);
//ms_jm/msenv2/msenv_updates.c
void		pwd_update(char *pwd, t_env **s_msenv);
void		oldpwd_update(char *oldpwd, t_env **s_msenv);
void		msenv_update(char *key, char *value, t_env **s_msenv);
//ms_jm/msenv2/msenv_utils.c
char		*ft_getkey(char *key_pair);
char		*ft_getvalue(char *key_pair);
char		*msenv_xkey(char *keypair);
char		*msenv_xvalue(char *keypair);
//ms_jm/msenv2/msenv_utils2.c
int			ft_strlen_jm(char *s);
char		*ft_strdup_jm(const char *s);
char		*ft_strjoin_jm(char *s1, char *s2);
//ms_jm/utils2/ft_str_equal.c
int			ft_str_equal(const char *s1, const char *s2);
//ms_jm/utils2/ft_str_equal.c
int			ft_is_varname(char c);
int			ft_is_valid_varname(char *name);
//ms_jm/utils2/ft_error.c
void		ft_print_error_msg(char *command, char *msg);
void		ft_exit_w_error(char *command, char *msg, int error);
void		ft_exit_w_perror(char *command, char *perror_msg, int error);
void		ft_print_varname_err_msg(char *command, char *varname);
//ms_jm/utils/signals.c
void		define_main_signals(void);
void		define_execute_signals(int child_pid);
void		define_heredoc_signals(int child_pid);
//ms_jm/utils/expand_exit_status
void		expand_exit_status(char **input, int exit_status);
//ms_jm/utils/expand_variables
void		expand_variables(char **input, t_env *s_msenv);
//ms_jm/utils/expand_wildcard_b.c
// int			is_wildcard_label(char c);
// char		*get_wildcard_label_position(char *str);
//void	update_input(char **input, char *wildcard_value, char *second_part);
// char		*get_wildcard_label(char *wildcard_label_position);
// void		expand_wildcards(char *search, char **input, t_env *s_msenv);
//ms_jm/utils/handle_expansions.c
void		handle_expansions(char **input, t_env *s_msenv, int exit_status);
//ms_jm/utils/str_checkers.c
int			ft_isempty(char *str);
int			ft_isquote(char c);
int			ft_haspipe(char *str);
int			ft_isnamelimiter(char c);
//ms_jm/utils/array_utils.c
int			ft_printarray(char **arr);
int			ft_arraylen(char **arr);
void		ft_freearray(char **arr);
//ms_jm/utils/str_utils.c
int			str_equal(const char *str1, const char *str2);
void		ft_memfw(char *str);
//MSENV
//ms_jm//msenv/msenv_free.c
void		ft_cleanup_msenvnode(t_env **s_msenv, const char *key);
void		ft_cleanup_msenv(t_env **s_msenv);
//ms_jm//msenv/msenv_init.c
void		list_append(char *key_pair, t_env **list);
t_env		*init_s_msenv(char **envp);
//ms_jm//msenv/msenv_str_utils.c
char		*ft_getkey(char *key_pair);
char		*ft_getvalue(char *key_pair);
char		*ft_create_keypair(char *name, char *value);
//ms_jm//msenv/msenv_utils.c
t_env		*s_msenv_node(char *name, t_env *s_msenv);
char		*s_msenv_value(char *name, t_env *s_msenv);
size_t		s_msenv_size(t_env *s_msenv);
char		**s_msenv_to_envp(t_env *s_msenv);
//ms_jm/msenv_update.c
void		s_msenv_update(char *name, char *value, t_env *s_msenv);
void		s_msenv_updatenew(char *name, char *value, t_env *s_msenv);
//ms_jm//msenv/msenv_init2.c
t_env		*ft_getnode2(t_env *s_msenv, const char *str);
t_env		**ft_initenv(t_env **s_msenv, char **envp);
//ms_jm//msenv/msenv_utils2.c
int			ft_list_struct(t_env **s_msenv);
char		*ft_strjoin_null(char const *s1, char const *s2);
//ms_jm//msenv/msenv_utils2b.c
char		*ft_getkey(char *envp);
char		*ft_getvalue(char *envp);
int			ft_addenv(t_env **s_msenv, char *envp);
//ms_jm//msenv/msenv_utils3b.c
t_env		*ft_getnode(char *key, t_env *s_msenv);
char		*ft_nodevalue(char *key, t_env *s_msenv);
char		*ft_getkey(char *envp);
char		*ft_getvalue(char *envp);
int			ft_addenv(t_env **s_msenv, char *envp);
//ms_jm//msenv/msenv_utils2.c
int			ft_strlen_null(char *s);
char		*ft_strjoin_null(char const *s1, char const *s2);
//ms_jm/utils/fd_utils.c
void		close_extra_fds(void);
void		close_all_fds(void);
//ms_jm/utils/ft_atoll.c
long long	ft_atoll(const char *str);
//ms_jm/utils/get_label_name.c
char		*get_label_name(char *redirect_str);
//ms_jm/utils/list_utils.c
void		ft_prnfiltredlst(t_env **list, char *pattern);
void		ft_printlst(t_env **list);
void		ft_update_list(t_env **list);
void		shlvl_update(t_env **s_msenv);
//ms_jm/utils/quotes_utils.c
int			ft_check_uquotes(char *str);
int			ft_skipquotes(char *str);
//ms_jm/utils/variables_utils.c
int			is_varname(char c);
int			is_valid_varname(char *name);
//main/split_commands.c
char		**split_commands(char *input);
//main/handle_heredoc.c
char		*get_heredoc_position(char *str);
void		read_heredoc(int *exit_status, t_env *s_msenv, t_heredoc *s_hd,
				int heredoc_number);
int			exec_heredoc(t_heredoc *s_hd, int heredoc_number, int *exit_status,
				t_env *s_msenv);
int			handle_heredoc(char *input, int *exit_status, t_env *s_msenv);
//main/handle_heredoc_uitls.c
void		delimiter_cleaner(char **heredoc_position, t_heredoc *s_hd);
void		readline_heredoc(int *exit_status, int tmp_file_fd, \
			t_env *s_msenv, t_heredoc *s_hd);
//src/main.c
int			main(int argc, char **argv, char **envp);
//src/minishell.c
int			ft_minishell(t_env *s_msenv);
//src/prompt.c
char		*get_prompt_str(t_env *s_msenv);
char		*prompt_input(t_env *s_msenv);
//error/input_error.c
int			has_input_error(char *input, int *exit_status, t_env *s_msenv);
//error/error2.c
int			launch_error(void);
int			msenv_error(void);
int			cd_error(void);
int			input_error(char *input, int *status, t_env ms_env);
int			ft_error(const char *msg, int status);
//exec/get_path.c
char		*get_path(char *command, t_env *s_msenv);
//execute/execute_builtins.c
int			execute_forked_builtin(char **args, t_env **s_msenv);
int			execute_builtin(char **args, t_env **s_msenv);
//execute/execute_external.c
void		external_exit(char **args, t_env *s_msenv, int exit_status);
int			execute_external(char **args, t_env *s_msenv);
//execute/execute_multiple_commands.c
int			execute_multiple_commands(char **commands, t_env **s_msenv);
//execute/execute_one_command
int			execute_forked_external(char **args, t_env *s_msenv);
int			execute_one_command(char *command, t_env **s_msenv);
//execute/multi_cmd_utils.c
int			*init_children_pid(char **cmd);
void		clean_after_execute(int *pid);
void		quit_child(char **cmd, t_env **s_msenv);
//execute/one_cmd_utils.c
void		save_original_fd_in(int original_fds[2]);
void		save_original_fd_out(int original_fds[2]);
int			handle_input_redirect(char *command, int original_fds[2]);
int			handle_output_redirect(char *command, int original_fds[2]);
//execute/pipes.c
void		handle_pipe(int original_fd_out, char *current_command, \
			char **commands);
//execute/split_args.c
char		**split_args(char *command);
//execute/wait.c
int			wait_for_child(int child_pid, int is_last_child);
int			wait_for_children(int children_pid[1024]);
//prompt/prompt.c
char		*get_prompt_str(t_env *s_msenv);
char		*prompt_input(t_env *s_msenv);
//REDIRECTION
//redirection/redirect_heredoc.c
void		redirect_heredoc(char *command, int heredoc_number);
//redirection/redirect_input.c
int			redirect_input(char *command);
//redirectio/redirect_output.c
int			redirect_output(char *command);
//redirection/redirect_utils.c
char		*get_redirect_position(char *str, char redirect_char);
char		get_next_redirect(char *str);
void		redirect_fd(int fd_to_redirect, int fd_location);
void		redirect_fds(int fd_in, int fd_out);
//SYNTAX
//syntax/syntax_utils.c
int			is_invalid_token(char c);
int			unexpected_token(char *input);
int			syntax_error(char *token);
char		*get_next_pipe(char *str);
//syntax/syntax.c
int			starts_with_pipe(char *input);
int			redirect_without_label(char *input);
int			has_empty_pipe(char *input);
int			is_invalid_syntax(char *input);
//UTILS
//utils/arr_len.c
int			ft_arraylen(char **arr);
//utils/array_utils.c
int			ft_arraylen(char **arr);
int			ft_printarray(char **arr);
//utils/error.c
void		print_error_msg(char *command, char *msg);
void		exit_with_error(char *command, char *msg, int error);
void		print_perror_msg(char *command, char *perror_msg);
void		exit_with_perror(char *command, char *perror_msg, int error);
void		print_varname_error_msg(char *command, char *varname);
//utils/ft_atoll.c
long long	ft_atoll(const char *str);
//utils/quote_checker.c
int			ft_check_uquotes(char *str);
//utils/skip_quotes.c
int			ft_skipquotes(char *str);

#endif
