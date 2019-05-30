/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaluko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:32:40 by aaluko            #+#    #+#             */
/*   Updated: 2019/02/20 23:15:44 by aaluko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION: The function computes the length of the string s.
** The strnlen() function attempts to compute the length of s, but never
** scans beyond the first maxlen bytes of s.
** RETURN VALUES: The function returns the number of characters that
** precede the terminating NUL character. The function returns
** either the same result as  or maxlen, whichever is smaller.
*/

size_t	ft_strlen(const char *s)
{
	size_t		i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}
