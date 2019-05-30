/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaluko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 22:16:54 by aaluko            #+#    #+#             */
/*   Updated: 2019/02/20 16:05:01 by aaluko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION: The tolower() function converts an upper-case letter to the
** corresponding lower-case letter. The argument must be representable as an
** unsigned char or the value of EOF.
** RETURN VALUES: If the argument is an upper-case letter, the tolower()
** function returns the corresponding lower-case letter if there is one;
** otherwise, the argument is returned unchanged.
*/

int		ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}
