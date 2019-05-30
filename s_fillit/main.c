/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:09:38 by bmoore            #+#    #+#             */
/*   Updated: 2019/04/24 11:48:06 by aaluko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**this function displays the usage of the program
*/

void	ft_usage(void)
{
	write(1, "usage: fillit [test_file]", 25);
	write(1, "\n", 1);
}

int		main(int argc, char **argv)
{
	int		fd;
	t_tetri	*lst;

	lst = NULL;
	if (argc == 2)
	{
		fd = 0;
		fd = open(argv[1], O_RDONLY);
		if (fd > -1)
		{
			lst = init_nodes();
			if (read_fill(fd, lst) == 0)
				ext_fill(lst);
			if (close(fd) == -1)
				write(1, "close() error", 13);
		}
		else
			write(1, "open() error", 12);
	}
	else
		ft_usage();
	free_lst(lst);
	return (0);
}
