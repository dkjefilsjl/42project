#include "ft_printf.h"

int ft_format(char c, va_list ap)
{
        int re;

        re = 0;
        if (c == 'c')
                re = ft_printf_char(va_arg(ap, int));
        else if (c == 's')
                re = ft_printf_str(va_arg(ap, char*));
        else if (c == 'p')
                re = ft_printf_pointer(va_arg(ap, unsigned long long));
        else if (c == 'd' || c == 'i')
                re = ft_printf_nbr(va_arg(ap, int), 1);
        else if (c == 'u')
                re = ft_printf_unnbr(va_arg(ap, unsigned int), 1);
        else if (c == 'x' || c == 'X')
                re = ft_printf_hex(va_arg(ap, unsigned int), c);
        else if (c == '%')
        {
                write(1, "%", 1);
                re++;
        }
        return (re);
}

int ft_printf_char(char c)
{
        write(1, &c, 1);
        return (1);
}
char    ft_isformat(char c)
{
        if (c == 'c' || c == 's' || c == 'p' || c== 'd' \
                       || c == 'i'|| c == 'u' || c == 'x' || c == 'X')
                return (1);
        else
                return (0);
}
int ft_printf(const char *str, ...)
{
        va_list ap;
        int re;
        int i;

        re = 0;
        i = 0;
        va_start(ap, str);
        while(str[i])
        {
                if (str[i] == '%' && ft_isformat(str[i + 1]))
                {
                        re += ft_format(str[i + 1], ap);
                        i += 2;
                }
                else
                {
                        re += ft_printf_char(str[i]);
                        i++;
                }
        }
        va_end(ap);
        return (re);
}: