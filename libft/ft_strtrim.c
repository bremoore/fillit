/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaluko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 14:10:42 by aaluko            #+#    #+#             */
/*   Updated: 2019/02/24 15:06:46 by aaluko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates (with malloc(3)) and returns a copy of the string
** given as argument without whitespaces at the beginning or at
** the end of the string. Will be considered as whitespaces the
** following characters ’ ’, ’\n’ and ’\t’. If s has no whitespaces
** at the beginning or at the end, the function returns a
** copy of s. If the allocation fails the function returns NULL.
** move s to the occurance of the first word and copy into temp
** count whitespace at the end and subtract from len.
*/

static int	iswhitespace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	char	*fresh;
	char	*temp;
	size_t	len;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (iswhitespace(*s))
		s++;
	len = ft_strlen(s);
	temp = (char *)malloc(sizeof(*s) * len + 1);
	if (!temp)
		return (NULL);
	ft_strcpy(temp, s);
	temp[len] = '\0';
	while (iswhitespace(temp[--len]))
		;
	fresh = (char *)malloc(sizeof(*s) * len + 2);
	if (!fresh)
		return (NULL);
	ft_strncpy(fresh, temp, len + 1);
	fresh[len + 1] = '\0';
	free(temp);
	return (fresh);
}
