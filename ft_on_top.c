/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_on_top.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 17:41:57 by nakoriko          #+#    #+#             */
/*   Updated: 2024/08/23 19:14:59 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "push_swap.h"

void	ft_rote(t_list **a, t_list **b, int score_a, int score_b)
{
	while (score_a > 0 && score_b > 0)
	{
		ft_rotate_ab(a, b);
		score_a--;
		score_b--;
	}
	while (score_a > 0)
	{
		ft_rotate(a, 'a');
		score_a--;
	}
	while (score_b > 0)
	{
		ft_rotate(b, 'b');
		score_b--;
	}
}

void	ft_rote_reverse(t_list **a, t_list **b, int score_a, int score_b)
{
	int	len_a;
	int	len_b;

	len_a = ft_lstsize(*a);
	len_b = ft_lstsize(*b);
	while (score_a < len_a && score_b < len_b)
	{
		ft_reverse_rotate_rrr(a, b);
		score_a++;
		score_b++;
	}
	while (score_a < len_a)
	{
		ft_reverse_rotate(a, 'a');
		score_a++;
	}
	while (score_b < len_b)
	{
		ft_reverse_rotate(b, 'b');
		score_b++;
	}
}

void	ft_on_top_rotate(t_list **a, t_list **b, int index_a, int index_b)
{
	int	len_a;
	int	len_b;

	len_a = ft_lstsize(*a);
	len_b = ft_lstsize(*b);
	if (index_b <= (len_b / 2) && index_b != 0)
	{
		while (index_b > 0)
		{
			ft_rotate(b, 'b');
			index_b--;
		}
	}
	if (index_a <= (len_a / 2) && index_a != 0)
	{
		while (index_a > 0)
		{
			ft_rotate(a, 'a');
			index_a--;
		}
	}
}

void	ft_on_top_reverse_rotate(t_list **a, t_list **b, int index_a, int ix_b)
{
	int	len_a;
	int	len_b;

	len_a = ft_lstsize(*a);
	len_b = ft_lstsize(*b);
	if ((ix_b > (len_b / 2) && ix_b != 0))
	{
		while (ix_b < len_b)
		{
			ft_reverse_rotate(b, 'b');
			ix_b++;
		}
	}
	if (index_a > (len_a / 2) && index_a != 0)
	{
		while (index_a < len_a)
		{
			ft_reverse_rotate(a, 'a');
			index_a++;
		}
	}
}

void	ft_on_top(t_list **a, t_list **b, int index_a, int index_b)
{
	int	len_a;
	int	len_b;
	int	score_a;
	int	score_b;

	score_a = index_a;
	score_b = index_b;
	len_b = ft_lstsize(*b);
	len_a = ft_lstsize(*a);
	if ((index_b <= (len_b / 2) && index_b != 0)
		&& (index_a <= (len_a / 2) && index_a != 0))
	{
		ft_rote(a, b, score_a, score_b);
		return ;
	}
	else if ((index_b > (len_b / 2) && index_b != 0)
		&& (index_a > (len_a / 2) && index_a != 0))
	{
		ft_rote_reverse(a, b, score_a, score_b);
		return ;
	}
	ft_on_top_rotate(a, b, index_a, index_b);
	ft_on_top_reverse_rotate(a, b, index_a, index_b);
}
