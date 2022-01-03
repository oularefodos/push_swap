/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foulare <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:43:59 by foulare           #+#    #+#             */
/*   Updated: 2022/01/03 17:44:03 by foulare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

t_stack	*last_value(t_stack *stack)
{
	t_stack	*l;
	t_stack	*temp;

	temp = stack;
	while (temp)
	{
		l = temp;
		temp = temp->next;
	}
	return (l);
}

void	swap(t_stack *stack, char *str)
{
	int	temp;

	temp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp;
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}

void	push(t_stack **stack, t_stack **stackpush, char *str)
{
	t_stack	*temp;
	t_stack	*p;

	temp = (t_stack *)malloc(sizeof(t_stack));
	if (!temp)
		return ;
	temp->value = (*stackpush)->value;
	temp->next = *stack;
	*stack = temp;
	p = *stackpush;
	*stackpush = (*stackpush)->next;
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	free(p);
}

void	rotate(t_stack *stack, char *str)
{
	int	temp;

	while (stack->next)
	{
		temp = stack->value;
		stack->value = stack->next->value;
		stack->next->value = temp;
		stack = stack->next;
	}
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}

void	rrotate(t_stack *stack, char *str)
{
	int		temp;
	t_stack	*last;

	while (stack->next)
	{
		last = last_value(stack);
		temp = stack->value;
		stack->value = last->value;
		last->value = temp;
		stack = stack->next;
	}
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}
