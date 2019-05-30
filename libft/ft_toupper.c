/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaluko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 22:13:01 by aaluko            #+#    #+#             */
/*   Updated: 2019/02/20 16:09:04 by aaluko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION: The toupper() function converts a lower-case letter to the
** corresponding upper-case letter. The argument must be representable as
** an unsigned char or the value of EOF.
** RETURN VALUES: If the argument is a lower-case letter, the toupper()
** function returns the corresponding uppercase letter if there is one;
** otherwise, the argument is returned unchanged.
*/

int		ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}
