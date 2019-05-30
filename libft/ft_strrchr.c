/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaluko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:00:51 by aaluko            #+#    #+#             */
/*   Updated: 2019/02/20 16:10:36 by aaluko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION: The strchr() function locates the first occurrence of c
** (converted to a char) in the string pointed to by s. The terminating null
** character is considered to be part of the string; therefore if c is `\0',
** the functions locate the terminating `\0'. The strrchr() function is
** identical to strchr(), except it locates the last occurrence of c.
** RETURN VALUES: The functions strchr() and strrchr() return a pointer to
** the located character, or NULL if the character does not appear in the
** string.
*/

char	*ft_strrchr(const char *s, int c)
{
	char	*temp;
	int		i;

	i = 0;
	temp = (char *)s;
	while (*temp)
	{
		i++;
		temp++;
	}
	while (i >= 0)
	{
		if (*temp == (char)c)
			return (temp);
		temp--;
		i--;
	}
	return (NULL);
}
