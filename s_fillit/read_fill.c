/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaluko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 22:30:20 by aaluko            #+#    #+#             */
/*   Updated: 2019/04/24 16:24:20 by aaluko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**also checks errors in a given tetrimo
*/

static int		c_error(char **array)
{
	int	i;
	int	j;
	int	g;

	i = -1;
	g = 0;
	while (array[++i])
	{
		j = -1;
		while (array[i][++j])
		{
			if (array[i][j] == '#')
				g++;
		}
	}
	if (g != 4)
	{
		ft_array_del(array);
		write(1, "error\n", 6);
		return (-1);
	}
	return (0);
}

/*
**this function checks for error in each given tetrimo
*/

static	int		error_chk(char **array, int x)
{
	int	i;
	int	y;

	i = -1;
	while (array[++i])
	{
		y = -1;
		while (array[i][++y])
		{
			if (x == 1 || (i < 4 && (array[i][y] != '.' && array[i][y] != '#')))
			{
				ft_array_del(array);
				write(1, "error\n", 6);
				return (-1);
			}
		}
	}
	if (i < 3 || !array[3])
	{
		ft_array_del(array);
		write(1, "error\n", 6);
		return (-1);
	}
	return (c_error(array));
}

/*
**this function calculates A(num[1]), B(num[2]), C(num[3]), D(num[4])
*/

static	void	cont_fill(char *str, int *num, int *i)
{
	num[i[1]] = 0;
	while (*str)
	{
		if (i[2] != 0)
			++(i[2]);
		if (*str == '#')
		{
			if (i[2] == 0)
				++(i[2]);
			num[i[1]] += i[2];
		}
		++str;
	}
}

/*
**this function calls the fuction that calculates the values of A-D of each
**tetrimo if it passes the error check, calls the funtion that adds the
**tetrimino to list and recursively calls for the next tetrimino.
**num[0]=sum, num[1]=a, num[2]=b, num[3]=c, num[4]=d
**i[0]=counter for array, i[1]=counter for num, i[2]=count for the first
**occurance of #
*/

static	int		fill_tetri(char **array, int *ret, t_tetri *lst, int fd)
{
	int		*num;
	int		i[3];

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	ret[3] += 1;
	num = (int *)ft_memalloc(sizeof(int) * 6);
	if (((error_chk(array, 0) == -1) || !num))
		return (-1);
	while ((ft_strchr(array[(i[0])], '#') == NULL))
		++(i[0]);
	while (array[(i[0])])
	{
		++(i[1]);
		cont_fill(array[i[0]], num, i);
		++(i[0]);
	}
	num[0] = num[1] + (2 * num[2]) + (3 * num[3]) + (4 * num[4]);
	ft_array_del(array);
	if (((chk_prty(num[0], num, ret, lst) < 0)) || ret[1] == -1)
		return (error_chk(array, 1));
	if (ret[1] == 0)
		return (0);
	return (read_fill(fd, lst));
}

/*
**this function reads and stores each tetrimo form the file, does some error
**checks.
**ret[0]=counter for array, ret[1]=return fron get_next_line, [3]=letter
*/

int				read_fill(int fd, t_tetri *lst)
{
	char		*array[6];
	char		*line;
	static	int	ret[4];

	ret[2] = -1;
	line = NULL;
	if (ret[3] == 0)
		ret[3] = (int)'A' - 1;
	while (++(ret[2]) < 6)
		array[ret[2]] = NULL;
	while ((ret[1] = get_next_line(fd, &line)) > 0)
	{
		array[ret[0]] = line;
		if ((ret[0] == 4 && ft_strlen(line) != 0) ||
				(ret[0] < 4 && ft_strlen(line) != 4))
		{
			ft_array_del(array);
			write(1, "error\n", 6);
			return (-1);
		}
		if (ret[0] == 4)
			break ;
		++(ret[0]);
	}
	return (fill_tetri(array, ret, lst, fd));
}
