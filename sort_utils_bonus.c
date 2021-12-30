/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foulare <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 19:07:43 by foulare           #+#    #+#             */
/*   Updated: 2021/12/30 18:25:49 by foulare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

t_stack	*last_value(t_stack *stack)
{
	t_stack *l;
	t_stack *temp;

	temp = stack;
	while (temp)
	{
		l = temp;
		temp = temp->next;
	}
	return (l);
}

void	swap_b(t_stack *stack)
{
	int	temp;

	temp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp;
}

void	push_b(t_stack **stack, t_stack **stackpush)
{
	t_stack *temp;
	t_stack	*p;

	temp = (t_stack *)malloc(sizeof(t_stack *));
	temp->value = (*stackpush)->value;
	temp->next = *stack;
	*stack = temp;
	p = *stackpush;
	*stackpush = (*stackpush)->next;
	free(p);
}

void	rotate_b(t_stack *stack)
{
	int	temp;
	while (stack->next)
	{
		temp = stack->value;
		stack->value = stack->next->value;
		stack->next->value = temp;
		stack = stack->next;
	}
}

void	rrotate_b(t_stack *stack)
{
	int temp;

	t_stack *last;
	while (stack->next)
	{
		last = last_value(stack);
		temp = stack->value;
		stack->value = last->value;
		last->value = temp;
		stack = stack->next;
	}
}
