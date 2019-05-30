/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaluko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 10:41:36 by aaluko            #+#    #+#             */
/*   Updated: 2019/04/24 11:49:29 by aaluko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**n[2]=row, n[3]=col, d=tetrimino value of D
*/

int			cmp_d(char **b, t_tetri *node, int *n)
{
	int d;

	d = node->num[4];
	if (d == 0)
		return (1);
	if (d == 13)
	{
		if (n[2] + 3 < n[0] && b[n[2] + 3][n[3]] == '.')
			return (1);
	}
	return (0);
}

/*
**n[2]=row, n[3]=col, c=tetrimino value of C
*/

static int	cmp_cd1(char **b, t_tetri *node, int *n)
{
	int	ret;
	int	c;

	ret = 0;
	c = node->num[3];
	if (c == 8 || c == 17)
	{
		if (n[3] - 1 < n[0] && b[n[2] + 2][n[3] - 1] == '.')
			ret = 1;
	}
	if (ret == 1 && c == 17)
	{
		if (b[n[2] + 2][n[3]] != '.')
			return (0);
	}
	if (c == 10)
	{
		if (n[3] + 1 < n[0] && b[n[2] + 2][n[3] + 1] == '.')
			return (1);
	}
	return (ret);
}

/*
**n[2]=row, n[3]=col, c=tetrimino value of C.
*/

int			cmp_cd(char **b, t_tetri *node, int *n)
{
	int	ret;
	int	c;

	ret = 0;
	c = node->num[3];
	if (c == 0)
		return (1);
	if (n[2] + 2 >= n[0])
		return (0);
	if (c == 9 || c == 19)
	{
		if (b[n[2] + 2][n[3]] == '.')
			ret = 1;
	}
	if (ret == 1 && c == 19)
	{
		if (n[3] + 1 >= n[0] || b[n[2] + 2][n[3] + 1] != '.')
			return (0);
	}
	if (c == 8 || c == 17 || c == 10)
		return (cmp_cd1(b, node, n));
	return (ret);
}
