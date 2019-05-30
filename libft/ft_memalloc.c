/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaluko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:30:14 by aaluko            #+#    #+#             */
/*   Updated: 2019/02/20 14:10:45 by aaluko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Description
** Allocates (with malloc(3)) and returns a “fresh” memory area.
** The memory allocated is initialized to 0. If the alloca- tion
** fails, the function returns NULL.
** Param. #1 The size of the memory that needs to be allocated.
** Return value: The allocated memory area.
*/

void	*ft_memalloc(size_t size)
{
	void	*pnt;
	char	*chapn;

	pnt = (void *)malloc(sizeof(void) * size);
	if (pnt)
	{
		chapn = (char *)pnt;
		while (size != 0)
		{
			*chapn = '\0';
			chapn++;
			size--;
		}
		return (pnt);
	}
	return (NULL);
}
