/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaluko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 20:33:09 by aaluko            #+#    #+#             */
/*   Updated: 2019/02/23 22:19:56 by aaluko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
** The atoi() function converts the initial portion of the string pointed
** to by str to int representation.
*/

int		ft_atoi(const char *str)
{
	int		num;
	int		sign;

	num = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		sign = 44 - *str;
		++str;
	}
	while (!((*str >= 9 && *str <= 13) || *str == 32) && *str)
	{
		if (!ft_isdigit(*str))
			return (num * sign);
		num = (num * 10) + (*str - '0');
		str++;
	}
	return (num * sign);
}
