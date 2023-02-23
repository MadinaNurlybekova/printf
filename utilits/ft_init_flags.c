/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:12:45 by vzhadan           #+#    #+#             */
/*   Updated: 2023/02/23 21:05:02 by mnurlybe         ###   ########.fr       */
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
}
