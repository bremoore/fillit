/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaluko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 17:24:56 by aaluko            #+#    #+#             */
/*   Updated: 2019/03/01 16:34:33 by aaluko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION: strlcat() appends string src to the end of dst. It will
** append at most dstsize - ft_strlen(dst) - 1 characters. It will then NUL-
** terminate, unless dstsize is 0 or the original dst string was longer than
** dstsize (in practice this should not happen as it means that either
** dstsize is incorrect or that dst is not a proper string). If the src and
** dst strings overlap, the behavior is undefined.
** RETURN VALUES: functions return the total length of the string they tried
** to create. For strlcat() the means the initial length of dst plus the
** length of src. If the return value is >= dstsize, the output string has
** been truncated. It is the caller's responsibility to handle this.
*/

static size_t	strlen_lcat(char *dst, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (i < dstsize && *dst)
	{
		++dst;
		i++;
	}
	return (i);
}

size_t			ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dlen;
	size_t	j;
	size_t	slen;
	int		copylen;

	j = dstsize;
	slen = ft_strlen(src);
	if ((strlen_lcat(dst, dstsize) < dstsize) && dstsize != 0)
	{
		dlen = ft_strlen(dst);
		while (--dstsize > 0 && *dst)
			dst++;
		copylen = (int)(j - dlen);
		while (--(copylen) > 0 && *src)
		{
			*dst = *src;
			dst++;
			src++;
		}
		*dst = '\0';
		return (dlen + slen);
	}
	return (dstsize + slen);
}
