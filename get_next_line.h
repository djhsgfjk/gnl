/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsheev <gsheev@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:16:07 by gsheev            #+#    #+#             */
/*   Updated: 2021/12/30 17:53:12 by gsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_piece
{
	char	*s;
	int		len;
}	t_piece;


typedef struct s_line
{
	struct s_line	*next;
	t_piece			*piece;
}	t_line;

char	*get_next_line(int fd);
t_piece	*ft_create_piece_elem(char *piece_of_line, int len);
void	ft_piece_clear(t_piece *piece);
t_line	*ft_create_line_elem(t_piece *piece);
void	ft_line_clear(t_line *line);
void	ft_line_push_back(t_line **line, t_piece *piece);

#endif
