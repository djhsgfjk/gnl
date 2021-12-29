/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsheev <gsheev@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:16:07 by gsheev            #+#    #+#             */
/*   Updated: 2021/12/29 18:31:21 by gsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE = 1000

typedef struct s_line
{
	struct s_line	*next;
	char			*piece_of_line;
	int				len;
}	t_line;

char	*get_next_line(int fd);
t_line	*ft_create_elem(char *piece_of_line, int len);
void	ft_line_clear(t_line *begin_list);
void	ft_line_push_back(t_line **begin_list, char *piece_of_line, int len);

#endif
