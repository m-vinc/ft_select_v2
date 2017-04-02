/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorvan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:15:20 by vmorvan           #+#    #+#             */
/*   Updated: 2017/04/02 01:53:24 by vmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include <unistd.h>
# include "../libft/libft.h"
# include <termios.h>
# include <sys/ioctl.h>
# include <term.h>
# include <curses.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <time.h>
# include <grp.h>
# include <pwd.h>
# include <uuid/uuid.h>
# define RIGHT_ARROW 'C'
# define LEFT_ARROW 'D'
# define DOWN_ARROW 'B'
# define UP_ARROW 'A'

typedef struct	s_option
{
	char			*data;
	uint8_t			selected;
	uint8_t			hover;
	int				finded;
	struct s_option *prev;
	struct s_option	*next;
}				t_option;

typedef struct	s_sopt
{
	t_option		*opt;
	struct s_sopt	*origin;
	struct s_sopt	*next;
}				t_sopt;

typedef struct	s_search
{
	char			*str;
	uint8_t			enable;
	struct s_sopt	*list;
}				t_search;

typedef struct	s_env
{
	struct termios	default_settings;
	int				max_row;
	int				max_col;
	t_search		search;
	t_option		*item;
	t_option		*cursor;
}				t_env;

typedef struct	s_sz
{
	int	col;
	int	row;
}				t_sz;
t_option	*create_list(int ac, char **av);
t_option	*option_initializer();
t_sopt		*sopt_initializer(t_sopt *origin);
void		free_sopt(t_env *env);
void		delete_list(t_env *env);
t_env		env_initializer();
void		enter_dmode();
int			init_term(t_env *env);
t_env		get_max(t_env env);
t_option	*get_last(t_option *list);
void		display(t_env env);
void		display_detail(t_env env, int *y);
void		display_word(t_env env);
void		display_searchbar(t_env env, t_sz sz);
void		display_col(t_env env, t_sz sz, int *position);
int			my_out(int c);
void		h_keystroke(t_env *env);
void		place_search_cursor(t_env *env);
void		search_add(t_env *env, char *buf);
void		search_backspace(t_env *env);
void		search_find(t_env *env);
void		search_reset(t_env *env);
void		search_create(t_env *env);
char		*ft_strjoinf(char *one, char *two);
t_option	*remove_option(t_option *save, char *data);
void		w_exit(t_env *env);
void		select_cursor(t_env *env);
void		move_cursor(int dir, t_env *env);
void		move_search_cursor(t_env *env);
t_env		*get_env();
void		handle_signal();
void		sig_handler(int n);
void		submit(t_env *env);
int			get_row_usage(t_env *env, t_sz sz);
void		infomark(t_env *env);
void		showfirst(struct stat info, char **f);
void		showright(struct stat info, char **f);
void		shownumberinfo(struct stat info, char **f);
void		showtime(struct stat info, char **f);
void		show_info(struct stat info, t_env *env);
void		addtime(char **time, char **f);
void		print_info(t_env *env);
t_sz		getsz();
void		show_info(struct stat info, t_env *env);
void		no_needed_row(t_sz sz, t_env *env, int *position);
void		build_strinfo(struct stat info, char **strinfo);
#endif
