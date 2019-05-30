/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaluko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 12:37:59 by aaluko            #+#    #+#             */
/*   Updated: 2019/02/21 18:52:27 by aaluko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Applies the function f to each character of the string passed
** as argument by giving its index as first argument to create a
** “fresh” new string (with malloc(3)) resulting from the successive
** applications of f.
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*fresh;
	char			*fresh_p;
	unsigned int	i;

	if (s)
	{
		i = 0;
		fresh = (char *)malloc((sizeof(*s) * (ft_strlen(s)) + 1));
		if (fresh)
		{
			fresh_p = fresh;
			while (s[i])
			{
				*fresh = (*f)(i, s[i]);
				i++;
				fresh++;
			}
			*fresh = '\0';
			return (fresh_p);
		}
	}
	return (NULL);
}
