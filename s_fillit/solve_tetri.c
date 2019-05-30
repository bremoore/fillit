/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaluko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 19:21:06 by aaluko            #+#    #+#             */
/*   Updated: 2019/04/24 11:50:59 by aaluko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**this function is used to perform two actions with different values of j
**if j == 0, it is used to check if all nodes have been used up in lst
**if j == 1, it is used to initialize the values of row and col to 0 for
**nodes with position in the list  greater than value of i;
*/

static int	avail(t_tetri *lst, int i, int j)
{
	while (lst)
	{
		if (j == 0)
		{
			if (lst->avail != 0)
				return (1);
		}
		else
		{
			if (lst->pos > i)
			{
				lst->row = 0;
				lst->col = 0;
			}
		}
		lst = lst->next;
	}
	return (0);
}

/*
**this function removes the given node fffrom the board
**also initialize the availability of the node to 1;
*/

static void	rm_node(t_tetri *node, char **board)
{
	char	let;
	int		col;
	int		row;

	node->avail = 1;
	let = node->let;
	row = node->row - 1;
	while (board[++row])
	{
		col = -1;
		while (board[row][++col])
		{
			if (board[row][col] == let)
				board[row][col] = '.';
		}
	}
}

/*
**this function uses recursion to place each node of the lst on the board and
**backtracks to the last node if the next node cannot be placed successfully
**if the board_size is too small, it returns 0, and it returns 1 on completion.
**num[0]=board_size, num[1]=lst_size,where node was placed, i=1;
*/

int			solve_tetri(t_tetri *lst, char **board, int *num, int i)
{
	t_tetri		*node;

	node = NULL;
	if (!avail(lst, 0, 0))
		return (1);
	while (i <= num[1])
	{
		if ((node = get_check(board, lst, num)) != NULL)
		{
			if (solve_tetri(lst, board, num, i + 1) == 1)
				return (1);
			rm_node(node, board);
			avail(lst, i, num[1]);
		}
		if (node == NULL)
			return (0);
	}
	return (0);
}
