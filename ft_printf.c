/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 20:25:31 by vzhadan           #+#    #+#             */
/*   Updated: 2023/02/23 21:15:30 by mnurlybe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// void	ft_switch_for_flags(char c, FLAGS *flags)
// {
// 	if (c == '.')
// 		flags->is_dot = 1;
// 	else if (c == ' ')
// 		flags->is_space = 1;
// 	else if (c == '#')
// 		flags->is_hash = 1;
// 	else if (c == '+')
// 		flags->is_plus = 1;
// 	else if (c == '-')
// 		flags->is_dash = 1;
// }

// void	ft_switch_for_sp(char c, SPECIFIERS *sp)
// {
// 	if (c == 'c')
// 		sp->c = 1;
// 	else if (c == 'd')
// 		sp->d = 1;
// 	else if (c == 'i')
// 		sp->i = 1;
// 	else if (c == 's')
// 		sp->s = 1;
// 	else if (c == 'p')
// 		sp->p = 1;
// 	else if (c == '%')
// 		sp->percent = 1;
// 	else if (c == 'x')
// 		sp->x = 1;
// 	else if (c == 'X')
// 		sp->X = 1;
// 	else if (c == 'u')
// 		sp->u = 1;
// }

// void	ft_add_to_number(char c, int *prev_number)
// {
// 	(*prev_number) = (*prev_number) * 10 + (c - '0');
// }

// void	ft_fill_pr_width(char c, FLAGS *flags)
// {
// 	ft_add_to_number(c, &(flags->pr_width));
// }

// void	ft_fill_width(char c, FLAGS *flags)
// {
// 	ft_add_to_number(c, &(flags->width));
// }

char	*ft_fill_flags(char *str, FLAGS *flags)
{
	const char	str_flags[] = "csdiuxpX%";
	
	while (!ft_strchr(str_flags, *str))
	{
		ft_switch_for_flags(*str, flags);
		if (*str == '0' && !(flags->width) && !(flags->pr_width))
			flags->is_zero = 1;
		if (ft_isdigit(*str) && !(flags->is_dot))
			ft_fill_width(*str, flags);
		else if (ft_isdigit(*str) && flags->is_dot)
			ft_fill_pr_width(*str, flags);
		str++;
	}
	return (str);
}

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *str)
{
	int	len;

	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}

int	ft_format(va_list args, SPECIFIERS sp, FLAGS flags)
{
	char				*str;
	int					num;
	unsigned long long	p_null; 
	
	if (sp.percent)
		return (write(1, "%", 1));
	if (sp.c)
	{
		str = malloc(2);
		*str = va_arg(args, int);
		str[1] = '\0';
	}
	else if (sp.d || sp.i)
	{
		num = va_arg(args, int);
		if (num < 0)
		{
			num *= -1;
			flags.is_negative  = 1;
		}
		str = ft_number_to_str(num, 'd', 10);
	}
	else if (sp.u)
		str = ft_number_to_str(va_arg(args, u_int), 'd', 10);
	else if (sp.s)
	{
		str = va_arg(args, char *);
		if (!str)
			return(ft_c_s_p("(null)", &flags, &sp));
		num = ft_c_s_p(str, &flags, &sp);
		return (num);
	}
	else if (sp.p)
	{
		p_null = va_arg(args, unsigned long long);
		if (!p_null)
			return(ft_c_s_p("(nil)", &flags, &sp));
		flags.is_hash = 1;
		str = ft_number_to_str_l(p_null, 'x', 16);
	}
	else if (sp.x || sp.X)
	{
		num = va_arg(args, unsigned int);
		if (sp.x)
			str = ft_number_to_str(num, 'x', 16);
		else if (sp.X)
			str = ft_number_to_str(num, 'X', 16);
	}
	if(sp.c)
	{
		if (!str)
		{
			free(str);
			return (ft_c_s_p("(null)", &flags, &sp));	
		}
		num = ft_c_s_p(str, &flags, &sp);
		free(str);
		return (num);
	}
	if (sp.d || sp.i || sp.u)
	{
		if (*str == '0' && flags.is_dot && !flags.pr_width)
		{
			free(str);
			return (ft_d_i_u("", &flags, &sp));
		}
		num = ft_d_i_u(str, &flags, &sp);
		free(str);
		return (num);
	}
	if (sp.x || sp.X || sp.p)
	{
		if (*str == '0' && flags.is_dot && !flags.pr_width)
		{
			free(str);
			return (ft_hex("", &flags, &sp));
		}
		num = ft_hex(str, &flags, &sp);
		free(str);
		return (num);
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	FLAGS		flags;
	SPECIFIERS	sp;
	va_list		ptr;
	size_t		printed;
	char		*tmp_ptr;
	
	printed = 0;
	tmp_ptr = (char *)str;
	va_start(ptr, str);
	ft_init(&flags, &sp);
	while (*(tmp_ptr))
	{
		if (*tmp_ptr == '%') 
		{
			ft_init(&flags, &sp);
			tmp_ptr = ft_fill_flags(tmp_ptr + 1, &flags);
			ft_switch_for_sp(*tmp_ptr, &sp);
			printed += ft_format(ptr, sp, flags);
		}
		else
			printed += write(1, &(*tmp_ptr), 1);
		tmp_ptr ++;
	}
	return (printed);
}
