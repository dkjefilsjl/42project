#include "printf.h"
#include <unistd.h>
size_t  ft_strlen(const char *s)
{
        int     i;

        i = 0;
        while (s[i])
        {
                i++;
        }
        return (i);
}

int ft_printf_str(char *c)
{
        int n;

        if (!c)
        {
                write(1, "(null)", 6);
                return (6);
        }
        else
        {
                n = ft_strlen(c);
                write(1, c, n);
                return (n);
        }
}