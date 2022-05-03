#include "ft_printf.h"

int ft_printf_pointer_count(unsigned long long n);
int ft_printf_pointer_hex(unsigned long long ui, char c);

int ft_printf_pointer(unsigned long long ull)
{
        int count;

        if (ull == 0)
        {
                write(1, "(nil)", 5);
                return (5);
        }
        count = 2;
        write(1, "0x", 2);
        count += ft_printf_pointer_hex(ull, 'x');
        return (count);
}

int     ft_printf_pointer_hex(unsigned long long ui, char c)
{
        char t[13];
        unsigned long long n;
        int count;
        int re;

        n = ui;
        count = ft_printf_pointer_count(n);
        //if (count == 0)
          //      return (5);
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

int ft_printf_pointer_count(unsigned long long n)
{
        int count;

        count = 0;
        //if (n == 0)
        //{
          //      write(1, "(nil)", 5);
        //}
        while (n > 0)
        {
                count++;
                n = n / 16;
        }
        return (count);
}