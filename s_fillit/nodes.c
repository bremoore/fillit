/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:51:03 by bmoore            #+#    #+#             */
/*   Updated: 2019/04/24 11:50:38 by aaluko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

/*
**this function is used to free the malloced list.
*/

void		free_lst(t_tetri *lst)
{
	t_tetri	*temp;

	if (lst)
	{
		temp = NULL;
		while (lst)
		{
			temp = lst;
			if (temp->num)
				free(temp->num);
			lst = lst->next;
			free(temp);
		}
	}
}

/*
**this function is used to malloc for each node of the list
*/

t_tetri		*init_nodes(void)
{
	t_tetri *lst;

	lst = NULL;
	if ((lst = (t_tetri *)ft_memalloc(sizeof(t_tetri))))
	{
		lst->num = NULL;
		lst->avail = 0;
		lst->row = 0;
		lst->col = 0;
		lst->pos = 0;
		lst->next = NULL;
	}
	return (lst);
}
