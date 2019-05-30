/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaluko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:30:51 by aaluko            #+#    #+#             */
/*   Updated: 2019/02/24 13:27:27 by aaluko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
** The memmove() function copies len bytes from string src to string dst.
** The two strings may overlap; the copy is always done in a non-destructive
** manner.
** RETURN VALUES: The memmove() function returns the original value of dst.
*/

static void	ft_mmemcpy(char *dst, const char *src, size_t n)
{
	while (n != 0)
	{
		*dst = *src;
		src++;
		dst++;
		n--;
	}
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_cpy;
	unsigned char	*temp;

	dst_cpy = (unsigned char *)dst;
	temp = (unsigned char *)malloc(sizeof(unsigned char) * (len + 1));
	if (temp)
	{
		temp[len] = '\0';
		ft_mmemcpy((char *)temp, (const char *)src, len);
		ft_mmemcpy((char *)dst_cpy, (const char *)temp, len);
		free(temp);
		return (dst);
	}
	return (dst);
}
