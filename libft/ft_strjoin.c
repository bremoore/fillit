/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaluko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 13:44:45 by aaluko            #+#    #+#             */
/*   Updated: 2019/02/24 17:08:29 by aaluko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates (with malloc(3)) and returns a “fresh” string ending
** with ’\0’, result of the concatenation of s1 and s2. If
** the allocation fails the function returns NULL.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		tlen;
	char		*fresh;

	if (s1 && s2)
	{
		tlen = 0;
		tlen = tlen + ft_strlen(s1) + ft_strlen(s2);
		fresh = (char *)malloc(sizeof(*s1) * tlen + 1);
		if (fresh)
		{
			ft_strcpy(fresh, s1);
			ft_strcat(fresh, s2);
			return (fresh);
		}
	}
	return (NULL);
}
