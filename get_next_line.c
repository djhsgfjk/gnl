/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsheev <gsheev@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:15:59 by gsheev            #+#    #+#             */
/*   Updated: 2021/12/30 15:11:42 by gsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void ft_rewrite_last(int i, t_piece *last)
{
	int 	j;
	int 	len;
	char	*s;

	len = last->len - i;
	s = (char *)malloc(len * sizeof(char));
	j = 0;
	while (i < last->len)
	{
		s[j] = last->s[i];
		j++;
		i++;
	}
	free(last->s);
	last->s = s;
	last->len = len;
}

static t_piece	*ft_get_piece_of_line(t_piece *buff)
{
	int 	i;
	int 	len;
	char	*s;
	t_piece *piece;

	i = 1;
	while (i < buff->len && buff->s[i-1] != '\n')
		i++;
	len = i;
	s = (char *)malloc(len * sizeof(char));
	i = 0;
	while (i < len)
	{
		s[i] = buff->s[i];
		i++;
	}
	piece = ft_create_piece_elem(s, len);
	if (buff->s[len-1] == '\n')
		ft_rewrite_last(i, buff);
	return (piece);
}

static t_line	*ft_read_line(int fd)
{
	static t_piece	*buff;
	t_piece	*piece;
	t_line	*line;

	line = (void *) 0;
	line = ft_create_line_elem(ft_get_piece_of_line(buff));
	if (line->piece->len > 0)
		if (line->piece->s[line->piece->len-1] == '\n')
			return (line);
	ft_piece_clear(buff);
	buff->s = (char *) malloc( BUFFER_SIZE * sizeof(char));
	buff->len = read(fd, buff->s, BUFFER_SIZE);
	while (buff->len > 0)
	{
		piece = ft_get_piece_of_line(buff);
		ft_line_push_back(&line, piece);
		if (piece->len > 0)
			if (piece->s[piece->len-1] == '\n')
				return (line);
		buff->len = read(fd, buff->s, BUFFER_SIZE);
	}
	if (buff->len <= 0)
		ft_piece_clear(buff);
	return (line);
}

static void ft_str_add(char **s1, char *s2, int len1, int len2)
{
	int		i;

	if (*s1 == (void *)0 || s2 == (void *)0)
		return ;
	i = len1;
	while (i < len1 + len2)
	{
		(*s1)[i] = s2[i - len1];
		i++;
	}
}

char	*get_next_line(int fd)
{
	t_line			*line;
	t_line			**p;
	char			*s;
	int 			len;

	line = ft_read_line(fd);
	if (line == (void *)0)
		return ((char *)0);
	len = 0;
	p = &line;
	while (*p != (void *)0)
	{
		len += (*p)->piece->len;
		(*p) = (*p)->next;
	}
	s = (char *)malloc(len * sizeof(char));
	p = &line;
	while (*p != (void *)0)
	{
		ft_str_add(&s, (*p)->piece->s, len, (*p)->piece->len);
		(*p) = (*p)->next;
	}
	ft_line_clear(line);
	return (s);
}
