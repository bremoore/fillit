/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaluko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 15:38:23 by aaluko            #+#    #+#             */
/*   Updated: 2019/02/24 13:38:07 by aaluko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
** The memchr() function locates the first occurrence of c (converted
** to an unsigned char) in string s.
** RETURN VALUES: The memchr() function returns a pointer to the byte
** located, or NULL if no such byte exists within n bytes.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_copy;

	s_copy = (unsigned char *)s;
	while (n > 0)
	{
		if (*s_copy == (unsigned char)c)
			return ((void *)s_copy);
		s_copy++;
		n--;
	}
	return (NULL);
}
