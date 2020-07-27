/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atuomine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 11:52:20 by atuomine          #+#    #+#             */
/*   Updated: 2019/11/11 13:07:28 by atuomine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		read_file(int fd, char **s)
{
	char	buf[BUFF_SIZE + 1];
	char	*tmp;
	int		ret;

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = ft_strjoin(s[fd], buf);
		ft_strdel(&s[fd]);
		s[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (ret);
}

static int		null_line(char **line)
{
	*line = NULL;
	return (0);
}

static int		create_line(int fd, char **line, char **s, int ret)
{
	char	*tmp;
	size_t	i;

	i = 0;
	if (ret == 0 && s[fd] == NULL)
		return (null_line(line));
	while (s[fd][i] != '\n' && s[fd][i] != '\0')
		i++;
	if (s[fd][i] == '\n')
	{
		*line = ft_strsub(s[fd], 0, i);
		tmp = ft_strdup(&s[fd][i + 1]);
		ft_strdel(&s[fd]);
		s[fd] = tmp;
		if (s[fd][0] == '\0')
			ft_strdel(&s[fd]);
		return (1);
	}
	else
	{
		*line = ft_strsub(s[fd], 0, i);
		ft_strdel(&s[fd]);
		return (1);
	}
}

int				get_next_line(const int fd, char **line)
{
	static char	*s[4864];
	int			result;
	int			ret;

	ret = read_file(fd, &s[fd]);
	if (line == NULL || fd < 0 || ret < 0)
		result = -1;
	else
		result = create_line(fd, line, &s[fd], ret);
	return (result);
}
