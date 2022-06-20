#include<unistd.h>
#include<stdlib.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>
//infile "ls -l" "wc -l" outfile
#include "pipex.h"

int main(int argc, char *argv[], char **envp)
{
  int   f[2];

  if (argc == 5)
  {
      //argv[2],[3] 에러 체크를 넣을까 말까? 일단 안넣구 간당!!
          //인자 1, 4 읽고 제대로 못읽은 경우 에러 체크
          f[0] = open(argv[1], O_RDONLY);
          f[1] = open(argv[4], O_WRONLY | O_CREAT, 0644 | O_TRUNC);
          if((f[0] < 0) || (f[1] < 0))
                return(ft_putstr_fd("file open error", 1)); //임시적 -1, error 리턴
      //파이프엑스 넘기기
          ft_pipex(argc, argv, f, envp);
          if(close(f[0]) < 0 || close(f[1]) < 0)
                return (ft_putstr_fd("file close error", 1));//임시적 -1, error 리턴
  }
  else
    return (ft_putstr_fd("I want argc == 5! check one more time", 1));
  return (0);
}
