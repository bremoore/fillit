/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 18:41:12 by bmoore            #+#    #+#             */
/*   Updated: 2019/04/24 11:35:50 by aaluko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**d[3]=C, d[4]=D
*/

static void		add_cd(char **board, t_tetri *node, int *num)
{
	char	let;
	int		*d;

	let = node->let;
	d = node->num;
	if (d[3] == 9 || d[3] == 19 || d[3] == 17)
		board[num[2] + 2][num[3]] = let;
	if (d[3] == 19 || d[3] == 10)
		board[num[2] + 2][num[3] + 1] = let;
	if (d[3] == 8 || d[3] == 17)
		board[num[2] + 2][num[3] - 1] = let;
	if (d[4] == 13)
		board[num[2] + 3][num[3]] = let;
	node->row = num[2];
	node->col = num[3] + 1;
}

/*
**this function adds the node to the board by checking its corresponding A-D
**values against the intepretation
**d[1]=A, d[2]=B, num[2]=row, num[3]=col
*/

void			add_node(char **board, t_tetri *node, int *num)
{
	char	let;
	int		*d;

	let = node->let;
	d = node->num;
	node->avail = 0;
	board[num[2]][num[3]] = let;
	if (d[1] == 3 || d[1] == 5 || d[1] == 6 || d[1] == 10)
		board[num[2]][num[3] + 1] = let;
	if (d[1] == 5 || d[1] == 10 || d[1] == 6)
		board[num[2]][num[3] + 2] = let;
	if (d[1] == 10)
		board[num[2]][num[3] + 3] = let;
	if (d[2] != 6 && d[2] != 13 && d[2] != 7 && d[2] != 0)
		board[num[2] + 1][num[3]] = let;
	if (d[2] == 11 || d[2] == 18 || d[2] == 6 || d[2] == 13 || d[2] == 15)
		board[num[2] + 1][num[3] + 1] = let;
	if (d[2] == 18 || d[2] == 13 || d[2] == 7)
		board[num[2] + 1][num[3] + 2] = let;
	if (d[2] == 9 || d[2] == 15 || d[2] == 12)
		board[num[2] + 1][num[3] - 1] = let;
	if (d[2] == 12)
		board[num[2] + 1][num[3] - 2] = let;
	add_cd(board, node, num);
}

/*
**this function checks the list for the next available node and checks if it
**can be placed on the board. if it can, the node is returned else, null is
**returned
**num[2]=row, num[3]=col
*/

static t_tetri	*compare(char **board, int *num, t_tetri *lst)
{
	while (lst)
	{
		if (lst->avail != 0)
			break ;
		lst = lst->next;
	}
	num[2] = lst->row - 1;
	while (board[++num[2]])
	{
		if (lst->row == num[2])
			num[3] = lst->col - 1;
		else if (lst->row < num[2])
			num[3] = -1;
		while (board[num[2]][++num[3]])
		{
			if (board[num[2]][num[3]] == '.')
			{
				if (comp_ad(board, lst, num))
					return (lst);
			}
		}
	}
	lst = NULL;
	return (lst);
}

/*
**this gets the already checked node from compare, and calls the
**add function if the node is not null for its addition to the board.
*/

t_tetri			*get_check(char **board, t_tetri *lst, int *num)
{
	t_tetri		*node;

	if ((node = compare(board, num, lst)))
	{
		add_node(board, node, num);
		return (node);
	}
	return (node);
}
