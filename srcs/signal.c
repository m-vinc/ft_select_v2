/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorvan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 01:10:04 by vmorvan           #+#    #+#             */
/*   Updated: 2017/04/01 04:23:18 by vmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	handle_tstp(void)
{
	t_env	*env;
	char	buf[2];

	env = get_env();
	buf[0] = env->default_settings.c_cc[VSUSP];
	buf[1] = 0;
	tputs(tgetstr("ve", 0), 1, my_out);
	tcsetattr(0, TCSADRAIN, &env->default_settings);
	signal(SIGTSTP, SIG_DFL);
	ioctl(0, TIOCSTI, buf);
	tputs(tgetstr("cl", 0), 1, my_out);
}

void	sig_handler(int n)
{
	t_env	*env;

	env = get_env();
	if (n == SIGINT)
		w_exit(env);
	else if (n == SIGQUIT)
		w_exit(env);
	else if (n == SIGKILL)
		w_exit(env);
	else if (n == SIGTERM)
		w_exit(env);
	else if (n == SIGWINCH)
	{
		tputs(tgetstr("cl", 0), 1, my_out);
		display(*env);
	}
	else if (n == SIGTSTP)
		handle_tstp();
	else if (n == SIGCONT)
	{
		signal(SIGTSTP, sig_handler);
		tputs(tgetstr("cl", 0), 1, my_out);
		enter_dmode();
		display(*env);
	}
}

void	handle_signal(void)
{
	int		x;

	x = 0;
	while (x < 33)
	{
		signal(x, sig_handler);
		x++;
	}
}
