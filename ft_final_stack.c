/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_final_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 01:44:18 by nakoriko          #+#    #+#             */
/*   Updated: 2024/08/24 12:34:12 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_index_head(t_list **a)
{
	int			i;
	int			num_a;
	t_list		*head_a;
	t_limits	lim;

	i = 0;
	num_a = 0;
	head_a = (*a);
	lim.min = *(int *)head_a->c;
	lim.min_index = 0;
	while (head_a != NULL)
	{
		num_a = *(int *)head_a->c;
		if (num_a < lim.min)
		{
			lim.min = num_a;
			lim.min_index = i;
		}
		head_a = head_a->next;
		i++;
	}
	return (lim.min_index);
}

void	ft_final_stack(t_list **a)
{
	int	i;
	int	len;

	len = ft_lstsize(*a);
	i = ft_index_head(a);
	if (i <= (len / 2))
	{
		while (i > 0)
		{
			ft_rotate(a, 'a');
			i--;
		}
	}
	else if (i > (len / 2))
	{
		while (i < len)
		{
			ft_reverse_rotate(a, 'a');
			i++;
		}
	}
}
