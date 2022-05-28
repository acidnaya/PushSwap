/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfriesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 14:55:38 by jfriesen          #+#    #+#             */
/*   Updated: 2019/01/21 14:55:41 by jfriesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_all(t_stack **a, t_stack **b, int i)
{
	write(1, "STACK A: ", 9);
	print_stack(*a);
	write(1, "STACK B: ", 9);
	print_stack(*b);
	write(1, "NUMBER OF COMMANDS: ", 20);
	ft_putnbr(i);
	write(1, "\n\n", 2);
}
