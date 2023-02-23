/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 21:08:53 by mnurlybe          #+#    #+#             */
/*   Updated: 2023/02/23 21:19:43 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_switch_for_flags(char c, FLAGS *flags)
{
	if (c == '.')
		flags->is_dot = 1;
	else if (c == ' ')
		flags->is_space = 1;
	else if (c == '#')
		flags->is_hash = 1;
	else if (c == '+')
		flags->is_plus = 1;
	else if (c == '-')
		flags->is_dash = 1;
}

void	ft_switch_for_sp(char c, SPECIFIERS *sp)
{
	if (c == 'c')
		sp->c = 1;
	else if (c == 'd')
		sp->d = 1;
	else if (c == 'i')
		sp->i = 1;
	else if (c == 's')
		sp->s = 1;
	else if (c == 'p')
		sp->p = 1;
	else if (c == '%')
		sp->percent = 1;
	else if (c == 'x')
		sp->x = 1;
	else if (c == 'X')
		sp->X = 1;
	else if (c == 'u')
		sp->u = 1;
}

void	ft_add_to_number(char c, int *prev_number)
{
	(*prev_number) = (*prev_number) * 10 + (c - '0');
}

void	ft_fill_pr_width(char c, FLAGS *flags)
{
	ft_add_to_number(c, &(flags->pr_width));
}

void	ft_fill_width(char c, FLAGS *flags)
{
	ft_add_to_number(c, &(flags->width));
}