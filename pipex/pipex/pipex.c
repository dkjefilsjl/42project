#include "pipex.h"

void init_pc(t_pc *pc)
{
        pc->cmd = 0;
        pc->path = 0;
        pc->options = 0;
}

void ft_pipex(int argc, char **argv, int *f, char **envp) // 파일 2개, argv, envp
{
        int i;
        t_pc pc[argc];

        i = 1;
        while(++i < argc - 1)
        {
                init_pc(&(pc[i - 2]));
                if(!get_pc(&(pc[i - 2]), argv[i], envp))
                {
                        free_struct(&(pc[i - 2]));
                        return ;
                }
                //path + c->cmd를 access 체크 후 성공은 1리턴 아닌경우 에러 리턴
        }
        go_pipex(f, envp, pc);
        i = 0;
        while(i < argc - 1)
                free_struct(&(pc[i++]));
}

void free_struct(t_pc *pc)
{
        if(pc->cmd)
                free(pc->cmd);
        if(pc->path)
                free_arr(pc->path);
        if(pc->options)
                free_arr(pc->options);
}

int get_pc(t_pc *pc, char *argv, char **envp)
{
        int      i;

        i = 0;
        pc->path = find_path(envp);
        if(!pc->path)
                return (0);
        pc->options = ft_split(argv, ' ');
        if(!pc->options)
                return (0);
        pc->cmd = ft_strdup(pc->options[0]);
        if (!pc->cmd)
        {
                free_arr(pc->options);
                return (0);
        }
        if(!pc->options)
                return (0);
        i = -1;
        return (1);
}

void    free_arr(char **st)
{
        int i;
        i = 0;

        while(st[i])
        {
                free(st[i]);
                i++;
        }
        if (st)
                free(st);
}

char **find_path(char **envp)
{
        int             i;
        char    *_path;
        char    **re;

        i = 2;
        while (envp[i] != NULL)
        {
                if (ft_strncmp("PATH=", envp[i], 5) == 0)
                {
                        _path = ft_strdup(envp[i] + 5);
                        if (!_path)
                                return (NULL);
                        re = ft_split(_path, ':');
                        if (!re)
                        {
                                free(_path);
                                return (NULL);
                        }
                        free (_path);
                        return (re);
                }
                i++;
        }
        return (0);
}
