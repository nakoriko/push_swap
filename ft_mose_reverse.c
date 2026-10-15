/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mose_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 17:45:40 by nakoriko          #+#    #+#             */
/*   Updated: 2024/08/23 19:15:11 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "push_swap.h"

void	ft_reverse_rotate(t_list **a, char c)
{
	t_list	*temp;
	t_list	*end;
	int		i;

	if (ft_lstsize(*a) < 2)
		return ;
	i = ft_lstsize(*a);
	temp = ft_lstlast(*a);
	ft_lstadd_front(a, temp);
	end = *a;
	while (--i != 0)
		end = end->next;
	end->next = NULL;
	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
}

void	ft_reverse_rotate_rrr(t_list **a, t_list **b)
{
	if ((ft_lstsize(*a) < 2) || (ft_lstsize(*b) < 2))
		return ;
	ft_reverse_rotate(a, 'c');
	ft_reverse_rotate(b, 'c');
	write(1, "rrr\n", 4);
}
