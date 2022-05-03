#include "ft_printf.h"

static void     ft_putnbr(int nb, int fd, int *count);
static int      ft_minus(int nb, int fd);

int     ft_printf_nbr(int n, int fd)
{

        int *count;
        int re;

        re = 0;
        count = &re;
        if (fd < 0)
                return (0);
        ft_putnbr(n, fd, count);
        return (re);
}

static void     ft_putnbr(int nb, int fd, int *count)
{
        char    c;

        if (nb == -2147483648)
                (*count) += 2;
        else if(nb < 0)
                (*count) += 1;
        nb = ft_minus(nb, fd);
        if (nb < 10)
        {
                (*count)++;
                c = nb + 48;
                write(fd, &c, 1);
        }
        else
        {
                ft_putnbr(nb / 10, fd, count);
                ft_putnbr(nb % 10, fd, count);
        }
}

static int      ft_minus(int nb, int fd)
{
        if (nb == -2147483648)
        {
                write(fd, "-2", 2);
                nb = 147483648;
        }
        else if (nb < 0)
        {
                write(fd, "-", 1);
                nb = -nb;
        }
        return (nb);
}