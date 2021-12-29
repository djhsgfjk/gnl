/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsheev <gsheev@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:16:03 by gsheev            #+#    #+#             */
/*   Updated: 2021/12/27 14:24:03 by gsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_unit	*ft_create_elem(char *piece_of_line, int len)
{
	t_list	*new_elem;

	new_elem = malloc(sizeof(t_unit));
	new_elem->next = (void *)0;
	new_elem->piece_of_line = piece_of_line;
	new_elem->len = len;
	return (new_elem);
}

void	ft_unit_clear(t_unit *begin_list)
{
	if (begin_list != (void *)0 && begin_list->next != (void *)0)
		ft_list_clear(begin_list->next);
	free(begin_list);
}

void	ft_unit_push_back(t_unit **begin_list, char *piece_of_line, int len)
{
	t_list	*new_last;

	new_last = ft_create_elem(piece_of_line, len);
	if (*begin_list != (void *)0)
	{
		while ((*begin_list)->next != (void *)0)
			begin_list = &((*begin_list)->next);
		(*begin_list)->next = new_last;
	}
	else
		*begin_list = new_last;
}
