/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foulare <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 14:54:30 by foulare           #+#    #+#             */
/*   Updated: 2022/01/03 15:57:26 by foulare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct data
{
	int	n;
	int	pos;
	int	size;
	int	len;
}	t_data;
typedef struct pile
{
	long int	value;
	struct pile	*next;
}	t_stack;

void	destroy_split(int n, char **str);
int		check_repeat(t_stack *a);
int		check_error(char **tab, int n, char **str);
void	stack_clear(t_stack *a);
void	sort_three(t_stack **a);
void	rotate(t_stack *stack, char *str);
t_stack	*last_value(t_stack *stack);
void	rrotate(t_stack *stack, char *str);
void	push(t_stack **stack, t_stack **stackpush, char *str);
void	swap(t_stack *stack, char *str);
void	sort_five(t_stack **a, t_stack **b);
void	sort(t_stack **a, t_stack **b);
int		check_sort(t_stack *a);
int		get_minindex(t_stack *a, int *tail);
int		stacklen(t_stack *a);
int		get_maxindex(t_stack *a, int *i);
t_stack	*last_value(t_stack *stack);
void	swap_b(t_stack *stack);
void	push_b(t_stack **stack, t_stack **stackpush);
void	rotate_b(t_stack *stack);
void	rrotate_b(t_stack *stack);
char	*get_next_line(int fd);
int		*remp_tab(t_stack *a, int *size);
int		check_tab(int *tab, t_stack **a, int len, int *i);
#endif
