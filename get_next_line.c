/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsheev <gsheev@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:15:59 by gsheev            #+#    #+#             */
/*   Updated: 2021/12/29 19:18:31 by gsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_line	*ft_get_piece_of_line(t_line **last, char	*buff, int n)
{
	int 	i;
	int 	len;
	char	*s;

	i = 0;
	while (i < n && buff[i] != '\n')
		i++;
	if (i < n)
		i++;
	len = i;
	s = (char *)malloc(len * sizeof(char));
	i = 0;
	while (i < len)
	{
		s[i] = buff[i];
		i++;
	}
	(*last)->piece_of_line = s;
	(*last)->len = len;
	return (*last);
}

int ft_end_of_line(char *line, int len)
{
	if (line[len-1] == '\n')
		return (1);
	return (0);
}

t_line	*ft_read_line(int fd, t_line **last)
{
	int 			i;
	char			*buff;
	int 			n;
	t_line			*line;

	line = (void *)0;
	buff = (char *)malloc(BUFFER_SIZE * sizeof(char));
	n = read(fd, buff, BUFFER_SIZE);
	if ((*last)->len > 0)
		line = ft_create_elem((*last)->piece_of_line, (*last)->len);
	else if (n > 0)
	{
		*last = ft_get_piece_of_line(last, buff, n);
		line = ft_create_elem((*last)->piece_of_line, (*last)->len);
		if (ft_end_of_line((*last)->piece_of_line, (*last)->len))
			return (line);
		n = read(fd, buff, BUFFER_SIZE);
	}
	while (n > 0)
	{
		*last = ft_get_piece_of_line(last, buff, n);
		ft_unit_push_back(&line, (*last)->piece_of_line, (*last)->len);
		if (ft_end_of_line((*last)->piece_of_line, (*last)->len))
			return (line);
		n = read(fd, buff, BUFFER_SIZE);
	}
	if (n == 0)
		ft_line_clear(*last);
	return (line);
}

char	*ft_stradd(char **s1, char *s2, int len1, int len2)
{
	int		i;

	if (s1 == (void *)0 || s2 == (void *)0)
		return (*s1);
	i = len1;
	while (i < len1 + len2)
	{
		(*s1)[i] = s2[i - len1];
		i++;
	}
	return (*s1);
}

char	*get_next_line(int fd)
{
	static t_line	*last;
	t_line			*line;
	t_line			*p;
	char			*s;
	int 			len;

	line = ft_read_line(fd, &last);
	if (line == (void *)0)
		return ((char *)0);
	len = 0;
	p = line;
	while (p != (void *)0)
	{
		len += p->len;
		p = p->next;
	}
	s = (char *)malloc(len * sizeof(char));
	p = line;
	while (p != (void *)0)
	{
		s = ft_stradd(&s, p->piece_of_line);
		p = p->next;
	}
	ft_line_clear(line);
	return (s);
}
