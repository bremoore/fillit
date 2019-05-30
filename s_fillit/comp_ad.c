/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaluko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 20:33:09 by aaluko            #+#    #+#             */
/*   Updated: 2019/04/24 11:46:39 by aaluko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**n[2]=row, n[3]=col, b=board, bee=tetrimino value of B
*/

static int	cmp_b2(char **b, t_tetri *node, int *n)
{
	int	ret;
	int	bee;

	ret = 0;
	bee = node->num[2];
	if (bee == 0)
		return (1);
	if (n[2] + 1 >= n[0])
		return (0);
	if (bee == 6 || bee == 13)
	{
		if (n[3] + 1 < n[0] && b[n[2] + 1][n[3] + 1] == '.')
			ret = 1;
	}
	if (ret == 1 && bee == 13)
	{
		if (n[3] + 2 >= n[0] || b[n[2] + 1][n[3] + 2] != '.')
			return (0);
	}
	if (bee == 7)
	{
		if (n[3] + 2 < n[0] || b[n[2] + 1][n[3] + 2] == '.')
			return (1);
	}
	return (ret);
}

/*
**n[2]=row, n[3]=col, b=board, bee=tetrimino value of B
*/

static int	cmp_b1(char **b, t_tetri *node, int *n)
{
	int	ret;
	int	bee;

	ret = 0;
	bee = node->num[2];
	if (bee == 9 || bee == 12 || bee == 15)
	{
		if (n[2] + 1 < n[0] && n[3] - 1 >= 0 && \
		b[n[2] + 1][n[3] - 1] == '.' && b[n[2] + 1][n[3]] == '.')
			ret = 1;
	}
	if (ret == 1 && (bee == 15))
	{
		if (n[3] + 1 >= n[0] || b[n[2] + 1][n[3] + 1] != '.')
			return (0);
	}
	if (ret == 1 && bee == 12)
	{
		if (n[3] - 2 < 0 || b[n[2] + 1][n[3] - 2] != '.')
			return (0);
	}
	if (bee == 6 || bee == 13 || bee == 7 || bee == 0)
		return (cmp_b2(b, node, n));
	return (ret);
}

/*
**n[2]=row, n[3]=col, b=board, bee=tetrimino value of B
*/

static int	cmp_b(char **b, t_tetri *node, int *n)
{
	int	ret;
	int	bee;

	ret = 0;
	bee = node->num[2];
	if (bee == 5 || bee == 11 || bee == 18)
	{
		if (n[2] + 1 < n[0] && b[n[2] + 1][n[3]] == '.')
			ret = 1;
	}
	if (ret == 1 && (bee == 11 || bee == 18))
	{
		if (n[3] + 1 >= n[0] || b[n[2] + 1][n[3] + 1] != '.')
			return (0);
	}
	if (ret == 1 && bee == 18)
	{
		if (n[3] + 2 >= n[0] || b[n[2] + 1][n[3] + 2] != '.')
			return (0);
	}
	if (bee == 9 || bee == 12 || bee == 15 || bee == 6 \
	|| bee == 13 || bee == 7 || bee == 0)
		return (cmp_b1(b, node, n));
	return (ret);
}

/*
**n[2]=row, n[3]=col, b=board, a=tetrimino value of A
*/

static int	cmp_a(char **b, t_tetri *node, int *num)
{
	int	a;

	a = node->num[1];
	if (a == 1)
		return (1);
	else if (a == 3)
	{
		if (num[3] + 1 < num[0] && b[num[2]][num[3] + 1] == '.')
			return (1);
	}
	else if (a == 6)
	{
		if (num[3] + 1 < num[0] && b[num[2]][num[3] + 1] == '.' \
		&& num[3] + 2 < num[0] && b[num[2]][num[3] + 2] == '.')
			return (1);
	}
	else if (a == 10)
	{
		if (num[3] + 1 < num[0] && b[num[2]][num[3] + 1] == '.' && \
		num[3] + 2 < num[0] && b[num[2]][num[3] + 2] == '.' && \
		num[3] + 3 < num[0] && b[num[2]][num[3] + 3] == '.')
			return (1);
	}
	return (0);
}

/*
**n is use to measure the hight of the tetrimo by checking if
**abcd[2-4] is available or not
**abcd[1]=B, abcd[2]=c, abcd[3]=D
**cmp_a, cmp_b, cmp_cd, cmp_d are checking the availability of
**a position on the board in relation to the values of abcd of
**a tetrimo.
*/

int			comp_ad(char **board, t_tetri *node, int *num)
{
	int	n[3];
	int	*abcd;

	n[0] = 0;
	n[1] = 0;
	n[2] = 0;
	abcd = node->num;
	if (abcd[2])
		n[0] = 1;
	if (abcd[3])
		n[1] = 1;
	if (abcd[4])
		n[2] = 1;
	if ((n[0] + n[1] + n[2] + num[2]) >= num[0])
		return (0);
	if (!cmp_a(board, node, num) || !cmp_b(board, node, num) \
	|| !cmp_cd(board, node, num) || !cmp_d(board, node, num))
		return (0);
	return (1);
}
