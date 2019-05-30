/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaluko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:35:28 by aaluko            #+#    #+#             */
/*   Updated: 2019/02/20 14:36:02 by aaluko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION: strcpy() functions copy the string src to dst (including
** the terminating `\0' character.)
** RETURN VALUES: The strncpy() functions return dst.
*/

char	*ft_strcpy(char *dst, const char *src)
{
	int		i;

	i = -1;
	while (src[++i])
	{
		dst[i] = src[i];
	}
	dst[i] = '\0';
	return (dst);
}
