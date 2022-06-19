#include "pipex.h"
typedef struct s_path_cmd{
	char 	*cmd;
	char 	**path;
	char	**options;
} t_pc;

void init_pc(int argc, t_pc **pc)
{
	while(argc--)
	{
		pc[argc - 1]->cmd = 0;
		pc[argc - 1]->path = 0;
	}
}

void ft_pipex(int argc, char **argv, int *fd, char **envp) // 파일 2개, argv, envp
{
	int i;
	t_pc pc[argc];
	
	i = 1;
	init_pc(argc, &pc);
	while(++i < argc)
	{
		if(!get_pc(&(pc[i - 2]), argv[i], envp) || !access_cmd(&(pc[i - 2])))
		{
			free_struct(&pc);
			return (0);
		}
		//path + c->cmd를 access 체크 후 성공은 1리턴 아닌경우 에러 리턴
	}
	//cmd 실행 함수()
	go_pipex(); //****여기 할차례~!!!
	i = 0;
	while(i < argc)
		free_struct(&(pc[i++]));
}

int access_cmd(t_pc *pc)
{
	int		i;
	char	*cmd;

	i = 0;
	while (pc->path[i])
	{
		cmd = ft_join(pc->path[i], pc->cmd);
		if (!cmd)
			return (0);
		if (access(cmd, X_OK) != -1)
		{
			free(cmd);
			return (1);
		}
		free(cmd);
		i++;
	}
	ft_putstr_fd("You write wrong cmd!", 1);
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
	char	**op;
	int	 i;

	i = 1;
	pc->path = find_path(envp);
	if(!pc->path)
		return (0);
	op = ft_split(argv, ' ');
	if(!op)
		return (0);
	pc->cmd = ft_strdup(op[0]);
	if (!pc->cmd)
	{
		free(op);
		return (0);
	}
	while(op[i])
	{
		pc->options = ft_strdup(op[i++]);
		if(!pc->options)
		{
			free_arr(pc->options);
			free(op);
			return (0);
		}
	}
	free(op);
	return (1);
}

void	free_arr(char **st)
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
	int		i;
	char	*_path;
	char	**re;

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
/*
int main(int argc, char **envp)
{
	int i = 0;
	char **re = find_path(envp);
	if(argc > 0)
	;
	while(re[i])
		printf("%s ", re[i++]);
	return (0);
}*/
/*
//get cmd 함수
{
	//c->path = get_path(); 오류 체크
	//cmd 받아온거 (인자 2,3) 스플릿해서 배열에 저장 후 오류 체크
	//c->cmd에 해당 배열[0] 저장과 오류 체크
	//c->args에 해당 배열 돌아가면서 전체 저장,마지막 0과 오류 체크
	//여기서 만든 배열 프리
}

//get path 함수
{
	//환경변수를 돌면서 PATH=부분을 체크하고 있으면 리턴
}

//cmd 실행 함수
{
	//pid_t pid1, pi2
	//pipe()
	//pid1 fork()
	//pid < 0 에러
	//child_()
	//pid2 fork()
	//에러처리
	//child_()
	//close pipefd[0],[1]
	//waitpid()
}

/* chile 다루기
static void	child()
{
	//execv();
}
*/