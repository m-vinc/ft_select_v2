/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorvan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 19:06:41 by vmorvan           #+#    #+#             */
/*   Updated: 2017/03/31 03:42:49 by vmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	enter_dmode()
{
	struct termios term;

	tcgetattr(0, &term);
	term.c_lflag &= ~(ECHO | ICANON);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return ;
}

int		init_term(t_env *env)
{
	char	*estr;

	if ((estr = getenv("TERM")) == 0)
	{
		ft_putendl("please set TERM variable... exiting");
		return (-1);
	}
	if (tgetent(0, estr) != 1)
	{
		ft_putendl("your term is not in the database... exiting");
		return (-1);
	}
	if (isatty(0) != 1)
	{
		ft_putendl("The 0 filedes is not a valid terminal device... exiting");
		return (-1);
	}
	if (tcgetattr(0, &(*env).default_settings) == -1)
	{
		ft_putendl("unable to get attribute... exiting");
		return (-1);
	}
	return (1);
}
t_env	env_initializer()
{
	t_env	env;

	env.search.str = 0;
	env.search.enable = 0;
	env.cursor = 0;
	env.max_row = 0;
	env.max_row = 0;
	env.item = 0;
	return (env);
}
int main(int ac, char **av)
{
	t_env	env;

	env = env_initializer();
	if (init_term(&env) == -1)
		return (-1);
	if (ac > 1)
	{
		tputs(tgetstr("vi", 0), 1, my_out);
		env.item = create_list(ac, av);
		env.cursor = env.item;
		display(env);
		enter_dmode();
		while (1)
		{
			if (env.item->data == 0)
				w_exit(&env);
			h_keystroke(&env);
			display(env);
		}
	}
}




