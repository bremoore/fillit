/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaluko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 17:08:53 by aaluko            #+#    #+#             */
/*   Updated: 2019/02/21 20:43:02 by aaluko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The strnstr() function locates the first occurrence of the null-terminated
** string needle in the string haystack, where not more than len characters
** are searched. Characters that appear after a `\0' character are not
** searched. Since the strnstr() function is a FreeBSD specific API,
** it should only be used when portability is not a concern.
** RETURN VALUES: If needle is an empty string, haystack is returned;
** if needle occurs nowhere in haystack, NULL is returned; otherwise a
** pointer to the first character of the first occurrence of needle
** is returned.
*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*temp;
	char	*hay;
	char	*needley;
	size_t	i;

	if (!(*needle))
		return ((char *)haystack);
	while (len != 0 && *haystack)
	{
		hay = (char *)haystack;
		needley = (char *)needle;
		i = len;
		if (*hay == *needley)
		{
			temp = hay;
			while (*hay && *needley && i-- != 0 && (*(++hay) == *(++needley)))
				;
			if (*needley == '\0')
				return (temp);
		}
		haystack++;
		len--;
	}
	return (NULL);
}
