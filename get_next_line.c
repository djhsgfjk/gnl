/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsheev <gsheev@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:15:59 by gsheev            #+#    #+#             */
/*   Updated: 2021/12/27 15:14:14 by gsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//char	*ft_clear_buff(char	*buff, int i, int j) //чистка буффера в интервале [i, j)
//{
//	while (i < j)
//	{
//		buff[i] = '\0';
//		i++;
//	}
//	return (buff);
//}

//int	ft_check_buff(char *buff)
//{
//	int		i;
//	int 	j;
//
//	i = 0;
//	while (i < BUFFER_SIZE)
//	{
//		if (buff[i] == '\n')
//			break;
//		i++;
//	}
//	if (i < BUFFER_SIZE - 1)
//		return (i+1);
//	return (BUFFER_SIZE);
//}

t_unit	*ft_first_piece_of_line(char *buff, int stop, int len)
{
	char *piece_of_line;

	if (stop >= BUFFER_SIZE)
		return (ft_create_elem((void *)0, 0));
	piece_of_line = malloc(len - stop + 1);
	return (ft_create_elem(&(buff[stop+1]), BUFFER_SIZE-stop));


}

char	*ft_get_piece_of_line(char	*buff, int len)
{
	int i;

	i = 0
	while(i < len && buff[i] != '\n')

}

char	*get_next_line(int fd)
{
	int 		i;
	static char	*buff;
	static int 	stop;
	int 		n;
	t_unit		*line;

	line = ft_first_piece_of_line(buff, stop, BUFFER_SIZE);
	buff = malloc(BUFFER_SIZE * sizeof(char));
	n = read(fd, buff, BUFFER_SIZE);
	while (n > 0)
	{
		ft_unit_push_back(line, ft_get_piece_of_line(buff, BUFFER_SIZE));

		n = read(fd, buff, BUFFER_SIZE);
	}
	stop = line

}