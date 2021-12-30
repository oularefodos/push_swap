/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foulare <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 12:29:53 by foulare           #+#    #+#             */
/*   Updated: 2021/12/30 21:41:54 by foulare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

void	sort_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while(j < size)
		{
			if (tab[i] > tab[j])
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int	check_tab(int *tab, t_stack *a, int len, int *i)
{
	t_stack *temp;

	temp = a;
	*i = 0;
	if (a == NULL)
		return (-1);
	while(temp)
	{	
		if (temp->value <= tab[len - 1])
			return (*i);
		(*i)++;
		temp = temp->next;
	}
	return (-1);
}

int	*remp_tab(t_stack *a, int *size)
{
	t_stack *temp;
	int	*tab;

	*size = 0;
	temp = a;
	*size = stacklen(temp);
	tab = (int *)malloc(sizeof(int) * *size);
	if (!tab)
		return (0);
	*size = 0;
	while (a)
	{
		tab[*size] = a->value;
		a = a->next;
		(*size)++;
	}
	sort_tab(tab, *size);
	return (tab);
}

void	instruct_a(t_stack **a, t_stack **b, int i, int size)
{
	int		n;

	n = size - i;
	if (i == 1)
		swap(*a, "sa");
	else if (i < size / 2)
		while (i-- > 0)
			rotate (*a, "ra");
	else if (i >= size / 2 && i != 0)
		while (n-- > 0)
			rrotate (*a, "rra");
	push(b, a, "pb");
}

void	sort(t_stack **a, t_stack **b)
{
	t_data	data;
	int	*tab;
	int	i;
	int	q;

	tab = remp_tab(*a, &data.len);
	if (data.len < 15)
		q = 5;
	else
		q = 10;
	data.size = data.len;
	data.pos = data.len / q;
	while(*a)
	{
		while (check_tab(tab, *a, data.pos, &i) >= 0)
		{
			instruct_a(a, b, i, data.size);
			data.size = stacklen(*a);
		}
		data.pos += data.len / q;
		if (data.size == 3)
			break;
		if (data.pos > data.len)
			data.pos = data.len;
	}
	if (*a)
		sort_three(a);
	while (*b)
	{
		i = get_maxindex(*b, &data.size);
		data.n = data.size - i;
		if (i == 1)
			swap(*b, "sb");
		else if (i < data.size/2)
			while (i-- > 0)
				rotate (*b, "rb");
		else if (i >= data.size / 2 && i != 0)
			while (data.n-- > 0)
				rrotate (*b, "rrb");	
		push(a, b, "pa");
	}
	free(tab);
}
