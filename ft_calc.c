/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 01:33:50 by nakoriko          #+#    #+#             */
/*   Updated: 2024/08/25 14:50:21 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "push_swap.h"

int	*ft_array_b(t_list **b, int len_b)
{
	int		*array_b;
	int		i;
	int		index_b;
	t_list	*head_b;

	i = 0;
	index_b = 0;
	array_b = NULL;
	array_b = malloc(sizeof(int) * ft_lstsize(*b));
	if (array_b == NULL)
		return (0);
	head_b = (*b);
	while (head_b != NULL)
	{
		if (index_b <= (len_b) / 2)
			array_b[i] = index_b + 1;
		else
			array_b[i] = (len_b - index_b) + 1;
		index_b++;
		i++;
		head_b = head_b->next;
	}
	return (array_b);
}

void	ft_index_a_support(t_list **a, t_list **head_a, t_limits *lim, int *i)
{
	(*head_a) = (*a);
	lim->max = *(int *)(*head_a)->c;
	lim->min = *(int *)(*head_a)->c;
	lim->max_index = 0;
	lim->min_index = 0;
	(*i) = 0;
	while ((*head_a) != NULL)
	{
		if (*(int *)(*head_a)->c > lim->max)
		{
			lim->max = *(int *)(*head_a)->c;
			lim->max_index = *i;
		}
		if (*(int *)(*head_a)->c < lim->min)
		{
			lim->min = *(int *)(*head_a)->c;
			lim->min_index = *i;
		}
		(*i)++;
		(*head_a) = (*head_a)->next;
	}
}

int	ft_index_a(t_list **a, int n)
{
	int			i;
	t_list		*head_a;
	t_limits	lim;
	int			num_a;

	i = 0;
	num_a = 0;
	head_a = (*a);
	if (n > *(int *)ft_lstlast(*a)->c && n < *(int *)(*a)->c)
		return (0);
	while (head_a->next != NULL)
	{
		num_a = *(int *)head_a->c;
		i++;
		if (n > num_a && n < *(int *)head_a->next->c)
			return (i);
		head_a = head_a->next;
	}
	ft_index_a_support(a, &head_a, &lim, &i);
	if (n > lim.max)
		return (lim.max_index + 1);
	else
		return (lim.min_index);
	return (i);
}

void	ft_array_a(t_list **a, t_list **b, int len_a, int **array_a)
{
	int		i;
	int		index_a;
	int		num_b;
	t_list	*head_b;

	i = 0;
	head_b = (*b);
	while (head_b != NULL)
	{
		num_b = *head_b->c;
		index_a = ft_index_a(a, num_b);
		if (num_b > *ft_lstlast(*a)->c && num_b < *(*a)->c)
			(*array_a)[i] = 0;
		else if ((num_b > *(*a)->c) && (num_b < *(*a)->next->c))
			(*array_a)[i] = index_a;
		else if (index_a <= (len_a / 2))
			(*array_a)[i] = index_a;
		else if ((len_a - index_a) == 0)
			(*array_a)[i] = 1;
		else
			(*array_a)[i] = (len_a - index_a);
		i++;
		head_b = head_b->next;
	}
}

void	ft_calc(t_list **a, t_list **b, int **array_a, int **array_b)
{
	int		len_a;
	int		len_b;

	len_a = ft_lstsize(*a);
	len_b = ft_lstsize(*b);
	*array_a = malloc(sizeof(int) * len_b);
	if (array_a == NULL)
		ft_free_all(a, b);
	ft_array_a(a, b, len_a, array_a);
	*array_b = ft_array_b(b, len_b);
	if (array_b == NULL)
		ft_free_all(a, b);
}
