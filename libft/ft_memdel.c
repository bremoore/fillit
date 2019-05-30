/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaluko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 19:46:47 by aaluko            #+#    #+#             */
/*   Updated: 2019/02/24 16:21:05 by aaluko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Description
** Takes as a parameter the address of a memory area that needs to be
** freed with free(3), then puts the pointer to NULL.
** Param. #1 A pointer’s address that needs its memory freed and set to NULL.
*/

void	ft_memdel(void **ap)
{
	unsigned char	**copy;

	if (ap)
	{
		copy = (unsigned char **)ap;
		if (*copy)
		{
			free(*copy);
			*copy = NULL;
			ap = NULL;
			copy = NULL;
		}
	}
}
