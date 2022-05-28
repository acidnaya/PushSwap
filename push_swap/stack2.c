/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfriesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:30:05 by jfriesen          #+#    #+#             */
/*   Updated: 2019/01/21 19:30:06 by jfriesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			stack_size(t_stack *a)
{
	int		i;
	t_stack	*s;

	s = a;
	i = 0;
	while (s)
	{
		i++;
		s = s->next;
	}
	return (i);
}

int			is_sorted_stack(t_stack **a)
{
	t_stack	*ptr;
	t_stack	*prev;

	if (!a || !*a)
		return (0);
	ptr = *a;
	while (ptr->next)
	{
		prev = ptr;
		ptr = ptr->next;
		if (ptr->num < prev->num)
			return (0);
	}
	return (1);
}

void		delete_stack(t_stack **stack)
{
	t_stack *ptr;

	if (stack)
	{
		ptr = *stack;
		while (*stack)
		{
			*stack = (*stack)->next;
			free(ptr);
			ptr = *stack;
		}
	}
}

void		print_stack(t_stack *stack)
{
	t_stack	*s;

	s = stack;
	while (s)
	{
		ft_putnbr(s->num);
		write(1, " ", 1);
		s = s->next;
	}
	write(1, "\n", 1);
}
