#include "pipex.h"

int go_pipex(int *f, char **argv, char **envp, t_pc pc[argc])
{
        int     fd[2];
        pid_t   pid1;

        pid1 = fork();
        if (pid1 == -1)
                return (0);
        if (pid1 == 0)
                child_p(f, envp, fd, pc);
        waitpid(pid1, NULL, 0);
        parent_p(f, envp, fd, pc);
}

void child_p(int *f, char **envp, int *fd, t_pc pc[argc])
{
        dup2(fd[1], STDOUT_FILENO);
        dup2(f[0], STDIN_FILENO);
        close(fd[0]);
        access_cmd(pc, envp);
}

void    parent_p(int *f, char **envp, int *fd, t_pc pc[argc])
{
        dup2(fd[0], STDIN_FILENO);
        dup2(f[1], STDOUT_FILENO);
        close(fd[1]);

}
