/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell1.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 17:50:04 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/30 09:59:01 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL1_H
# define FT_MINISHELL1_H

# include <dirent.h>

//sgdd
# include "libft/includes/ft_debug.h"

typedef struct	s_sh
{
	char		**cmd;
	char		**env;
	char		*path_cmd;
}				t_sh;

void			print_error_bad_cmd(char *cmd, int ret);
void			init_struct_sh(t_sh *sh);
void			init_after_gnl(t_sh *sh, char *line);
char			*search_in_envp(t_sh *sh, char *str);
char			*search_in_chartab(char **tab, char *str);
int				check_the_cmd(t_sh *sh);
void			cmd_detected(t_sh *sh);
int				bdin_detected(t_sh *sh);
int				bdin_cd(t_sh *sh);
int				bdin_chdir(t_sh *sh);
int				bdin_setenv(t_sh *sh);
int				bdin_unsetenv(t_sh *sh);
int				bdin_env(t_sh *sh);
int				bdin_pwd(t_sh *sh);
int				bdin_echo(t_sh *sh);
int				bdin_exit(char *signal);
void			print_error_cant_exec(char *cmd);
int				check_file_rights(char *path);
void			print_error_lstat(char *cmd, int error);
char			*pwd_without_end(t_sh *sh);
char			*pwd_with_end(t_sh *sh);
int				check_the_path(t_sh *sh, char *str);
void			print_error_path_access(char *cmd, int error);
t_sh			*manage_shlvl(t_sh *sh);
int				check_env_cmd(char **newenv, char *cmd);
int				check_the_cmd(t_sh *sh);
void			check_if_pwd(t_sh *sh);
void			print_error_signal(const char *str_sig, int nb_sig);

#endif
