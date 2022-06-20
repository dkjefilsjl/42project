/////////
#include <stdio.h>
////////
#include<unistd.h>
#include<stdlib.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_path_cmd{
        char    *cmd;
        char    **path;
        char    *options[256];
} t_pc;
static int      ft_put(char **t, char const *str, int k, char charset);
static int      ft_count(char const *str, char charset);
static void     ft_free(char ***t, int j);
static void     ft_hate_line(char **t, int j, int size);
char    **ft_split(char const *s, char c);
int     ft_putstr_fd(char *s, int fd);
size_t  ft_strlen(const char *s);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
char    *ft_strdup(const char *s1);
char **find_path(char **envp);
void init_pc(int argc, t_pc *pc);
void ft_pipex(int argc, char **argv, int *f, char **envp);
int access_cmd(t_pc *pc);
void free_struct(t_pc *pc);
int get_pc(t_pc *pc, char *argv, char **envp);
void    free_arr(char **st);
char **find_path(char **envp);
char    *ft_strjoin(char const *s1, char const *s2);
void    *ft_memcpy(void *dst, const void *src, size_t n);
void child_process(int *f, char **argv, char **envp, int *fd);
int go_pipex(int *f, char **argv, char **envp);
void    parent_process(int *f, char **argv, char **envp, int *fd);
