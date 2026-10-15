/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:58:14 by naal-jen          #+#    #+#             */
/*   Updated: 2024/08/26 13:02:04 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stddef.h> // size_t NULL
# include <stdio.h>
# include <stdlib.h> // malloc free sizeof
# include <unistd.h>

typedef struct limitss
{
	int	min;
	int	max;
	int	min_index;
	int	max_index;
}		t_limits;

void		ft_del(void *content);
void		printer(t_list **a);
void		ft_free_all(t_list **a, t_list **b);
void		ft_free_array(char **array);
void		ft_free(long int *array);
void		ft_free_exit(long int *array);
void		ft_print_error(void);
void		ft_print_array(int *array, int lis_len);
void		ft_stack(char **mtx, t_list **a);
void		ft_swap(t_list **a, char c);
void		ft_swap_ab(t_list **a, t_list **b);
void		ft_push(t_list **sender, t_list **receiver, char c);
void		ft_rotate(t_list **a, char c);
void		ft_rotate_ab(t_list **a, t_list **b);
void		ft_reverse_rotate(t_list **a, char c);
void		ft_reverse_rotate_rrr(t_list **a, t_list **b);
void		ft_push_rotate(t_list **b, t_list **a, char c);
void		ft_sort(t_list **a, t_list **b);
void		ft_big_sort(t_list **a, t_list **b);
void		ft_final_sort(t_list **a, t_list **b, int *array_a, int *array_b);
void		ft_calc(t_list **a, t_list **b, int **array_a, int **array_b);
void		ft_on_top(t_list **a, t_list **b, int index_a, int index_b);
void		ft_final_stack(t_list **a);
void		ft_stack_divide(t_list **a, t_list **b, int *array, int len);
int			main(int ac, char **av);
int			ft_index_a(t_list **a, int n);
int			ft_check_string(char *str);
int			ft_check_args(int ac, char **av);
long int	ft_atol(const char *nptr);
void		ft_sort_helper_ini(int *tmp, int *tmpn, int *tmpnn, t_list **a);
void		ft_free_2args_exit(char **mtx);

#endif
