/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaluko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 12:16:44 by aaluko            #+#    #+#             */
/*   Updated: 2019/02/23 20:57:20 by aaluko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
** The memccpy() function copies bytes from string src to string dst.  If
** the character c (as converted to an unsigned char) occurs in the string
** src, the copy stops and a pointer to the byte after the copy of c in the
** string dst is returned.  Otherwise, n bytes are copied, and a NULL
** pointer is returned. The source and destination strings should not over
** lap, as the behavior is undefined.
*/

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dst_cpy;
	unsigned char	*src_cpy;

	dst_cpy = (unsigned char *)dst;
	src_cpy = (unsigned char *)src;
	while (n != 0)
	{
		if (*src_cpy == (unsigned char)c)
		{
			*dst_cpy = *src_cpy;
			return ((void *)(++dst_cpy));
		}
		*dst_cpy = *src_cpy;
		dst_cpy++;
		src_cpy++;
		n--;
	}
	return (NULL);
}
