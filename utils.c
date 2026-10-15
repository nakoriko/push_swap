/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 01:53:53 by nakoriko          #+#    #+#             */
/*   Updated: 2024/08/25 18:00:27 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_del(void *content)
{
	if (content)
		free(content);
}

void	ft_push_rotate(t_list **b, t_list **a, char c)
{
	ft_push(b, a, c);
	ft_rotate(a, c);
}

void	printer(t_list **a)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = *a;
	while (temp != NULL)
	{
		i = *(int *)(temp)->c;
		ft_printf("Stack in ft_stack: %d\n", i);
		(temp) = (temp)->next;
	}
}

void	ft_free_all(t_list **a, t_list **b)
{
	ft_lstclear(a, ft_del);
	ft_lstclear(b, ft_del);
	exit (1);
}

void	ft_print_array(int *array, int lis_len)
{
	int	i;

	i = 0;
	ft_printf("Array: ");
	while (i <= lis_len)
	{
		ft_printf("%d, ", array[i]);
		i++;
	}
	ft_printf("\n");
}
