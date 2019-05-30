/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaluko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 12:59:56 by aaluko            #+#    #+#             */
/*   Updated: 2019/02/24 17:06:04 by aaluko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Lexicographical comparison between s1 and s2. If the 2
** strings are identical the function returns 1, or 0 otherwise
*/

int		ft_strequ(char const *s1, char const *s2)
{
	int		num;

	if (s1 && s2)
	{
		num = ft_strcmp(s1, s2);
		if (num == 0)
			return (1);
		return (0);
	}
	else if (!s1 && !s2)
		return (1);
	else
		return (0);
}
