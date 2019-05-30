/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaluko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 20:19:06 by aaluko            #+#    #+#             */
/*   Updated: 2019/02/21 19:35:41 by aaluko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION: The strcmp() functions lexicographically compare
** the null-terminated strings s1 and s2.
** RETURN VALUES: The strcmp() functions return an integer
** greater than, equal to, or less than 0, according as the string s1 is
** greater than, equal to, or less than the string s2. The comparison is done
** using unsigned characters, so that `\200' is greater than `\0'.
*/

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*s11;
	unsigned char	*s22;

	s11 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
	while (*s11 || *s22)
	{
		if (*s11 > *s22)
			return (*s11 - *s22);
		else if (*s11 < *s22)
			return (*s11 - *s22);
		s11++;
		s22++;
	}
	return (0);
}
