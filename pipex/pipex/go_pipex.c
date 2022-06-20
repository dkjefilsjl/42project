#include "pipex.h"


int access_cmd(t_pc *pc, char **envp)
{
        int             i;
        char    *cmd;

        i = 0;
        while (pc->path[i])
        {
                cmd = ft_strjoin(pc->path[i++], "/");
                cmd = ft_strjoin(cmd, pc->cmd);
                if (!cmd)
                        return (0);
                if (access(cmd, F_OK) == 0)
                {
                        if (execve(cmd, pc->options, envp) == -1)
                        {
                                free(cmd);
                                return (ft_putstr_fd("You write wrong cmd!", 1));
                        }
                        free(cmd);
                        break;
                }
                free(cmd);
        }
        return (0);
}


int go_pipex(int *f, char **envp, t_pc *pc)
{
        int     fd[2];
        pid_t   pid1;

        if(pipe(fd) == -1)
                exit(1);
        pid1 = fork();
        if (pid1 == -1)
                return (0);
        if (pid1 == 0)
                child_p(f, envp, fd, &pc[0]);
        waitpid(pid1, NULL, 0);
        parent_p(f, envp, fd, &pc[1]);
        return (0);
}

void child_p(int *f, char **envp, int *fd, t_pc *pc) //write
{
        dup2(fd[1], STDOUT_FILENO);
        dup2(f[0], STDIN_FILENO);
        close(fd[0]); // read
        access_cmd(pc, envp);
}

void    parent_p(int *f, char **envp, int *fd, t_pc *pc) //read
{
        dup2(fd[0], STDIN_FILENO);
        dup2(f[1], STDOUT_FILENO);
        close(fd[1]); //write
        access_cmd(pc, envp);
}