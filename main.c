/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:43:18 by smizuoch          #+#    #+#             */
/*   Updated: 2023/08/29 11:27:28 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	argc_many_init(int argc, char **argv, t_stack *stack_a)
{
	int	i;

	i = argc - 1;
	while (i > 0)
	{
		push(stack_a, ps_atoi(argv[i]));
		i --;
	}
}

void	argc_2_init(char **argv, t_stack *stack_a)
{
	int		i;
	char	**split;

	split = ps_split(argv[1], ' ');
	if (!split)
		error_exit();
	i = 0;
	while (split[i] != NULL)
		i ++;
	while (i > 0)
	{
		i --;
		push(stack_a, ps_atoi(split[i]));
		free (split[i]);
	}
	free (split);
}

void	stack_init(t_stack *stack)
{
	stack->head = NULL;
	stack->size = 0;
	stack->max = INT_MAX;
}

void	stack_free(t_stack *stack)
{
	t_node	*tmp;

	while (stack->head)
	{
		tmp = stack->head;
		stack->head = stack->head->next;
		free(tmp);
	}
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	stack_init(&stack_a);
	stack_init(&stack_b);
	if (argc == 1)
		exit (0);
	if (argc > 2)
		argc_many_init(argc, argv, &stack_a);
	if (argc == 2)
		argc_2_init(argv, &stack_a);
	chack_same_num(&stack_a);
	algo(&stack_a, &stack_b);
	stack_free(&stack_a);
	exit (0);
}
