/////////
#include <stdio.h>
////////
#include<unistd.h>
#include<stdlib.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>
static int	ft_put(char **t, char const *str, int k, char charset);
static int	ft_count(char const *str, char charset);
static void	ft_free(char ***t, int j);
static void	ft_hate_line(char **t, int j, int size);
char	**ft_split(char const *s, char c);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s1);
char **find_path(char **envp);