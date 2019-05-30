/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_prty.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaluko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:21:26 by aaluko            #+#    #+#             */
/*   Updated: 2019/04/24 11:46:19 by aaluko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**this function initializes the elements of the added node to the values of
**the corresponding terimino.
*/

static	int	ft_qty(t_tetri *lst, int *ret, int *num)
{
	int		i;

	i = 0;
	while (lst)
	{
		if (lst->avail == 0)
		{
			i++;
			lst->let = (char)ret[3];
			lst->avail = 1;
			lst->num = num;
		}
		if (i == 0 && !lst->next)
			lst->next = init_nodes();
		lst = lst->next;
	}
	i = -1;
	while (++i < 3)
	{
		if (i != 1)
			ret[i] = 0;
	}
	return (0);
}

static	int	chk_prty3(int sum, int *num)
{
	int prty;

	prty = 0;
	if (sum == 25)
	{
		if (num[1] == 3)
			prty = 3;
		else if (num[1] == 1)
			prty = 19;
	}
	else
	{
		prty = -1;
		free(num);
	}
	return (prty);
}

static	int	chk_prty2(int sum, int *num)
{
	int	prty;

	prty = 0;
	if (sum == 53)
		prty = 11;
	else if (sum == 45)
		prty = 12;
	else if (sum == 29)
		prty = 13;
	else if (sum == 43)
		prty = 14;
	else if (sum == 21)
		prty = 15;
	else if (sum == 31)
		prty = 16;
	else if (sum == 46)
		prty = 17;
	else if (sum == 62)
		prty = 18;
	else
		prty = chk_prty3(sum, num);
	return (prty);
}

/*
**this function serves as the final error check for a valid tetrimino by
**checking the value of its sum(sum = 1*A + 2*B + 3*C + 4*D) against
**already determined values for all 19 valid tetriminos.
**sum=num[0]
*/

int			chk_prty(int sum, int *num, int *ret, t_tetri *lst)
{
	int prty;

	prty = 0;
	if (sum == 90)
		prty = 1;
	else if (sum == 10)
		prty = 2;
	else if (sum == 40)
		prty = 4;
	else if (sum == 50)
		prty = 5;
	else if (sum == 68)
		prty = 6;
	else if (sum == 16)
		prty = 7;
	else if (sum == 18)
		prty = 8;
	else if (sum == 20)
		prty = 9;
	else if (sum == 37)
		prty = 10;
	else if (((prty = chk_prty2(sum, num)) < 0))
		return (-1);
	ft_qty(lst, ret, num);
	return (0);
}
