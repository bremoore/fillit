/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaluko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 12:59:56 by aaluko            #+#    #+#             */
/*   Updated: 2019/02/24 17:28:13 by aaluko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Lexicographical comparison between s1 and s2 up to n characters
** or until a ’\0’ is reached. If the 2 strings are identical,
** the function returns 1, or 0 otherwise.
*/

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int		num;

	if (s1 && s2)
	{
		num = ft_strncmp(s1, s2, n);
		if (num == 0)
			return (1);
		return (0);
	}
	if (!s1 && !s2)
		return (1);
	else
		return (0);
}
