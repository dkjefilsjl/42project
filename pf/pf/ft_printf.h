#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

int ft_printf_char(char c);
int ft_printf(const char *str, ...);
int ft_printf_str(char *c);
int ft_printf_nbr(int n, int fd);
int ft_printf_unnbr(unsigned int n, int fd);
int ft_printf_pointer(unsigned long long ull);
int ft_printf_hex(unsigned int ui, char c);

#endif