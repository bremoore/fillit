/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaluko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 20:20:09 by aaluko            #+#    #+#             */
/*   Updated: 2019/02/23 19:02:05 by aaluko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION: The strncmp() functions lexicographically compares not more
** than n characters. Because strncmp() is designed for comparing strings
** rather than binary data, characters that appear after a `\0' character
** are not compared.
** RETURN VALUES: The strncmp() functions return an integer greater than,
** equal to, or less than 0, according as the string s1 is greater than,
** equal to, or less than the string s2. The comparison is done using
** unsigned characters, so that `\200' is greater than `\0'.
*/

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s11;
	unsigned char	*s22;

	s11 = (unsigned char*)s1;
	s22 = (unsigned char *)s2;
	while ((*s11 || *s22) && n != 0)
	{
		if ((*s11 > *s22) || (*s11 < *s22))
			return (*s11 - *s22);
		s11++;
		s22++;
		n--;
	}
	return (0);
}
