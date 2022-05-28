/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfriesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 15:58:04 by jfriesen          #+#    #+#             */
/*   Updated: 2019/01/09 15:58:04 by jfriesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*create_elem(int n)
{
	t_stack *ptr;

	ptr = NULL;
	ptr = (t_stack *)malloc(sizeof(t_stack));
	if (ptr)
	{
		ptr->num = n;
		ptr->next = NULL;
	}
	return (ptr);
}

t_stack		*add_elem(t_stack **stack, int n)
{
	t_stack *ptr;

	ptr = NULL;
	if (stack)
	{
		if (!(ptr = create_elem(n)))
			return (NULL);
		ptr->next = *stack;
		*stack = ptr;
	}
	return (ptr);
}

t_stack		*last_elem(t_stack *stack)
{
	t_stack	*last;

	last = stack;
	if (last)
		while (last->next)
			last = last->next;
	return (last);
}

t_stack		*add_elem_back(t_stack **stack, int n)
{
	t_stack	*ptr;
	t_stack	*last;

	if (stack)
	{
		last = last_elem(*stack);
		if (!(ptr = create_elem(n)))
			return (NULL);
		if (last)
			last->next = ptr;
		else
			*stack = ptr;
	}
	return (*stack);
}
