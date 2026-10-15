/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mosse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 01:45:14 by nakoriko          #+#    #+#             */
/*   Updated: 2024/08/20 17:57:39 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "push_swap.h"

void	ft_swap(t_list **a, char c)
{
	t_list	*temp;
	t_list	*end;

	if (ft_lstsize(*a) <= 1)
		return ;
	temp = *a;
	end = (*a)->next->next;
	*a = (*a)->next;
	temp->next = end;
	(*a)->next = temp;
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
}

void	ft_swap_ab(t_list **a, t_list **b)
{
	if ((ft_lstsize(*a) <= 1) || (ft_lstsize(*b) <= 1))
		return ;
	ft_swap(a, 'c');
	ft_swap(b, 'c');
	write(1, "ss\n", 3);
}

void	ft_push(t_list **sender, t_list **receiver, char c)
{
	t_list	*temp;

	temp = *sender;
	if (ft_lstsize(*sender) < 1)
		return ;
	*sender = (*sender)->next;
	temp->next = NULL;
	ft_lstadd_front(receiver, temp);
	if (c == 'b')
		write(1, "pb\n", 3);
	else
		write(1, "pa\n", 3);
}

void	ft_rotate(t_list **a, char c)
{
	t_list	*head;

	head = NULL;
	if (ft_lstsize(*a) < 2)
		return ;
	head = *a;
	*a = (*a)->next;
	head->next = NULL;
	ft_lstadd_back(a, head);
	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
}

void	ft_rotate_ab(t_list **a, t_list **b)
{
	if ((ft_lstsize(*a) < 2) || (ft_lstsize(*b) < 2))
		return ;
	ft_rotate(a, 'r');
	ft_rotate(b, 'r');
	write(1, "rr\n", 3);
}
