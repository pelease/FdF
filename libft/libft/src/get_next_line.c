/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 21:25:09 by pelease           #+#    #+#             */
/*   Updated: 2019/10/21 21:25:12 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static void			s_func_buff(const int fd, char **s_cache, char *buff)
{
	char			*link;

	if (s_cache[fd] != NULL)
	{
		link = ft_strjoin(s_cache[fd], buff);
		free(s_cache[fd]);
		s_cache[fd] = link;
	}
	else
		s_cache[fd] = ft_strdup(buff);
}

static int			s_func(char **line, char **s_cache, const int fd)
{
	int				number;
	char			*link;

	number = 0;
	while (s_cache[fd][number] != '\n' && s_cache[fd][number] != '\0')
		number++;
	if (s_cache[fd][number] == '\n')
	{
		*line = ft_strsub(s_cache[fd], 0, number);
		link = ft_strdup(s_cache[fd] + number + 1);
		free(s_cache[fd]);
		s_cache[fd] = link;
		if (s_cache[fd][0] == '\0')
			ft_strdel(&s_cache[fd]);
	}
	else
	{
		*line = ft_strdup(s_cache[fd]);
		ft_strdel(&s_cache[fd]);
	}
	return (1);
}

static int			s_func_main(char **line, const int fd, char **s_cache)
{
	ssize_t			number;
	char			buff[BUFF_SIZE + 1];

	while ((number = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[number] = '\0';
		s_func_buff(fd, s_cache, buff);
		if (ft_strchr(buff, '\n') != NULL)
			return (s_func(line, s_cache, fd));
	}
	if (number < 0)
		return (-1);
	else if (number == 0 && s_cache[fd] == NULL)
		return (0);
	else
		return (s_func(line, s_cache, fd));
}

int					get_next_line(const int fd, char **line)
{
	static char		*s_cache[FD_SIZE];

	if (fd < 0 || fd > FD_SIZE || BUFF_SIZE < 1 || line == NULL)
		return (-1);
	if (s_cache[fd] == NULL)
		return (s_func_main(line, fd, s_cache));
	else
	{
		if (ft_strchr(s_cache[fd], '\n') != NULL)
			return (s_func(line, s_cache, fd));
		else
			return (s_func_main(line, fd, s_cache));
	}
}
