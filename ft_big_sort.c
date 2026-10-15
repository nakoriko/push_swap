/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:59:48 by nakoriko          #+#    #+#             */
/*   Updated: 2024/08/25 17:43:19 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "push_swap.h"

void	ft_temp_iter(t_list **temp, int *temp_num, int *next_num, int *temp_len)
{
	*next_num = *(int *)(*temp)->next->c;
	if (*temp_num < *next_num)
	{
		*temp_num = *next_num;
		(*temp_len)++;
	}
	*temp = (*temp)->next;
}

void	ft_lis_search(t_list **a, int *lis_len, t_list **lis_head)
{
	t_list	*head;
	t_list	*temp;
	int		temp_len;
	int		temp_num;
	int		next_num;

	temp_len = 0;
	temp_num = 0;
	next_num = 0;
	head = (*a);
	while (head != NULL)
	{
		temp = head;
		temp_num = *(int *)(temp)->c;
		while (temp->next != NULL)
			ft_temp_iter(&temp, &temp_num, &next_num, &temp_len);
		if (temp_len > *lis_len)
		{
			*lis_len = temp_len;
			*lis_head = head;
		}
		temp_len = 0;
		head = head->next;
	}
}

void	ft_lis_support(int *temp_num, int next_num, int *i, int *array)
{
	array[*i] = next_num;
	*temp_num = next_num;
	(*i)++;
}

int	*ft_lis(int *lis_len, t_list **lis_head)
{
	int		*array;
	int		i;
	int		temp_num;
	int		next_num;
	t_list	*temp;

	i = 0;
	next_num = 0;
	array = malloc(sizeof(int) * ((*lis_len) + 1));
	if (array == NULL)
		return (NULL);
	temp = *lis_head;
	temp_num = *(int *)(temp)->c;
	array[i] = temp_num;
	i++;
	while (temp->next != NULL)
	{
		next_num = *(int *)(temp)->next->c;
		if (temp_num < next_num)
			ft_lis_support(&temp_num, next_num, &i, array);
		temp = temp->next;
	}
	return (array);
}

void	ft_big_sort(t_list **a, t_list **b)
{
	t_list	*lis_head;
	int		lis_len;
	int		*array;
	int		*array_a;
	int		*array_b;

	lis_head = NULL;
	lis_len = 0;
	array = NULL;
	array_a = NULL;
	array_b = NULL;
	ft_lis_search(a, &lis_len, &lis_head);
	array = ft_lis(&lis_len, &lis_head);
	if (array == NULL)
		ft_free_all(a, b);
	ft_stack_divide(a, b, array, lis_len);
	free(array);
	while (*b != NULL)
	{
		ft_calc(a, b, &array_a, &array_b);
		ft_final_sort(a, b, array_a, array_b);
		free(array_a);
		free(array_b);
	}
	ft_final_stack(a);
}
