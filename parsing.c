/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 14:03:39 by nakoriko          #+#    #+#             */
/*   Updated: 2024/08/26 13:02:14 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_array(long int n, long int *array, int i, int j)
{
	int	k;

	k = 0;
	if ((n < (-2147483648)) || n > (2147483647))
		ft_free_exit(array);
	while (i < j)
	{
		if (array[i] == n)
			ft_free_exit(array);
		i++;
	}
	i = 0;
	while (i < (j - 1))
	{
		if (array[i] < array[i + 1])
			k++;
		i++;
	}
	if (k == i)
	{
		ft_free(array);
		exit(1);
	}
	return (0);
}

int	ft_array(char **mtx, int j)
{
	long int	*array;
	int			i;
	int			k;

	k = j;
	array = NULL;
	i = 0;
	while (mtx[j])
		j++;
	if (j < 3)
		ft_free_2args_exit(mtx);
	array = malloc(sizeof(long int) * (j + 1));
	if (array == NULL)
		return (1);
	j = k;
	while (mtx[j])
		array[i++] = ft_atol(mtx[j++]);
	if (!ft_strnstr(mtx[0], "push_swap", ft_strlen(mtx[0])))
		ft_free_array(mtx);
	i = -1;
	while (++i < (j - k))
		check_array(array[i], array, i + 1, (j - k));
	free(array);
	array = NULL;
	return (0);
}

int	str_check(char *str)
{
	int		i;
	char	c;

	i = 0;
	c = 0;
	while (str[i])
	{
		c = str[i];
		if ((c >= '0' && c <= '9') || (c == '-' || c == '+'))
		{
			if ((c == '-' || c == '+') && ((i != 0) || (ft_strlen(str) == 1)))
				return (1);
			i++;
		}
		else
			return (1);
	}
	return (0);
}

int	ft_check_string(char *str)
{
	int		arr_check;
	char	**str_split;
	int		i;

	arr_check = 0;
	i = 0;
	if (!str[i])
		return (1);
	str_split = ft_split(str, 32);
	while (str_split[i])
	{
		if (str_check(str_split[i]) == 1)
		{
			ft_free_array(str_split);
			return (1);
		}
		i++;
	}
	arr_check = ft_array(str_split, 0);
	return (arr_check);
}

int	ft_check_args(int ac, char **av)
{
	int	i;
	int	j;
	int	arg_check;

	j = 1;
	i = 0;
	arg_check = 0;
	while (j < ac)
	{
		if (!av[j][i])
			return (1);
		if (str_check(av[j]) == 0)
			j++;
		else
			return (1);
	}
	arg_check = ft_array(av, 1);
	return (arg_check);
}
