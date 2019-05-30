/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ext_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaluko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 21:35:29 by aaluko            #+#    #+#             */
/*   Updated: 2019/04/24 15:29:43 by aaluko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**this function is used to perform two actions with different values of x
**if x == 0, it is used to initialize each position of the board_array to '.'
**if x == 1, it is used to reset the elements of the given list
**str=a position in the board_array, i=size of str
*/

void	init_str(char *str, t_tetri *lst, int i, int x)
{
	if (x == 0)
	{
		while (--i >= 0)
			str[i] = '.';
	}
	else if (x == 1)
	{
		while (lst)
		{
			lst->avail = 1;
			lst->row = 0;
			lst->col = 0;
			lst = lst->next;
		}
	}
}

/*
**this function is used to creat the board of size i
*/

char	**crt_board(int i)
{
	char	**board;
	int		size;
	t_tetri	*lst;

	lst = NULL;
	size = i;
	board = NULL;
	while (board == NULL)
	{
		if ((board = (char **)malloc(sizeof(char *) * (size + 1))))
		{
			board[size] = NULL;
			while (--size >= 0)
			{
				if ((board[size] = (char *)malloc(sizeof(char) * (i + 1))))
				{
					board[size][i] = '\0';
					init_str(board[size], lst, i, 0);
				}
				else
					++size;
			}
		}
	}
	return (board);
}

/*
**this function prints the board to the standard output.
*/

void	print_board(char **board)
{
	int	i;

	i = -1;
	while (board[++i])
	{
		ft_putstr(board[i]);
		write(1, "\n", 1);
	}
}

/*
**this function calculates the initial size of board from
**the given number of tetrimo
*/

int		board_size(t_tetri *lst, int *num)
{
	int		x;

	x = 2;
	num[1] = 0;
	while (lst)
	{
		++(num[1]);
		lst->pos = num[1];
		lst = lst->next;
	}
	while ((num[1] * 4) > (x * x))
		++x;
	return (x);
}

/*
**this function controls the solving process.
**it increases the board_size if it is too small for a solution
*/

void	ext_fill(t_tetri *lst)
{
	char	**board;
	int		*num;
	int		i;

	i = 1;
	board = NULL;
	num = (int *)ft_memalloc(sizeof(int) * 5);
	num[0] = board_size(lst, num);
	while (1)
	{
		board = crt_board(num[0]);
		if ((solve_tetri(lst, board, num, i)) == 1)
			break ;
		++(num[0]);
		init_str(board[0], lst, 0, 1);
		ft_array_del(board);
		free(board);
	}
	print_board(board);
	free(num);
	ft_array_del(board);
	if (board)
		free(board);
}
