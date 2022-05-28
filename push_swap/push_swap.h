/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfriesen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:48:23 by jfriesen          #+#    #+#             */
/*   Updated: 2019/01/09 14:48:25 by jfriesen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# define MIN(a,b) ((a)<(b)) ? (a) : (b)

typedef struct		s_stack
{
	int				num;
	int				ord;
	struct s_stack	*next;
}					t_stack;

int					atoi_stat(char *str, int *n);

t_stack				*create_elem(int n);

t_stack				*add_elem(t_stack **stack, int n);

t_stack				*add_elem_back(t_stack **stack, int n);

t_stack				*last_elem(t_stack *stack);

void				delete_stack(t_stack **stack);

int					is_sorted_stack(t_stack **a);

void				print_stack(t_stack *stack);

char				operations(t_stack **a, t_stack **b, char *s);

t_stack				*merge_sort(t_stack *a, int n);

void				quick_sort(t_stack **a, int n, char **res);

void				divide_to_b(t_stack **a, t_stack **b, int *n, char **s);

void				optimization(char **res);

void				join_del(char **s1, char *s2);

void				message(t_stack **a, t_stack **b, int e, char *line);

void				duplicate_check(t_stack **a, int ac);

void				print_all(t_stack **a, t_stack **b, int i);

void				string_parsing(t_stack **a, char *s);

void				args_parsing(t_stack **a, int ac, char **av);

int					stack_size(t_stack *a);

void				do_op(t_stack **a, t_stack **b, char **s, char *op);

int					minimum(int a, int b);

int					direction(t_stack *b, int *n);

void				range_max(int *n, int p[3]);

void				range_min(int *n, int q[3]);

#endif
