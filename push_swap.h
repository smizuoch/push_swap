/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:41:14 by smizuoch          #+#    #+#             */
/*   Updated: 2023/08/27 09:08:13 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<stdio.h>
# include<unistd.h>
# include"libft/libft.h"

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node			*head;
	int				size;
	int				max;
}	t_stack;

void	chack_same_num(t_stack *stack);
void	algo(t_stack *a, t_stack *b);

void	push(t_stack *stack, int data);
int		pop(t_stack *stack);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *a, t_stack *b);

void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *a, t_stack *b);

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

void	sort6(t_stack *a, t_stack *b);

void	sort_push_swap(t_stack *a, t_stack *b);

void	quick_sort(int *arr, int low, int high);

void	error_exit(void);
void	error_check(const char *str);
long	ps_atoi(const char *str);
char	**ps_split(char const *s, char c);

void	stack_free(t_stack *stack);

#endif
