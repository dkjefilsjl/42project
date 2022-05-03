#include "ft_printf.h"

static void     ft_putnbr(unsigned int nb, int fd, int *count);

int     ft_printf_unnbr(unsigned int n, int fd)
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

static void     ft_putnbr(unsigned int nb, int fd, int *count)
{
        char    c;

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