/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfriesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:48:29 by jfriesen          #+#    #+#             */
/*   Updated: 2019/01/09 14:48:30 by jfriesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	**swap(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*second;
	t_stack	*first;

	first = *stack;
	second = (first->next) ? first->next : first->next;
	if (second)
	{
		tmp = second->next;
		second->next = first;
		first->next = tmp;
		*stack = second;
	}
	return (stack);
}

static t_stack	**push(t_stack **where, t_stack **what)
{
	t_stack	*first;
	t_stack	*second;

	first = what ? *what : NULL;
	second = where ? *where : NULL;
	if (first)
	{
		*what = first->next;
		first->next = second;
		*where = first;
	}
	return (where);
}

static t_stack	**rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	first = stack ? *stack : NULL;
	last = last_elem(first);
	if (first && last && first != last)
	{
		*stack = first->next;
		last->next = first;
		first->next = NULL;
	}
	return (stack);
}

static t_stack	**reverse_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	first = stack ? *stack : NULL;
	last = last_elem(first);
	if (first && last && first != last)
	{
		*stack = last;
		last->next = first;
		while (first->next != last)
			first = first->next;
		first->next = NULL;
	}
	return (stack);
}

char			operations(t_stack **a, t_stack **b, char *s)
{
	if (!s)
		return (0);
	if (strcmp(s, "sa\n") == 0 && swap(a))
		return (1);
	else if (strcmp(s, "sb\n") == 0 && swap(b))
		return (1);
	else if (strcmp(s, "ss\n") == 0 && swap(a) && swap(b))
		return (1);
	else if (strcmp(s, "pa\n") == 0 && push(a, b))
		return (1);
	else if (strcmp(s, "pb\n") == 0 && push(b, a))
		return (1);
	else if (strcmp(s, "ra\n") == 0 && rotate(a))
		return (1);
	else if (strcmp(s, "rb\n") == 0 && rotate(b))
		return (1);
	else if (strcmp(s, "rr\n") == 0 && rotate(a) && rotate(b))
		return (1);
	else if (strcmp(s, "rra\n") == 0 && reverse_rotate(a))
		return (1);
	else if (strcmp(s, "rrb\n") == 0 && reverse_rotate(b))
		return (1);
	else if (strcmp(s, "rrr\n") == 0 && reverse_rotate(a) && reverse_rotate(b))
		return (1);
	return (0);
}
