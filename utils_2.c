/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 18:00:45 by nakoriko          #+#    #+#             */
/*   Updated: 2024/08/26 13:04:39 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_helper_ini(int *tmp, int *tmpn, int *tmpnn, t_list **a)
{
	*tmp = *(int *)(*a)->c;
	*tmpn = *(int *)(*a)->next->c;
	*tmpnn = *(int *)(*a)->next->next->c;
}

long int	ft_atol(const char *nptr)
{
	long int	i;
	long int	sign;
	long int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (res * 10) + (nptr[i] - 48);
		i++;
	}
	res = res * sign;
	return (res);
}

void	ft_free_2args_exit(char **mtx)
{
	ft_free_array(mtx);
	exit(1);
}
