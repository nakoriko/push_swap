/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_final_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 01:39:26 by nakoriko          #+#    #+#             */
/*   Updated: 2024/08/25 14:57:55 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "push_swap.h"

int	ft_min(t_list **b, int *array_a, int *array_b)
{
	int	num;
	int	min;
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = ft_lstsize(*b);
	num = 0;
	min = array_a[i] + array_b[i];
	while (i < len - 1)
	{
		num = array_a[i] + array_b[i];
		if (num <= min)
		{
			min = num;
			j = i;
		}
		i++;
	}
	return (j);
}

void	ft_final_sort(t_list **a, t_list **b, int *array_a, int *array_b)
{
	int		index_b;
	int		index_a;
	int		num_b;
	int		sup_len;
	t_list	*head_b;

	index_b = ft_min(b, array_a, array_b);
	head_b = (*b);
	sup_len = 0;
	while (sup_len < index_b)
	{
		sup_len++;
		head_b = head_b->next;
	}
	num_b = *(int *)head_b->c;
	index_a = ft_index_a(a, num_b);
	ft_on_top(a, b, index_a, index_b);
	ft_push(b, a, 'a');
}
