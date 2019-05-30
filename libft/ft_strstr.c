/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaluko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:37:51 by aaluko            #+#    #+#             */
/*   Updated: 2019/02/21 20:43:16 by aaluko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION: The strstr() function locates the first occurrence of the
** null-terminated string needle in the null-terminated string haystack.
** RETURN VALUES: If needle is an empty string, haystack is returned; if
** needle occurs nowhere in haystack, NULL is returned; otherwise a
** pointer to the first character of the first occurrence of needle is
** returned.
*/

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*temp;
	char	*hay;
	char	*needley;

	if (!(*needle))
		return ((char *)haystack);
	while (*haystack)
	{
		hay = (char *)haystack;
		needley = (char *)needle;
		if (*hay == *needley)
		{
			temp = hay;
			while (*hay && *needley && (*(++hay) == *(++needley)))
				;
			if (*needley == '\0')
				return (temp);
		}
		haystack++;
	}
	return (NULL);
}
