/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaluko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:12:24 by aaluko            #+#    #+#             */
/*   Updated: 2019/03/31 21:16:56 by aaluko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** returns 1 after copying a newline
** returns 0 after reading the whole fd
** returns -1 on getting an error
*/

int		ft_newline(int ret, char **temp_buff, char **line, const int fd)
{
	int			i;
	char		*temp;
	char		*p_temp;

	i = 0;
	while (temp_buff[fd][i] != '\n' && temp_buff[fd][i] != '\0')
		i++;
	if (temp_buff[fd][i] == '\n')
	{
		*line = ft_strsub(temp_buff[fd], 0, i);
		p_temp = ft_strchr(temp_buff[fd], '\n');
		temp = ft_strdup(++p_temp);
		ft_strdel(&temp_buff[fd]);
		temp_buff[fd] = temp;
		if (temp_buff[fd][0] == '\0')
			ft_strdel(&temp_buff[fd]);
	}
	else if (temp_buff[fd][i] == '\0')
	{
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(temp_buff[fd]);
		ft_strdel(&temp_buff[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	int			ret;
	char		buff[BUFF_SIZE + 1];
	static char	*temp_buff[4865];
	char		*temp;

	ft_bzero(buff, BUFF_SIZE + 1);
	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, (void *)buff, BUFF_SIZE)) > 0)
	{
		if (temp_buff[fd] == NULL)
			temp_buff[fd] = ft_strnew(1);
		temp = ft_strjoin(temp_buff[fd], buff);
		ft_bzero(buff, BUFF_SIZE + 1);
		ft_strdel(&temp_buff[fd]);
		temp_buff[fd] = temp;
		if (ft_strchr(temp_buff[fd], '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (temp_buff[fd] == NULL || temp_buff[fd][0] == '\0'))
		return (0);
	else
		return (ft_newline(ret, temp_buff, line, fd));
}
