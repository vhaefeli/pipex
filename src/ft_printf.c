/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:50:59 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/04/21 10:38:18 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdarg.h>

static int	ft_prints(char *src)
{
	int	n;

	n = 0;
	if (src == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (src[n])
	{
		write(1, &src[n], 1);
		n++;
	}
	return (n);
}

static void	ft_printnb_base(unsigned int nb, int nbase, int *n)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb / nbase)
		ft_printnb_base(nb / nbase, nbase, n);
	write(1, &base[nb % nbase], 1);
	(*n)++;
}

static void	ft_dealtype(va_list ap, char type, int *n)
{	
	int	nb;

	if (type == 's')
		*n += ft_prints(va_arg(ap, char *));
	else if (type == 'd' || type == 'i')
	{
		nb = va_arg(ap, int);
		if (nb < 0)
		{
			nb *= -1;
			write(1, "-", 1);
			(*n)++;
		}
		ft_printnb_base(nb, 10, n);
	}
	else if (type == 'x')
		ft_printnb_base(va_arg(ap, unsigned int), 16, n);
	else
		write(1, "ERROR type printf\n", 18);
}

int	ft_printf(const char *src, ...)
{
	va_list	ap;
	int		i;
	int		n;

	n = 0;
	i = 0;
	va_start(ap, src);
	while (src[i])
	{
		if (src[i] != '%')
		{
			write(1, &src[i], 1);
			i++;
			n++;
		}
		else
		{
			ft_dealtype(ap, src[i + 1], &n);
			i += 2;
		}
	}
	va_end(ap);
	return (n);
}
