#include "pipex.h"
int     ft_putstr_fd(char *s, int fd)
{
        if (!s || (fd < 0))
                return (0);
        write(fd, s, ft_strlen(s));

        return (0);
}

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

int     ft_strncmp(const char *s1, const char *s2, size_t n)
{
        int     i;

        i = 0;
        while (n > 0 && s1[i] && s2[i])
        {
                if (s1[i] != s2[i])
                {
                        break ;
                }
                i++;
                n--;
        }
        if (n == 0)
        {
                return (0);
        }
        else
        {
                return ((unsigned char)s1[i] - (unsigned char)s2[i]);
        }
}

char    *ft_strdup(const char *s1)
{
        int             i;
        char    *ch;

        i = 0;
        while (s1[i])
        {
                i++;
        }
        ch = (char *)malloc(sizeof(char) * i + 1);
        if (!ch)
                return (0);
        i = 0;
        while (s1[i])
        {
                ch[i] = s1[i];
                i++;
        }
        ch[i] = '\0';
        return (ch);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
        char    *ch;

        if (!s1 && !s2)
                return (0);
        else if (!s1)
                return (ft_strdup(s2));
        else if (!s2)
                return (ft_strdup(s1));
        ch = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
        if (!ch)
                return (0);
        ft_memcpy(ch, s1, ft_strlen(s1));
        ft_memcpy(&ch[ft_strlen(s1)], s2, ft_strlen(s2));
        ch[ft_strlen(s1) + ft_strlen(s2)] = '\0';
        return (ch);
}

void    *ft_memcpy(void *dst, const void *src, size_t n)
{
        unsigned char   *ch;
        unsigned char   *sch;
        int             i;

        if (!dst && !src)
                return (0);
        i = 0;
        ch = (unsigned char *)dst;
        sch = (unsigned char *)src;
        while (n)
        {
                ch[i] = sch[i];
                i++;
                n--;
        }
        return (dst);
}