/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaluko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 16:56:49 by aaluko            #+#    #+#             */
/*   Updated: 2019/02/22 16:17:54 by aaluko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Takes as a parameter a link’s pointer address and frees the memory of the
** link’s content using the function del given as a parameter, then frees the
** link’s memory using free(3). The memory of next must not be freed unde
** any circumstance. Finally, the pointer to the link that was just freed
** must be set to NULL (quite similar to the function ft_memdel in the
** mandatory part).
*/

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;
	t_list	**p_temp;

	temp = *alst;
	while (temp)
	{
		p_temp = &temp;
		temp = temp->next;
		ft_lstdelone(p_temp, del);
	}
	ft_lstdelone(alst, del);
}
