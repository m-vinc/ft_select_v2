/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorvan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 01:45:18 by vmorvan           #+#    #+#             */
/*   Updated: 2017/04/02 01:51:16 by vmorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	showfirst(struct stat info, char **f)
{
	if (S_ISREG(info.st_mode))
		*f = ft_strjoinf(*f, "-");
	if (S_ISDIR(info.st_mode))
		*f = ft_strjoinf(*f, "d");
	if (S_ISCHR(info.st_mode))
		*f = ft_strjoinf(*f, "c");
	if (S_ISBLK(info.st_mode))
		*f = ft_strjoinf(*f, "b");
	if (S_ISFIFO(info.st_mode))
		*f = ft_strjoinf(*f, "p");
	if (S_ISLNK(info.st_mode))
		*f = ft_strjoinf(*f, "l");
	if (S_ISSOCK(info.st_mode))
		*f = ft_strjoinf(*f, "s");
	if (S_ISWHT(info.st_mode))
		*f = ft_strjoinf(*f, "D");
}

void	showright(struct stat info, char **f)
{
	*f = ft_strjoinf(*f, (info.st_mode & S_IRUSR) ? "r" : "-");
	*f = ft_strjoinf(*f, (info.st_mode & S_IWUSR) ? "w" : "-");
	*f = ft_strjoinf(*f, (info.st_mode & S_IXUSR) ? "x" : "-");
	*f = ft_strjoinf(*f, (info.st_mode & S_IRGRP) ? "r" : "-");
	*f = ft_strjoinf(*f, (info.st_mode & S_IWGRP) ? "w" : "-");
	*f = ft_strjoinf(*f, (info.st_mode & S_IXGRP) ? "x" : "-");
	*f = ft_strjoinf(*f, (info.st_mode & S_IROTH) ? "r" : "-");
	*f = ft_strjoinf(*f, (info.st_mode & S_IWOTH) ? "w" : "-");
	*f = ft_strjoinf(*f, (info.st_mode & S_IXOTH) ? "x  " : "-  ");
}

void	shownumberinfo(struct stat info, char **f)
{
	char			*tmp;
	struct passwd	*pwd;
	struct group	*grp;

	grp = getgrgid(info.st_gid);
	pwd = getpwuid(info.st_uid);
	tmp = ft_itoa(info.st_nlink);
	*f = ft_strjoinf(*f, tmp);
	free(tmp);
	*f = ft_strjoinf(*f, " ");
	*f = ft_strjoinf(*f, pwd->pw_name);
	*f = ft_strjoinf(*f, "  ");
	*f = ft_strjoinf(*f, grp->gr_name);
	tmp = ft_itoa(info.st_size);
	*f = ft_strjoinf(*f, "  ");
	if (tmp != 0)
		*f = ft_strjoinf(*f, tmp);
	free(tmp);
	*f = ft_strjoinf(*f, " ");
}

void	showtime(struct stat info, char **f)
{
	char	**time;
	int		e;
	char	**s;
	char	**hour;

	e = 0;
	time = ft_strsplit(ctime(&info.st_ctime), ' ');
	*f = ft_strjoinf(*f, time[1]);
	*f = ft_strjoinf(*f, "  ");
	*f = ft_strjoinf(*f, time[2]);
	*f = ft_strjoinf(*f, " ");
	hour = ft_strsplit(time[3], ':');
	addtime(hour, f);
	free(hour);
	s = time;
	while (time[e] != 0)
	{
		free(time[e]);
		e++;
	}
	if (time[e])
		free(time[e]);
	if (s)
		free(s);
}

void	addtime(char **time, char **f)
{
	int	c;

	c = 0;
	*f = ft_strjoinf(*f, time[0]);
	*f = ft_strjoinf(*f, ":");
	*f = ft_strjoinf(*f, time[1]);
	while (time[c] != 0)
	{
		free(time[c]);
		c++;
	}
}
