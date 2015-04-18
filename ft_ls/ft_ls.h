/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 21:15:14 by wide-aze          #+#    #+#             */
/*   Updated: 2014/12/13 15:19:47 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <string.h>
# include <dirent.h>

# define ST_MODE(x) ((list->l_stat->st_mode & (x)) == (x))
# define MAJOR(dev) ((int)(((unsigned int)(dev) >> 24) & 0xFF))
# define MINOR(dev) ((int)((dev) & 0xFFFFFF))

typedef struct		s_lopt
{
	char			*rights;
	char			*links;
	char			*usr;
	char			*gp;
	char			*size;
	char			*time;
	char			*linked;
}					t_lopt;

typedef struct		s_read
{
	char			*name;
	char			*path;
	int				was_lnk;
	struct stat		*l_stat;
	struct s_read	*contents;
	t_lopt			*lopt;
	struct s_read	*next;
}					t_read;

void				putstr_with_one_space(char const *s);
void				putstr_l_opt(char const *s, size_t max, char l_or_r);
int					put_options_tab(char **av, int *options);
t_read				*new_elem(char *name);
t_read				*add_elem(t_read *list, char *name);
t_read				**remove_elem(t_read **list, char *name);
t_read				*a_option(t_read *list, int a_option);
t_read				*sort_asc(t_read *list);
t_read				*sort_by_reverse(t_read *list);
t_read				*sort_by_time(t_read *list);
t_read				*give_arg(int ac, char **av);
t_read				*put_l_stat_list(t_read **list, int l_option);
t_read				*put_l_stat_contents(t_read **list);
t_read				*put_minor_major(t_read *list);
void				put_error(char *name);
char				*give_usr(t_read *list);
char				*give_gp(t_read *list);
char				*give_str_time(t_read *list);
char				*give_linked(char *name, char *path);
char				*give_type_and_rights(t_read *list);
void				put_lopt(t_read *list);
int					give_nb_dirs(t_read *list);
int					give_nb_files(t_read *list);
int					check_if_enabled(t_read *list);
void				print_l_option_dir(t_read *list);
void				print_l_option_file(t_read *list, size_t *max);
void				putstr_without_last(char *str);
int					is_last_dir(t_read *list);
char				*give_name(struct dirent *current, int i);
void				print_list(t_read *list);
size_t				*give_max(t_read *list);
size_t				*give_max_files(t_read *list);
void				put_contents(t_read *list);
void				put_path(t_read *list, char *path);
void				apply_options(t_read **list, int *options);
void				if_enabled_no_l(t_read *list, int enabled);
void				if_enabled_l(char *name, int enabled);

#endif
