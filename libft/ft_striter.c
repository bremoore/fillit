/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaluko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 10:33:15 by aaluko            #+#    #+#             */
/*   Updated: 2019/02/24 17:33:26 by aaluko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Description: Applies the function f to each character of the string
** passed as argument. Each character is passed by address to f to be
** modified if necessary.
** Param. #1-The string to iterate.
** Param. #2-The function to apply to each character of s.
*/

void	ft_striter(char *s, void (*f)(char *))
{
	if (s && f)
	{
		while (*s)
		{
			(*f)(&*s);
			s++;
		}
	}
}
