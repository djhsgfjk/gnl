/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsheev <gsheev@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:16:03 by gsheev            #+#    #+#             */
/*   Updated: 2021/12/30 17:26:11 by gsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_piece	*ft_create_piece_elem(char *s, int len)
{
	t_piece	*new_elem;

	new_elem = (t_piece *)malloc(sizeof(t_piece));
	new_elem->s = s;
	new_elem->len = len;
	return (new_elem);
}

void	ft_piece_clear(t_piece *piece)
{
	if (piece == (void *)0)
		return ;
	free(piece->s);
	free(piece);
}

t_line	*ft_create_line_elem(t_piece *piece)
{
	t_line	*new_elem;

	new_elem = malloc(sizeof(t_line));
	new_elem->next = (void *)0;
	new_elem->piece = piece;
	return (new_elem);
}

void	ft_line_clear(t_line *line)
{
	if (line != (void *)0 && line->next != (void *)0)
		ft_line_clear(line->next);
	if (line == (void *)0)
		return ;
	ft_piece_clear(line->piece);
	free(line);
}

void	ft_line_push_back(t_line **line, t_piece *piece)
{
	t_line	*new_last;

	new_last = ft_create_line_elem(piece);
	if (*line!= (void *)0)
	{
		while ((*line)->next != (void *)0)
			line = &((*line)->next);
		(*line)->next = new_last;
	}
	else
		*line = new_last;
}
