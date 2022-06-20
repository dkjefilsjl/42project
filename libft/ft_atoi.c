#include "libft.h"
static long longft_over(long long flag, long long tmp, long long num);

intft_atoi(const char *str)
{
size_ti;
long longnum;
intflag;
long longtmp;

i = 0;
num = 0;
flag = 1;
while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
i++;
if (str[i] == '-')
flag = -1;
if (str[i] == '-' || str[i] == '+')
i++;
while (str[i] >= '0' && str[i] <= '9')
{
tmp = num;
num = num * 10;
num += str[i++] - '0';
num = ft_over(flag, tmp, num);
if ((tmp > 0) && (num <= 0))
break ;
}
return (num * flag);
}

static long longft_over(long long flag, long long tmp, long long num)
{
if ((flag == -1) && (tmp > num))
return (0);
else if ((flag != -1) && (tmp > num))
return (-1);
else
return (num);
}
seoyepar@c6r8s2 seo % 
