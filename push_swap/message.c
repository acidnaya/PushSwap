/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfriesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 12:46:34 by jfriesen          #+#    #+#             */
/*   Updated: 2019/01/21 12:46:37 by jfriesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	message(t_stack **a, t_stack **b, int e, char *line)
{
	delete_stack(a);
	delete_stack(b);
	if (line)
		free(line);
	line = NULL;
	if (e == -1)
		write(1, "Error\n", 6);
	else
		e ? write(1, "OK\n", 3) : write(1, "KO\n", 3);
	exit(0);
}
