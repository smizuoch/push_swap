/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:27:10 by smizuoch          #+#    #+#             */
/*   Updated: 2023/08/27 09:12:47 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_free(t_stack *a, int *arr)
{
	stack_free(a);
	free(arr);
}

int	*already_sorted(t_stack *a)
{
	int		*arr;
	int		i;
	t_node	*tmp;

	arr = (int *)malloc(sizeof(int) * a->size);
	if (!arr)
		error_exit();
	i = 0;
	tmp = a->head;
	while (i < a->size)
	{
		arr[i ++] = tmp->data;
		tmp = tmp->next;
	}
	i = 0;
	quick_sort(arr, 0, a->size - 1);
	tmp = a->head;
	while (i < a->size)
	{
		if (arr[i ++] != tmp->data)
			return (arr);
		tmp = tmp->next;
	}
	a_free(a, arr);
	exit(0);
}

void	algo(t_stack *a, t_stack *b)
{
	int	*arr;

	if (a->size <= 1)
		return ;
	arr = already_sorted(a);
	free(arr);
	if (a->size <= 6 && a->size > 1)
		sort6(a, b);
	else if (a->size > 6)
		sort_push_swap(a, b);
}
