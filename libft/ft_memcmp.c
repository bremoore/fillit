/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaluko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 15:55:13 by aaluko            #+#    #+#             */
/*   Updated: 2019/02/23 19:04:31 by aaluko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
** The memcmp() function compares byte string s1 against byte string s2.
** Both strings are assumed to be n bytes long.
** RETURN VALUES
** The memcmp() function returns zero if the two strings are identical, oth-
** erwise returns the difference between the first two differing bytes
** (treated as unsigned char values, so that `\200' is greater than `\0',
** for example).  Zero-length strings are always identical.  This behavior
** is not required by C and portable code should only depend on the sign of
** the returned value.
*/

static int	m_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s11;
	unsigned char	*s22;

	s11 = (unsigned char*)s1;
	s22 = (unsigned char *)s2;
	while (n != 0)
	{
		if ((*s11 > *s22) || (*s11 < *s22))
			return (*s11 - *s22);
		s11++;
		s22++;
		n--;
	}
	return (0);
}

int			ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s11;
	unsigned char	*s22;
	int				num;

	s11 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
	num = m_strncmp((const char *)s11, (const char *)s22, n);
	return (num);
}
