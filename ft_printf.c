#include <unistd.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i = 0;

	if (str == NULL)
		str = "(null)";
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(unsigned int nbr, int base)
{
	int	i = nbr % base;
	char	*base_set = "0123456789abcdef";
	int	count = 0;

	if (nbr / base > 0)
		count += ft_putnbr(nbr / base, base);
	count += ft_putchar(base_set[i]);
	return (count);
}

int	print_d(int nb)
{
	int	count = 0;

	if (nb < 0)
	{
		count += ft_putchar('-');
		if (nb == -2147483648)
		{
			count += ft_putstr("2147483648");
			return (count);
		}
		nb = -nb;
	}
	count += ft_putnbr((unsigned int)nb, 10);
	return (count);
}

int	main()
{
	ft_putnbr(57, 10);
	ft_putchar('\n');
	ft_putnbr(10, 16);
	ft_putchar('\n');
	print_d(-2147483648);
	ft_putchar('\n');
	print_d(2147483647);
	ft_putchar('\n');
	return (0);
}