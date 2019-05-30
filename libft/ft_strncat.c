/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaluko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:10:18 by aaluko            #+#    #+#             */
/*   Updated: 2019/02/24 14:27:51 by aaluko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION: The strncat() function appends not more than n characters
** from s2, and then adds a terminating `\0'. The source and destination
** strings should not overlap, as the behavior is undefined.
** RETURN VALUES: The strcat() and strncat() functions return the pointer s1.
*/

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		len;
	size_t	j;

	j = 0;
	len = (int)ft_strlen(s1);
	while (j < n && *s2)
	{
		s1[len] = *s2;
		j++;
		len++;
		++s2;
	}
	s1[len] = '\0';
	return (s1);
}
