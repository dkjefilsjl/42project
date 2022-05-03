#include "ft_printf.h"

int ft_printf_hex_count(unsigned int n);

int     ft_printf_hex(unsigned int ui, char c)
{
        char t[9];
        unsigned int n;
        int count;
        int re;

        n = ui;
        count = ft_printf_hex_count(n);
        if (count == 0)
                return (1);
        t[count] = '\0';
        while (count > 0)
        {
                if (c == 'x')
                        t[count - 1] = "0123456789abcdef"[ui % 16];
                else
                        t[count - 1] = "0123456789ABCDEF"[ui % 16];
                ui = ui / 16;
                count--;
        }
        re = ft_printf_str(t);
        return (re);
}

int ft_printf_hex_count(unsigned int n)
{
        int count;

        count = 0;
        if (n == 0)
        {
                write(1, "0", 1);
        }
        while (n > 0)
        {
                count++;
                n = n / 16;
        }
        return (count);
}