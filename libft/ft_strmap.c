/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaluko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 12:08:12 by aaluko            #+#    #+#             */
/*   Updated: 2019/02/24 17:26:28 by aaluko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Description: Applies the function f to each character of the string given
** as argument to create a “fresh” new string (with malloc(3)) resulting from
** the successive applications of f.
** Param. #1: The string to map.
** Param. #2: The function to apply to each character of s.
** Return value: The “fresh” string created from the successive applications
** of f.
*/

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*fresh;
	char	*fresh1;

	if (s)
	{
		fresh = (char *)malloc((sizeof(*s) * (ft_strlen(s)) + 1));
		if (fresh)
		{
			fresh1 = fresh;
			while (*s)
			{
				*fresh = (*f)(*s);
				s++;
				fresh++;
			}
			*fresh = '\0';
			return (fresh1);
		}
	}
	return (NULL);
}
