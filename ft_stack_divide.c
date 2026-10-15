/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_divide.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 17:31:37 by nakoriko          #+#    #+#             */
/*   Updated: 2024/08/24 12:32:28 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "push_swap.h"

int	ft_numsrc(int n, int *array, int len)
{
	int	i;

	i = 0;
	while (i <= len)
	{
		if (array[i] == n)
			return (1);
		i++;
	}
	return (0);
}

void	ft_stack_divide(t_list **a, t_list **b, int *array, int len)
{
	int	i;

	i = 0;
	while (ft_lstsize(*a) != (len + 1))
	{
		if (ft_numsrc(*(int *)(*a)->c, array, len) == 0)
			ft_push(a, b, 'b');
		else
		{
			ft_rotate(a, 'a');
			i++;
		}
	}
}
