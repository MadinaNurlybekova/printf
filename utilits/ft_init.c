/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:12:45 by vzhadan           #+#    #+#             */
/*   Updated: 2023/02/22 20:03:18 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_init_flags(FLAGS *flags)
{
	flags->is_negative = 0;
	flags->is_dash = 0;
	flags->is_zero = 0;
	flags->is_dot = 0;
	flags->is_hash = 0;
	flags->is_space = 0;
	flags->is_plus = 0;
	flags->width = 0;
	flags->pr_width = 0;
}

void	ft_init_specifiers(SPECIFIERS *sp)
{
	sp->c = 0;
	sp->s = 0;
	sp->d = 0;
	sp->i = 0;
	sp->u = 0;
	sp->x = 0;
	sp->X = 0;
	sp->p = 0;
	sp->percent = 0;
}

void	ft_init(FLAGS *f, SPECIFIERS *sp)
{
	ft_init_flags(f);
	ft_init_specifiers(sp);
}
