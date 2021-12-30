/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foulare <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:54:49 by foulare           #+#    #+#             */
/*   Updated: 2021/12/29 14:35:44 by foulare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"

void	sort_three(t_stack **a)
{
	int i;
	int n;

	if ((*a)->next == NULL)
		return ;
	i = get_maxindex(*a, &n);
	if ((*a)->value > (*a)->next->value && i != 0)
			swap(*a, "sa");
	if (check_sort(*a) == 0)
	{
		if (i == 0)
			rotate(*a, "ra");
		if (i == 1)
			rrotate(*a, "rra");
		if ((*a)->value > (*a)->next->value)
			swap(*a, "sa");
	}
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	i;
	int tail;
	int	n;
	
	i = get_minindex(*a, &tail);
	if ((*a)->next == NULL)
		return ;
	while (tail > 3)
	{
		n = tail - i;	
		if(i == 1)
			swap(*a, "sa");
		else if (i < tail / 2)
			while (i-- > 0)
				rotate(*a, "ra");
		else if (i >= tail / 2 && i != 0)
			while(n-- > 0)
				rrotate(*a, "rra");	
		push(b, a, "pb");
		i = get_minindex(*a, &tail);
	}
	sort_three(a);
	while (*b)
		push(a, b, "pa");
}
