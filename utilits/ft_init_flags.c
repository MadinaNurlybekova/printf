/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:04:07 by mnurlybe          #+#    #+#             */
/*   Updated: 2023/03/09 20:04:09 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_init_flags(t_flags *flags)
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
