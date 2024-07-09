/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykostan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:37:03 by lykostan          #+#    #+#             */
/*   Updated: 2023/02/01 17:37:05 by lykostan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	sjoins(char **s, char *s1)
{
	char	*tmp;

	tmp = ft_strjoin(*s, s1);
	free(*s);
	*s = ft_strdup(tmp, 0, ft_strlen(tmp));
	free(tmp);
}

static void	sdups(char **s, char **str, int i)
{
	char	*tmp;

	*str = ft_strdup(*s, 0, i + 1);
	tmp = ft_strdup(*s, i + 1, ft_strlen(*s) - i - 1);
	free(*s);
	*s = ft_strdup(tmp, 0, ft_strlen(tmp));
	free(tmp);
}

static void	infinity(int fd, char **s)
{
	int			read_size;
	char		s1[BUFFER_SIZE + 1];

	while (1)
	{
		read_size = read(fd, s1, BUFFER_SIZE);
		if (read_size < 0)
		{
			free(*s);
			*s = NULL;
			return ;
		}
		s1[read_size] = 0;
		if (*s)
			sjoins(s, s1);
		else
			*s = ft_strdup(s1, 0, ft_strlen(s1));
		if (ft_strchr(*s, '\n') != -1 || read_size == 0)
			break ;
	}
}

char	*get_next_line(int fd)
{
	char		*str;
	int			i;
	static char	*s;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	infinity(fd, &s);
	if (s == NULL)
		return (NULL);
	i = ft_strchr(s, '\n');
	if (i > -1)
	{
		sdups(&s, &str, i);
		return (str);
	}
	else
	{
		str = ft_strdup(s, 0, ft_strlen(s));
		free(s);
		s = NULL;
		if (*str != 0)
			return (str);
		free(str);
		return (s);
	}
}
