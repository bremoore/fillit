/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaluko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 13:18:08 by aaluko            #+#    #+#             */
/*   Updated: 2019/02/24 17:00:04 by aaluko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates (with malloc(3)) and returns a “fresh” substring
** from the string given as argument. The substring begins at
** indexstart and is of size len. If start and len aren’t refering
** to a valid substring, the behavior is undefined. If the
** allocation fails, the function returns NULL
*/

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;

	if (s)
	{
		i = 0;
		substr = (char *)malloc(sizeof(*s) * len + 1);
		if (substr)
		{
			while (len--)
			{
				substr[i] = s[start + i];
				i++;
			}
			substr[i] = '\0';
			return (substr);
		}
	}
	return (NULL);
}
