/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:59:48 by nakoriko          #+#    #+#             */
/*   Updated: 2024/08/25 17:59:04 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_middle(int i, t_list **a, t_list **b)
{
	int	j;

	if (i <= (ft_lstsize(*a) / 2))
	{
		j = i + 1;
		while (--j != 0)
			ft_rotate(a, 'a');
		j = i + 1;
		ft_push(b, a, 'a');
		while (--j != 0)
			ft_reverse_rotate(a, 'a');
	}
	else
	{
		j = ((ft_lstsize(*a)) - i) + 1;
		while (--j != 0)
			ft_reverse_rotate(a, 'a');
		ft_push(b, a, 'a');
		j = ((ft_lstsize(*a)) - i) + 1;
		while (--j != 0)
			ft_rotate(a, 'a');
	}
}

void	ft_sort_5(t_list **a, t_list **b, t_list *na)
{
	int	i;

	ft_sort(a, b);
	while (ft_lstsize(*b) != 0)
	{
		i = 0;
		na = (*a);
		if (*(int *)(*b)->c < (*(int *)na->c))
			ft_push(b, a, 'a');
		else if (*(int *)(*b)->c > *(int *)(ft_lstlast(*a))->c)
			ft_push_rotate(b, a, 'a');
		else
		{
			while (++i && na->next)
			{
				if (*na->c < *(*b)->c && *(*b)->c < *na->next->c)
				{
					ft_sort_middle(i, a, b);
					break ;
				}
				na = na->next;
			}
		}
	}
}

void	ft_sort_helper_sort_5(t_list **a, t_list **b, t_list *n_a)
{
	if (ft_lstsize(*a) == 5)
		ft_push(a, b, 'b');
	ft_push(a, b, 'b');
	ft_sort_5(a, b, n_a);
}

void	ft_sort_three_num(t_list **a)
{
	int	tmp;
	int	tmpn;
	int	tmpnn;

	ft_sort_helper_ini(&tmp, &tmpn, &tmpnn, a);
	if ((tmp > tmpn && tmpn > tmpnn && tmpnn < tmp)
		|| (tmp > tmpn && tmpn < tmpnn && tmpnn > tmp)
		|| (tmp < tmpn && tmpn > tmpnn && tmpnn > tmp))
	{
		ft_swap(a, 'a');
		ft_sort_helper_ini(&tmp, &tmpn, &tmpnn, a);
	}
	if (tmp < tmpn && tmpn > tmpnn && tmpnn < tmp)
	{
		ft_reverse_rotate(a, 'a');
		ft_sort_helper_ini(&tmp, &tmpn, &tmpnn, a);
	}
	else if (tmp > tmpnn && tmpn < tmpnn)
		ft_rotate(a, 'a');
}

void	ft_sort(t_list **a, t_list **b)
{
	t_list	*n_a;

	n_a = NULL;
	if (ft_lstsize(*a) == 2)
		ft_swap(a, 'a');
	else if (ft_lstsize(*a) == 3)
		ft_sort_three_num(a);
	else if (ft_lstsize(*a) <= 5)
		ft_sort_helper_sort_5(a, b, n_a);
	else
		ft_big_sort(a, b);
}
