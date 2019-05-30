/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaluko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 21:00:41 by aaluko            #+#    #+#             */
/*   Updated: 2019/02/24 17:09:58 by aaluko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Description
** Takes as a parameter the address of a string that need to be
** freed with free(3), then sets its pointer to NULL.
** Param. # The string’s address that needs to be freed and its
** pointer set to NULL.
*/

void	ft_strdel(char **as)
{
	if (as)
	{
		if (*as)
		{
			free(*as);
			*as = NULL;
			as = NULL;
		}
	}
}
