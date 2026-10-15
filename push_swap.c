/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 17:38:19 by nakoriko          #+#    #+#             */
/*   Updated: 2024/08/26 13:02:18 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_free_exit(long int *array)
{
	ft_free(array);
	ft_print_error();
}

void	ft_print_error(void)
{
	write(2, "Error\n", 7);
	exit(1);
}

void	ft_free(long int *array)
{
	if (!array)
		return ;
	free(array);
	array = NULL;
}

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	if (array == NULL)
		return ;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	char	**split_args;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	if (ac == 2 && ft_check_string(av[1]) == 0)
	{
		split_args = ft_split(av[1], ' ');
		ft_stack(split_args, &a);
		ft_free_array(split_args);
	}
	else if (ac == 3)
		return (0);
	else if ((ac > 2) && (ft_check_args(ac, av) == 0))
		ft_stack(++av, &a);
	else
		ft_print_error();
	ft_sort(&a, &b);
	ft_lstclear(&a, ft_del);
	return (0);
}
