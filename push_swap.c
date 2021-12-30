/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foulare <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 14:54:07 by foulare           #+#    #+#             */
/*   Updated: 2021/12/30 21:31:41 by foulare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

t_stack	*ft_alloc(t_stack *a)
{
	t_stack *temp;

	temp = (t_stack *)malloc(sizeof(t_stack));
	if (!temp)
	{
		free(temp);
		stack_clear(a);
		exit (0);
	}
	return (temp);
}

int	stack_init(int ac, char **str, t_stack **a)
{
	int		j;
	t_stack	*temp;
	char	**tab;

	ac = ac - 1;
	while (ac > 0)
	{
		tab = ft_split(str[ac], ' ');
		j = taille_tab(str[ac], ' ') - 1;
		if (!check_error(tab, j, str))
			return (0);
		while (j >= 0)
		{
			temp = ft_alloc(*a);
			temp->value = ft_atoi(tab[j]);
			temp->next = *a;
			*a = temp;
			j--;
		}
		destroy_split(taille_tab(str[ac], ' ') - 1, tab);
		ac--;
	}
	return (1);
}

int	main(int ac, char **str)
{
	int	i;
	t_stack	*a;
	t_stack	*b;
	
	a = NULL;
	b = NULL;
	i = 1;
	if (ac == 1)
		return (0);
	if(!stack_init(ac, str, &a))
		return (0);
	if(!check_repeat(a))
		return (0);
	if (stacklen(a) <= 3)
		sort_three(&a);
	else if (stacklen(a) <= 5)
		sort_five(&a, &b);
	else
		sort(&a, &b);
}
