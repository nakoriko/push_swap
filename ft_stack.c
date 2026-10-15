/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:35:47 by nakoriko          #+#    #+#             */
/*   Updated: 2024/08/26 09:50:12 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>

void	ft_stack(char **mtx, t_list **a)
{
	int		i;
	int		*n;
	t_list	*temp;

	i = 0;
	while (mtx[i])
	{
		n = (int *)malloc(sizeof(int));
		if (!n)
			return ;
		*n = ft_atoi(mtx[i]);
		temp = ft_lstnew(n);
		ft_lstadd_back(a, temp);
		i++;
	}
}
