/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaluko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 12:53:03 by aaluko            #+#    #+#             */
/*   Updated: 2019/02/20 14:19:28 by aaluko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION: The strcat() and strncat() functions append a copy of the
** null-terminated string s2 to the end of the null-terminated string s1,
** then add a terminating `\0'. The string s1 must have sufficient space
** to hold the result.
*/

char	*ft_strcat(char *s1, const char *s2)
{
	int		len;
	int		j;

	j = 0;
	len = (int)ft_strlen(s1);
	while (s2[j])
	{
		s1[len + j] = s2[j];
		j++;
	}
	s1[len + j] = '\0';
	return (s1);
}
