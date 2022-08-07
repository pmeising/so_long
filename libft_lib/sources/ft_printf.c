/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:55:10 by pmeising          #+#    #+#             */
/*   Updated: 2022/08/07 09:30:26 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_helper3(const char *str, ...)
{
	int		count;
	char	*substr;
	char	*s1;
	va_list	args;

	va_start(args, str);
	s1 = ft_strchr(str, '%');
	count = 0;
	if (s1[1] == 'x')
		count += ft_hex(va_arg(args, unsigned int), 'x');
	else if (s1[1] == 'X')
		count += ft_hex(va_arg(args, unsigned int), 'X');
	else if (s1[1] == 'p')
		count += ft_hex_func_p(va_arg(args, unsigned long));
	else if (s1[1] == 'u')
	{
		substr = ft_itoa_u((unsigned int)va_arg(args, unsigned int));
		count = count + ft_putstr(substr);
		free (substr);
	}
	va_end(args);
	return (count);
}

static int	ft_helper2(const char *str, ...)
{
	int		count;
	char	*substr;
	char	*s1;
	va_list	args;

	va_start(args, str);
	s1 = ft_strchr(str, '%');
	count = 0;
	if (s1[1] == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		count++;
	}
	else if (s1[1] == 's')
		count = count + ft_putstr(va_arg(args, char *));
	else if (s1[1] == 'i' || s1[1] == 'd')
	{
		substr = ft_itoa(va_arg(args, int));
		count += ft_putstr(substr);
		free (substr);
	}
	va_end(args);
	return (count);
}

static int	ft_helper1(const char *str, char *s1)
{
	int		count;
	char	*substr;

	count = 0;
	substr = ft_substr(str, 0, (s1 - str));
	count = count + ft_putstr(substr);
	free (substr);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	char	*s1;
	int		count;

	if (!str)
		return (0);
	s1 = (char *)str;
	count = 0;
	va_start(args, str);
	while (str && s1)
	{
		s1 = ft_strchr(str, '%');
		if (s1 == NULL)
			return (count += ft_putstr((char *)str));
		else
			count += ft_helper1(str, s1);
		if (s1[1] == 'c' || s1[1] == 's' || s1[1] == 'd' || s1[1] == 'i')
			count += ft_helper2(s1, va_arg(args, void *));
		else if (s1[1] == 'p' || s1[1] == 'u' || s1[1] == 'x' || s1[1] == 'X')
			count += ft_helper3(s1, va_arg(args, void *));
		else if (s1[1] == '%')
			count += ft_putperc();
		str = s1 + 2;
	}
	return (count);
}
