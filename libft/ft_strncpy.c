/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaluko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 10:44:24 by aaluko            #+#    #+#             */
/*   Updated: 2019/02/24 17:41:28 by aaluko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The stpncpy() and strncpy() functions copy at most len characters from src
** into dst. If src is less than len characters long, the remainder of dst is
** filled with `\0' characters. Otherwise, dst is not terminated.
** The source and destination strings should not overlap, as the behavior is
** undefined.
*/

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		if (src[i] == '\0' && i < len)
		{
			while (i < len)
			{
				dst[i] = '\0';
				i++;
			}
			return (dst);
		}
		dst[i] = src[i];
		i++;
	}
	return (dst);
}
